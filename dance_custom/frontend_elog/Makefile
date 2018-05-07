#
#  Name:         Makefile
#  Created by:   John M. O'Donnell
#
#  Contents:     Makefile for MIDAS example frontend and analyzer
#

OSFLAGS  = -DOS_LINUX -Dextname -DLINUX
#   DEFAULT_EVENT_BUFFER_SIZE is needed for midas rev 4057
CFLAGS  += -DDEFAULT_EVENT_BUFFER_SIZE=$(shell perl -e 'print 500*1024*1024')

LIBS += -lm -lz -lutil -lnsl -lpthread -lrt

#-------------------------------------------------------------------
# The following lines define directories. Adjust if necessary
#

DRV_DIR         = $(MIDASSYS)/drivers
INC_DIR 	= $(MIDASSYS)/include
MXML_DIR	= $(MIDASSYS)/../mxml
INC_DIR        += -I$(MXML_DIR) -I$(CAENVMELIBSYS)/include -I$(MDIR) -I$(MDIR)/uac/shared
LIB_DIR 	= $(MIDASSYS)/lib

include $(WNRSYS)/include/jmodRules.mk

# MIDAS library
LIB = $(LIB_DIR)/libmidas.a

# compiler
CC = gcc
CXX = g++
CFLAGS += -g -O2 -I. -I$(INC_DIR) -I$(DRV_DIR) $(OSFLAGS)
CXXFLAGS = $(CFLAGS) 
LDFLAGS += -L$(LIB_DIR) -lmidas
LDFLAGS += -g


PROGS = frontend_elog
all:: $(PROGS)

frontend_elog: $(LIB_DIR)/mfe.o frontend_elog.o 
	$(CXX) $(CXXFLAGS) -o frontend_elog $(LIB_DIR)/mfe.o \
	frontend_elog.o $(LIB) $(LDFLAGS) $(LIBS)

clean::
	rm -f *.o *~ \#*

distclean::
	make clean
	rm -f $(PROGS)
	rm -f *.bak
	rm -f core
	rm -f .depend
