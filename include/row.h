#pragma once

#include "HTML/HTML.h"
#include "tinyxml2/tinyxml2.h"

namespace xml2html {
/**
 A Row as defined by the xml element.
 */
class Row {
public:
    
    Row(tinyxml2::XMLElement * element);
    
    /**
     Adds the row of column titles to the document. The title is derived from the XML element name.
     @param document : The HTML document that the row will be added to.
     */
    void titlesToHTML(HTML::Document& document);
    
    /**
     Adds the row of columns to the document.
     @param document : The HTML document that the row will be added to.
     */
    void toHTML(HTML::Document& document);
    
private:
    tinyxml2::XMLElement * _rowXML;
    
};
}
