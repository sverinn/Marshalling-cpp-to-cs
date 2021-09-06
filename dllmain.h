#pragma once
#include <string>

#ifdef PINVOKELIB_EXPORTS
#define PINVOKELIB_API __declspec(dllexport)
#else
#define PINVOKELIB_API __declspec(dllimport)
#endif


typedef struct pItem
{
public:
    int a;
    const char* str;
    pItem* items;
};

#ifdef __cplusplus
extern "C"
{
#endif

    PINVOKELIB_API pItem* getData();

#ifdef __cplusplus
}
#endif