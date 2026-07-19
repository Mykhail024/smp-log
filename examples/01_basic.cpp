#include <smp/log.hpp>

int main(int argc, char *argv[])
{
    Log_Info("Hello from smp-log");
    Log_Warning("This is warning");
    Log_Error("This is error");

    return 0;
}
