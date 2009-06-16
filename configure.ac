AC_PREREQ(2.59)
AC_INIT(Spartan Test Framework, 0.1.0, cyphactor@socal.rr.com, lib_stf)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/stf.c])
AM_CONFIG_HEADER([src/config.h])

LIBRARY_VERSION=1:0:0

# checks for programs
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL
AM_PROG_CC_C_O

# checks for libraries

case $host in
  *mingw32*) PMF_SYSTEM='-Wl,--output-def,.libs/libpmf.def,-s' ;;

	*darwin*)
	    AC_ARG_ENABLE([universal-binary],
	        [AS_HELP_STRING([--enable-universal-binary enable universal binary creation (default disabled)])],
	        [enable_univ_bin=$enableval],
	        [enable_univ_bin=no])
	    
	    [if [ "$enable_univ_bin" = "yes" ]
	    then
	        CFLAGS="$CFLAGS -mmacosx-version-min=10.4 -isysroot /Developer/SDKs/MacOSX10.4u.sdk -arch i386 -arch ppc"
	        PMF_SYSTEM="-mmacosx-version-min=10.4 -Wl,-syslibroot,/Developer/SDKs/MacOSX10.4u.sdk -arch i386 -arch ppc"
	    fi]	        

	    ;;	

    # Handle linking to the proper libraries for all other machines.
    *) PMF_SYSTEM='' ;;
esac

AC_SUBST([PMF_SYSTEM])
AC_SUBST([LIBRARY_VERSION])
AC_SUBST([LIBRARY_RELEASE])

# checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS([assert.h])

# checks for types

# checks for structures

# checks for compiler characteristics
AC_C_BIGENDIAN(
[AH_VERBATIM([WORD_BIGENDIAN],
[
/* This a custom Verbatim macro template created to handle proper compiler based big-endian detection on apple machines when building universal binaries. This is needed because autoconf normally will only check the endianness of the system it is running on, not the system that the other systems that are cross-compiled for when building universal binaries. */
#ifdef __APPLE__
#ifdef __BIG_ENDIAN__
#define WORD_BIGENDIAN 1
#endif
#else
#define WORD_BIGENDIAN 1
#endif])],
[AH_VERBATIM([WORD_BIGENDIAN],[
/* This a custom Verbatim macro template created to handle proper compiler based big-endian detection on apple machines when building universal binaries. This is needed because autoconf normally will only check the endianness of the system it is running on, not the system that the other systems that are cross-compiled for when building universal binaries. */
#ifdef __APPLE__
#ifdef __BIG_ENDIAN__
#define WORD_BIGENDIAN 1
#endif
#endif])],
[AH_VERBATIM([WORD_BIGENDIAN],[
/* This a custom Verbatim macro template created to handle proper compiler based big-endian detection on apple machines when building universal binaries. This is needed because autoconf normally will only check the endianness of the system it is running on, not the system that the other systems that are cross-compiled for when building universal binaries. */
#ifdef __APPLE__
#ifdef __BIG_ENDIAN__
#define WORD_BIGENDIAN 1
#endif
#endif])])

# checks for library functions

# checks for system services

AC_CONFIG_FILES([Makefile src/Makefile examples/Makefile])
AC_OUTPUT
