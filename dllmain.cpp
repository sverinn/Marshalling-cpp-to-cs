// dllmain.cpp : Defines the entry point for the DLL application.
#define PINVOKELIB_EXPORTS
#include "dllmain.h"
#include "windows.h"
#include <string>
using namespace std;

BOOL APIENTRY DllMain(HANDLE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

PINVOKELIB_API pItem* getData()
{
    pItem* Item = new pItem;
    Item->a = 1;
    Item->str = "Foo";
    Item->items = new pItem();
    return Item;
}