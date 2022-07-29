/**
  skeleton - a sample project using the zpl ecosystem

Usage:
#  define SKEL_IMPLEMENTATION exactly in ONE source file right BEFORE including the library, like:

#  define SKEL_IMPLEMENTATION
#  include "skeleton.h"

Options:

GitHub:
  https://github.com/zpl-c/skeleton

Version History:
  @{CHANGELOG}

License:
  @{LICENSE}
*/

#ifndef SKEL_H
#define SKEL_H

#define SKEL_VERSION_MAJOR 15
#define SKEL_VERSION_MINOR 0
#define SKEL_VERSION_PATCH 0
#define SKEL_VERSION_PRE ""

#include "zpl_hedley.h"

#define SKEL_VERSION SKEL_VERSION_ENCODE(SKEL_VERSION_MAJOR, SKEL_VERSION_MINOR, SKEL_VERSION_PATCH)

#ifdef SKEL_IMPL
#    ifndef SKEL_IMPLEMENTATION
#    define SKEL_IMPLEMENTATION
#    endif
#endif

#if defined(__cplusplus) && !defined(SKEL_EXTERN)
#    define SKEL_EXTERN extern "C"
#else
#    define SKEL_EXTERN extern
#endif

#ifndef SKEL_DEF
#    if defined(SKEL_SHARED_LIB)
#        ifdef SKEL_IMPLEMENTATION
#            define SKEL_DEF SKEL_PUBLIC
#        else
#            define SKEL_DEF SKEL_IMPORT
#        endif
#    elif defined(SKEL_STATIC_LIB)
#        ifdef SKEL_IMPLEMENTATION
#            define SKEL_DEF
#        else
#            define SKEL_DEF SKEL_EXTERN
#        endif
#    elif defined(SKEL_STATIC)
#        define SKEL_DEF static
#    else
#        define SKEL_DEF SKEL_EXTERN
#    endif
#endif

#ifndef SKEL_DEF_INLINE
#    if defined(SKEL_STATIC)
#        define SKEL_DEF_INLINE
#        define SKEL_IMPL_INLINE
#    else
#        define SKEL_DEF_INLINE static
#        define SKEL_IMPL_INLINE static inline
#    endif
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wunused-function"
#    pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#    pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#endif

#if defined(_MSC_VER)
#    pragma warning(push)
#    pragma warning(disable : 4201)
#    pragma warning(disable : 4127) // Conditional expression is constant
#endif

/* general purpose includes */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#if defined(SKEL_SYSTEM_WINDOWS)
#    include <intrin.h>
#endif

// TODO: header includes go here

#include "header/foo.h"

#if defined(SKEL_COMPILER_MSVC)
#    pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#    pragma GCC diagnostic pop
#endif

#if defined(SKEL_IMPLEMENTATION) && !defined(SKEL_IMPLEMENTATION_DONE)
#define SKEL_IMPLEMENTATION_DONE

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wattributes"
#    pragma GCC diagnostic ignored "-Wunused-value"
#    pragma GCC diagnostic ignored "-Wunused-function"
#    pragma GCC diagnostic ignored "-Wwrite-strings"
#    pragma GCC diagnostic ignored "-Wunused-parameter"
#    pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#    pragma GCC diagnostic ignored "-Wmissing-braces"
#    pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#    pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#    pragma GCC diagnostic ignored "-Wignored-qualifiers"
#endif

#if defined(_MSC_VER)
#    pragma warning(push)
#    pragma warning(disable : 4201)
#    pragma warning(disable : 4996) // Disable deprecated POSIX functions warning
#    pragma warning(disable : 4127) // Conditional expression is constant
#    pragma warning(disable : 4204) // non-constant field initializer
#    pragma warning(disable : 4756) // -INFINITY
#    pragma warning(disable : 4056) // -INFINITY
#    pragma warning(disable : 4702) // unreachable code
#endif

/* general purpose includes */

#include <stdio.h>
#include <errno.h>

#if defined(SKEL_SYSTEM_UNIX) || defined(SKEL_SYSTEM_MACOS)
#    include <unistd.h>
#elif defined(SKEL_SYSTEM_WINDOWS)
#    if !defined(SKEL_NO_WINDOWS_H)
#        ifndef WIN32_LEAN_AND_MEAN
#            ifndef NOMINMAX
#            define NOMINMAX
#            endif

#            define WIN32_LEAN_AND_MEAN
#            define WIN32_MEAN_AND_LEAN
#            define VC_EXTRALEAN
#        endif
#        include <windows.h>
#        undef NOMINMAX
#        undef WIN32_LEAN_AND_MEAN
#        undef WIN32_MEAN_AND_LEAN
#        undef VC_EXTRALEAN
#    endif
#endif

// TODO: source includes go here

#include "source/foo.c"

#if defined(SKEL_COMPILER_MSVC)
#    pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#    pragma GCC diagnostic pop
#endif

#endif // SKEL_IMPLEMENTATION
#endif // SKEL_H

//TOC:
//skeleton.h
//zpl_hedley.h
//header/foo.h
//source/foo.c
