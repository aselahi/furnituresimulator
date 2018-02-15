#include <fs_inc/Globals.hpp>
#include <fs_inc/Configuration.hpp>
#include <fs_inc/Logger.hpp>

#include <boost/filesystem.hpp>

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace fs_kernel;
using namespace glob;

namespace bofs = boost::filesystem; 

/* Exceptions */
//namespace fs_kernel {
    //FileNotFoundException res_dir_error("Resources directory not found!");
//}

/*
 * Constructor, destructor
 */
Configuration::Configuration()
{
    /* DEFINITIONS */
    this->CONF_DIR_BASENAME = ".furnsim";
    this->RES_DIR_BASENAME = "furnsim";
    
    /* CONFIGURATION DIR */
    // OS specific: Find path for configuration directory.
    if(__LINUX) {
        char *home = std::getenv("HOME");
        this->HOME_PATH = home;
        this->CONF_PATH = this->HOME_PATH / this->CONF_DIR_BASENAME;
        this->RES_PATH = bofs::current_path() /  this->RES_DIR_BASENAME;
    }
    
    // Standard Paths
    std::vector<path> conf_paths = {this->CONF_PATH, bofs::current_path() / ".furnsim"};
    std::vector<path> res_paths = {this->RES_PATH};
    
    // Check for existance and try to create, if not exists.
    // Try multiple possible locations for the configuration directory.
    bool live_mode = false;
    bool conf_dir_setup_succesfull = false;
    bool res_dir_setup_succesfull = false;
    
    for(std::vector<path>::iterator pit = conf_paths.begin(); (not conf_dir_setup_succesfull) and (pit != conf_paths.end()); ++pit) {
        this->CONF_PATH = *pit;
        
        std::cout << "Cheking if configuration directory exists: " << this->CONF_PATH << std::endl;
        if( not bofs::is_directory(this->CONF_PATH) ) {
            std::cout << "Not found, trying to create." << std::endl;
            try {            
                bofs::create_directory(this->CONF_PATH);
                conf_dir_setup_succesfull = true;
                std::cout << "Success.." << std::endl;
            } catch (const bofs::filesystem_error& e) {
                std::cout << "Failed." << std::endl;
                conf_dir_setup_succesfull = false;
            }
        } else {
            conf_dir_setup_succesfull = true;
            std::cout << "Success.." << std::endl;
        }
    }
    if ( not conf_dir_setup_succesfull ) {
        std::cout << "Failed creating all possible config dirs. Starting in live mode. Your settings will not be saved."  << std::endl;
        live_mode = true;
    }
    
    for(std::vector<path>::iterator pit = res_paths.begin(); (not res_dir_setup_succesfull) and (pit != res_paths.end()); ++pit) {
        this->RES_PATH = *pit;
        
        std::cout << "Cheking if resources directory exists: " << this->RES_PATH << std::endl;
        if( not bofs::is_directory(this->RES_PATH) ) {
            std::cout << "Not found." << std::endl;            
        } else {            
            std::cout << "Found." << std::endl;
            res_dir_setup_succesfull = true;
        }        
    }
    if( not res_dir_setup_succesfull ) {
        res_dir_not_found_error e;
        throw e;
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













/* ******* EXCEPTION ******* */
const char*  res_dir_not_found_error::what() const throw() {
    return "Resources directory not found.";
}






















