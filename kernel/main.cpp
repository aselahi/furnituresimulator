#include <fs_inc/Globals.hpp>
#include <fs_inc/Configuration.hpp>

#include <iostream>

using namespace fs_kernel;

int main(int argc, char *argv[])
{
    
    Configuration *c;
    try {
        c = new Configuration();
        std::cout << "Test1" << std::endl;
    } catch (res_dir_not_found_error & e) {
        std::cout << "Test2" << std::endl;
        std::cout << e.what() << std::endl;
    }
    
    
    std::cout << "Test3" << std::endl;
    std::cout << "Hallo" << c->CONF_PATH << std::endl;
    std::cout << "Hallo" << c->RES_PATH << std::endl;
    
    delete c;

    return 0;

}
