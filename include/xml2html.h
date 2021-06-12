#pragma once

#include <string>

#include "tinyxml2/tinyxml2.h"

namespace xml2html {

/**
Manages the different conversions of XML to HTML
*/
class Xml2htmlConverter {
public:
    /**
     Converts an XML file into an HTML table.
     The HTML will be put into a file of the same name as the XML file with '.html' in place of '.xml'
     @param fileName : The name of the file that contains the xml code
     @return whether the conversion was successful
     */
    static bool convertXMLToHTMLTable( const std::string& fileName);
};
}
