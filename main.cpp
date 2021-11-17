#include <iostream>
#include "Windows.h"
#include "Core/application.hpp"

// Set new DLL folder after delay loading
struct PreInitialization { PreInitialization(){ SetDllDirectoryW(L".\\Binaries\\"); }; } preinit;

int main(int argc, char* argv[]){

    Application app;

    app.Initialize();
        app.Run();
    app.Shutdown();

    return 0;

};