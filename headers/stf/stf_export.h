/*
 * Copyright 2008 Andrew De Ponte.
 *
 * This file is part of lib_stf.
 *
 * lib_stf is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or any
 * later version.
 * 
 * lib_stf is distributed in the hopes that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with lib_stf; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#ifndef STF_EXPORT_H
#define STF_EXPORT_H

/* Basically, the autotools (autoconf, automake, and libtool) build
 * tools detect when a Win32 DLL is being built and defines the
 * DLL_EXPORT macro. If DLL_EXPORT is defined then we know that it is
 * building a Win32 DLL so we need to use __declspec(dllexport) for each
 * item we would like exposed to the client applications from the DLL.
 * Hence, we have created our own macro STF_EXPORT containing this
 * value.
 *
 * If DLL_EXPORT is NOT defined we know that we are NOT building a Win32
 * DLL which leaves us a couple possibilities. One, is that we are
 * building Unix/Linux version of the library, another possibility is
 * that a Unix/Linux client application is linking to the Unix/Linux
 * version of the library. The final possability is that a Win32 client
 * application is linking to the Win32 DLL version of the library. In
 * this last case __declspec(dllimport) must be used for each item that
 * the client application should be allowed to import from the DLL.
 * Hence, we force the user to define a macro (LIBSTF_DLL_IMPORT) when
 * building/linking a Win32 client application. This tells our library
 * to set our STF_EXPORT macro to __declspec(dllimport) rather than
 * __declspec(dllexport).
 *
 * In the cases that one is either building a Unix/Linux client
 * application which links to this library, or building a Unix/Linux
 * version of this library there is no need for doing
 * __declspec(dllexport) or __declspec(dllimport). Hence our STF_EXPORT
 * is set to a value of nothing.
 */
#ifdef DLL_EXPORT
    #define STF_EXPORT __declspec(dllexport)
#else
    #ifdef LIBSTF_DLL_IMPORT
        #define STF_EXPORT __declspec(dllimport)
    #endif
#endif
#ifndef STF_EXPORT
    #define STF_EXPORT
#endif

#endif