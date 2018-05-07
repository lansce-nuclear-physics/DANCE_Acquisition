#*********************************#
#*    Christopher J. Prokop      *#
#*    cprokop@lanl.gov           *#
#*    global.h                   *# 
#*    Last Edit: 04/05/18        *#  
#*********************************#

# The MIDASSYS should be defined prior the use of this Makefile
ifndef MIDASSYS
missmidas::
	@echo "...";
	@echo "Missing definition of environment variable 'MIDASSYS' !";
	@echo "...";
endif

# get OS type from shell
OSTYPE = $(shell uname)

OS_DIR = linux
OSFLAGS = -DOS_LINUX -Dextname
CFLAGS = -g -O2 -Wall -I -I$  -pthread -fPIC -DPIC
LIBS = -lm -lz -lutil -lnsl -lrt -L.. -L$(CAENDIGITIZERSYS)/lib -lCAENDigitizer
LIBS += -L$(CAENVMELIBSYS)/lib -lCAENVME 

#Directories
INC_DIR   = $(MIDASSYS)/include
LIB_DIR   = $(MIDASSYS)/$(OS_DIR)/lib
SRC_DIR   = $(MIDASSYS)/src

#Name of frontend
UFE = caen2018_dpp_frontend

# MIDAS library
LIB = $(LIB_DIR)/libmidas.a

# compiler
CC = gcc
CXX = g++
CFLAGS += -g -I$(INC_DIR) -I$(MIDASSYS)/include/ -I$(CAENDIGITIZERSYS)/include/ 
CFLAGS += -DLINUX -I$(CAENVMELIBSYS)/include 

INCLUDES:=  global.h program_digitizer.h functions.h

SRCS:= $(UFE).cpp functions.cpp program_digitizer.cpp

OBJECTS:= $(UFE).o functions.o program_digitizer.o

all: $(UFE)

$(UFE): $(LIB) $(LIB_DIR)/mfe.o $(OBJECTS) $(SRCS) $(INCLUDES)
	$(CXX) -w $(CFLAGS) $(OSFLAGS) -o $(UFE) $(OBJECTS) $(CLFAGS) $(LIB_DIR)/mfe.o $(LIB) $(LIBS)

# make some files with the versions used at compilation for frontend	
	$(shell readlink $(CAENDIGITIZERSYS) > .caendigitizerversion_compile)
	$(shell readlink $(CAENCOMMSYS) > .caencommversion_compile)
	$(shell readlink $(CAENVMELIBSYS) > .caenvmelibversion_compile)
	$(shell readlink $(CAENUPGRADERSYS) > .caenupgraderversion_compile)
	$(shell readlink $(CAEN_A3818SYS) > .caena3818version_compile)

%.o: %.c experim.h
	$(CXX) $(USERFLAGS) $(CFLAGS) $(OSFLAGS) -o $@ -c $<

clean::
	rm -f *.o *~ \#* caen2018_dpp_frontend
