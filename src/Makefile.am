AM_CFLAGS=-O3
AUTOMAKE_OPTIONS=std-options subdir-objects
lib_LTLIBRARIES = librmem.la

librmem_ladir=$(PROJ_DIR)
librmem_la_SHORTNAME = lrm
librmem_la_CFLAGS=-I$(INCLUDE_DIR)
librmem_la_LIBADD=$(LIBRLOG)
librmem_la_LDFLAG=
librmem_la_SOURCES=mem.c
include_HEADERS=$(INCLUDE_DIR)/librmem.h

.PHONY: check-syntax
check-syntax:
	gcc -o nul ${AM_CFLAGS} ${librmem_la_CFLAGS} -S ${CHK_SOURCES}
