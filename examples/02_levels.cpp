#include <smp/log.hpp>

int main(int argc, char *argv[])
{
    Log_Debug("Debug message");
    Log_Info("Info message");
    Log_Warning("Warning message");
    Log_Error("Error message");

    return 0;
}
