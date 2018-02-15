#ifndef FS_CONFIGURATION_CLASS_H
#define FS_CONFIGURATION_CLASS_H

#include <fs_inc/Logger.hpp>

#include <boost/filesystem.hpp>

#include <string>
#include <exception>

typedef boost::filesystem::path path;


namespace fs_kernel {
    
class res_dir_not_found_error: public std::exception { public: virtual const char* what() const throw(); };
    
    
class Configuration 
{

public:
    Configuration();
    ~Configuration();
    
    path HOME_PATH;
    path CONF_DIR_BASENAME;
    path CONF_PATH;
    path RES_DIR_BASENAME; // Ressources path
    path RES_PATH;
    
    Logger * logger;

    
protected:


};






}

#endif
