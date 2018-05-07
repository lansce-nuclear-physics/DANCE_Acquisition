#####################################################################
#
#  Name:         Makefile
#  Created by:   Stefan Ritt
#
#  Contents:     UNIX Makefile for MIDAS slow control frontend
#
#  $Id: Makefile 4649 2009-12-08 08:00:38Z ritt $
#
#####################################################################
#
#--------------------------------------------------------------------
# The MIDASSYS should be defined prior the use of this Makefile
ifndef MIDASSYS
missmidas::
	@echo "...";
	@echo "Missing definition of environment variable 'MIDASSYS' !";
	@echo "...";
endif

# get OS type from shell
OSTYPE = $(shell uname)

#--------------------------------------------------------------------
# The following lines contain specific switches for different UNIX
# systems. Find the one which matches your OS and outcomment the 
# lines below.

# This is for Linux ----------------
LIBS = -lbsd -lm -lutil -lpthread -lrt -ldl
OSFLAGS = -DOS_LINUX -DUNIX

#-------------------------------------------------------------------
# The following lines define direcories. Adjust if necessary
#                 

INC_DIR 	= $(MIDASSYS)/include
LIB_DIR 	= $(MIDASSYS)/linux/lib
DRV_DIR		= $(MIDASSYS)/drivers

#-------------------------------------------------------------------
# Drivers needed by the frontend program
#                 
DRIVERS         = hv.o caen1527.o tcpip.o null.o 

LIB = $(LIB_DIR)/libmidas.a 

# compiler
CC = cc
CFLAGS = -g -Wall -I$(INC_DIR) -I$(DRV_DIR) -I$(CAENHVWRAPPERSYS)/include
LDFLAGS = -g
LIBS += -L$(CAENHVWRAPPERSYS)/lib -lcaenhvwrapper -lhscaenet

all: frontend_hv

frontend_hv:  $(LIB) $(LIB_DIR)/mfe.o frontend_hv.o $(DRIVERS)
	$(CC) $(LDFLAGS) -o frontend_hv frontend_hv.o $(LIB_DIR)/mfe.o \
	$(LIBS) $(DRIVERS) $(LIB)

hv.o: ./hv.c
	$(CC) $(CFLAGS) $(OSFLAGS) -c $< -o $@

null.o: $(DRV_DIR)/bus/null.c
	$(CC) $(CFLAGS) $(OSFLAGS) -c $< -o $@

caen1527.o: ./caen1527.c
	$(CC) $(CFLAGS) $(OSFLAGS) -c $< -o $@

tcpip.o: $(DRV_DIR)/bus/tcpip.c
	$(CC) $(CFLAGS) $(OSFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) $(OSFLAGS) -c $<

clean:
	rm -f *.o *~ \#*

