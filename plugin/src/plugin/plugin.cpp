#include "XPLMPlugin.h"
#include "ui/ui.h"
#include <cstring>

#if IBM
    #include <windows.h>
    BOOL APIENTRY DllMain( HANDLE hModule,
     DWORD ul_reason_for_call,
     LPVOID lpReserved
     )
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
#endif
#if LIN
    #include <GL/gl.h>
#elif __GNUC__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

#ifndef XPLM401
    #error This is made to be compiled against the XPLM401 SDK
#endif


PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc) {
    // Defining plugin details
    strcpy(outName, "Checklist Tester");
    strcpy(outSig, "io.anthonyberg.checklistplugin");
    strcpy(outDesc, "Plugin to connect and complete actions in X-Plane for the Checklist Tester");

    UI::Init();

    return 1;
}

PLUGIN_API int XPluginEnable(void) {
    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho, int inMessage, void * inParam) { }

PLUGIN_API void XPluginDisable(void) { }

PLUGIN_API void XPluginStop(void) {
    // Cleaning up UI components
    UI::Destroy();
}
