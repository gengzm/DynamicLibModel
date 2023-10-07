#pragma once

#ifdef _EXPORTING
#define _DECLSPEC    __declspec(dllexport)
#else
#define _DECLSPEC    __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
#endif
_DECLSPEC int aaaddd(int a, int b);