#include <fs_inc/Globals.hpp>
#include <fs_inc/Configuration.hpp>

#include <iostream>

using namespace fs_kernel;

int main(int argc, char *argv[])
{
    std::cout << "Hallo" << glob::HOME_PATH << std::endl;
    Configuration c;
        std::cout << "Hallo" << c.CONF_PATH << std::endl;

return 0;

}
