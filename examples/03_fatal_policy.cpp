#include <smp/log.hpp>

int main(int argc, char *argv[])
{
    smp::log::set_fatal_action(smp::log::FatalAction::None); // Disable action on fatal error

    Log_Info("Program continues after fatal log");
    Log_Fatal("Fatal without process termination");
    Log_Info("Still running");

    return 0;
}
