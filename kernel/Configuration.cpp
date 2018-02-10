#include <fs_inc/Globals.hpp>
#include <fs_inc/Configuration.hpp>
#include <fs_inc/Logger.hpp>

//#include <boost/filesystem.hpp>

#include <cstdlib>
#include <iostream>

using namespace fs_kernel;
using namespace glob;

//namespace bofs = boost::filesystem; 


/*
 * Constructor, destructor
 */
Configuration::Configuration()
{
    if(__LINUX) {
        char *home = std::getenv("HOME");
        this->HOME_PATH = home;
        this->CONF_PATH = this->HOME_PATH / this->CONF_DIR_BASENAME;
    }
}

Configuration::~Configuration()
{
}

/*
 * Public functions
 */



/*
 * Protected/private functions
 */


































