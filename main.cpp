
#include <iostream>
#include <sstream>
#include <fstream>

#include "xml2html.h"

int main( const int argc, const char *const argv[] )
{
    if (argc < 2) {
        std::cout << "Please provide the filename to parse" << std::endl;
        return 1;
    }
    return xml2html::Xml2htmlConverter::convertXMLToHTMLTable(argv[1]);
}
