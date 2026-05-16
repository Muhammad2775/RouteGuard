//#include <iostream>
#include <print>

#include <Constants.hpp>
#include <SystemInterface.hpp>

using namespace std;

int main()
{
    SystemInterface systemInterface;

    systemInterface.Initialize();
    systemInterface.Run();
    systemInterface.Shutdown();

    print("RouteGuard has exited successfully.");

    return 0;
}