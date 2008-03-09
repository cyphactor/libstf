AM_CFLAGS = -Wall -Werror
AUTOMAKE_OPTIONS = no-dependencies
stfincdir = $(includedir)/stf
lib_LTLIBRARIES = libstf.la
libstf_la_LDFLAGS = -no-undefined -version-info 0:0:0 @PMF_SYSTEM@
libstf_la_CFLAGS = -I../headers/stf/
libstf_la_SOURCES = stf.c
stfinc_HEADERS = ../headers/stf/stf.h ../headers/stf/stf_export.h