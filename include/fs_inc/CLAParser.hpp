#ifndef FS_CLAPARSER_CLASS_H
#define FS_CLAPARSER_CLASS_H

#include <string>
#include <map>


namespace fs_kernel {
    
class CLAParser
{

public:
    CLAParser(int xx=0);
    ~CLAParser();
    
    void parse_options(int *argc, char* argv[]);
    
    
protected:
    std::map<std::string, void (CLAParser::*)(int)> call_map;
    int x;
    
    
    void opt_v(int a);
    
    
    
};






}

#endif
