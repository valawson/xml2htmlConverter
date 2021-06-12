
#include "HTML/HTML.h"
#include "tinyxml2/tinyxml2.h"

#include "row.h"

namespace xml2html {
/**
A Table as defined by the xml element.
A table contains many rows.
*/
class Table {
public:

    Table(tinyxml2::XMLElement * element);
    
    /**
     Adds the table to the document.
     @param document : The HTML document that the table will be added to.
     */
    void toHTML(HTML::Document& document) ;
    
private:
    std::vector<Row*> _rows;
};

}

