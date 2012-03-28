# $Id: Makefile,v 1.1 2007/07/23 13:54:42 tat Exp $

include common.mk
include $(KLONE_SRC)/Makefile.conf

TOP := $(shell pwd)

LIB = mymisc

SRCS = misc.c

CFLAGS += -I$(TOP) -I$(TOP)/.. $(KLONE_CFLAGS)

NO_INSTALL = true

include lib.mk
