#include <iostream>
#include <SystemInterface.hpp>

int main()
{
    SystemInterface systemInterface;

    systemInterface.Initialize();

    systemInterface.Run();

    systemInterface.Shutdown();

    std::cin.get();
    
    return 0;
}