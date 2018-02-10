#ifndef FS_CONFIGURATION_CLASS_H
#define FS_CONFIGURATION_CLASS_H

#include <fs_inc/Logger.hpp>

#include <boost/filesystem.hpp>

#include <string>

typedef boost::filesystem::path path;


namespace fs_kernel {
    
class Configuration 
{

public:
    Configuration();
    ~Configuration();
    
    path HOME_PATH;
    path CONF_DIR_BASENAME = ".furnsim";
    path CONF_PATH;
    
    Logger * logger;

    
protected:


};






}

#endif
