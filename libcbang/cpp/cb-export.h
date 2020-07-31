#ifndef __CB_EXPORT_H__
#define __CB_EXPORT_H__

#if defined(__GNUC__)
#define _CB_EXPORT_GNUC_FULLVERSION \
    ( (__GNUC__            * 10000) \
    + (__GNUC_MINOR__      *   100) \
    + (__GNUC_PATCHLEVEL__ *     1) )
#else
#define _CB_EXPORT_GNUC_FULLVERSION 0
#endif

#if defined(WIN32) || defined(_WIN32) || \
    defined(WIN64) || defined(_WIN64) || \
    defined(WINCE) || defined(_WINCE) || \
    defined(__TOS_WIN__) || \
    defined(__WIN32__) || defined(__TOS_WIN__) || \
    defined(__WINDOWS__)
#define _CB_EXPORT_PLATFORM_WINDOWS
#endif

#if defined(CB_EXPORT_API)
#  if defined(_CB_EXPORT_PLATFORM_WINDOWS)
#    define CB_API __declspec(dllexport)
#  elif _CB_EXPORT_GNUC_FULLVERSION >= 40000
#    define CB_API __attribute__((visibility("default")))
#  else
#    define CB_API
#  endif
#else
#  if defined(_CB_EXPORT_PLATFORM_WINDOWS)
#    define CB_API __declspec(dllimport)
#  else
#    define CB_API
#  endif
#endif

#endif
