#include <fs_inc/Globals.hpp>
#include <fs_inc/Configuration.hpp>
#include <fs_inc/CLAParser.hpp>

#include <iostream>

using namespace fs_kernel;

int main(int argc, char *argv[])
{
    
    CLAParser par(8);
    par.parse_options(&argc, argv);
    
    
    Configuration *c;
    try {
        c = new Configuration();
    } catch (res_dir_not_found_error & e) {
        
    }
    
    //std::cout << "Hallo" << c->CONF_PATH << std::endl;
    //std::cout << "Hallo" << c->RES_PATH << std::endl;
    
    delete c;

    return 0;

}
