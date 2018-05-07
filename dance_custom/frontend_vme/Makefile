#
#  Name:         Makefile
#  Created by:   John M. O'Donnell
#
#  Contents:     Makefile for MIDAS example frontend and analyzer
#

#-------------------------------------------------------------------
# The following lines define directories. Adjust if necessary
#

DRV_DIR         = $(MIDASSYS)/drivers
INC_DIR 	= $(MIDASSYS)/include
MXML_DIR	= $(MIDASSYS)/../mxml
INC_DIR        += -I$(MXML_DIR)
LIB_DIR 	= $(MIDASSYS)/lib

# MIDAS flags
CPPFLAGS  += -DOS_LINUX -Dextname
#   DEFAULT_EVENT_BUFFER_SIZE is needed for midas rev 4057
#CPPFLAGS  += -DDEFAULT_EVENT_BUFFER_SIZE=$(shell perl -e 'print 500*1024*1024')
CPPFLAGS  += -DDEFAULT_EVENT_BUFFER_SIZE=$(shell perl -e 'print 1024*1024*1024')
LIBS += -L$(LIB_DIR) -lmidas -lm -lz -lutil -lnsl -lpthread -lrt 

#CAEN VME support
LIBS += -L$(CAENVMELIBSYS)/lib -lCAENVME
CPPFLAGS += -I$(CAENVMELIBSYS)/include   
CPPFLAGS += -DLINUX

include $(WNRSYS)/include/jmodRules.mk

#-------------------------------------------------------------------
# List of frontend_camac modules
#                 

DRIVER = camacnul

# compiler
CPPFLAGS += -I. -I$(INC_DIR) -I$(DRV_DIR)
CFLAGS += $(CPPFLAGS) -g -O2
CXXFLAGS = $(CFLAGS)
LDFLAGS += -g

#.SUFFIXES: .cxx
#.c.o:
#	$(CC) $(CFLAGS) $(OSFLAGS) -c $<
#.cxx.o:
#	$(CXX) $(CFLAGS) $(ROOTCFLAGS) $(OSFLAGS) -c $<

################################################################################

PROGS = frontend_vme
all:: $(PROGS)

frontend_vme: $(LIB_DIR)/mfe.o frontend_vme.o $(MODULES)
	$(CXX) $(LDFLAGS) -o frontend_vme $(LIB_DIR)/mfe.o \
	frontend_vme.o $(MODULES) $(LIBS)
	
$(DRIVER).c: $(DRV_DIR)/camac/$(DRIVER).c
	cp $^ .

clean::
	rm -f camacnul.c
	rm -f *.o *~ \#*

distclean::
	make clean
	rm -f $(PROGS)
	rm -f *.bak
	rm -f core

