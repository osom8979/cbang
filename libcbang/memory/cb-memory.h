#ifndef __CB_MEMORY_H__
#define __CB_MEMORY_H__

#include <cb-export.h>

#if defined(__cplusplus)
extern "C" {
#endif

CB_API void * cb_malloc(size_t size);
CB_API void * cb_calloc(size_t size);
CB_API void * cb_realloc(size_t size);
CB_API void cb_free(void * data);

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif
