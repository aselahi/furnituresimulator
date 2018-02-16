#include <fs_inc/CLAParser.hpp>

#include <iostream>
#include <map>

using namespace fs_kernel;


/*
 * Constructor, destructor
 */
CLAParser::CLAParser(int xx)
{
    this->call_map["aaa"] = &CLAParser::opt_v;
    this->x = xx;
    
}

CLAParser::~CLAParser()
{
}

/*
 * Public functions
 */

void CLAParser::parse_options(int *argc, char *argv[]) {
    for(int i =0; i < *argc; i++){
        std::cout << argv[i] << std::endl;
    }
    
    (*this.*(this->call_map["aaa"]))(33);
}

/*
 * Protected/private functions
 */

void CLAParser::opt_v(int a) {
    std::cout << "*** Version 0.0.0 *** " << this->x << " ***"  << a << "***" << std::endl;
}
































