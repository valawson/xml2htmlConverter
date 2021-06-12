#include "row.h"

namespace xml2html {
    
Row::Row(tinyxml2::XMLElement * element) {
    _rowXML = element;
}

void Row::titlesToHTML(HTML::Document& document) {

    document << HTML::RowStart();
    
    // Get the first child element which will point to the first column element of the row.
    tinyxml2::XMLElement * columnElement =  _rowXML->FirstChildElement();
    
    // Iterate through all the columns
    while(columnElement != nullptr) {
        document << HTML::Col(columnElement->Name()) ;
        columnElement = columnElement->NextSiblingElement();
    }
    
    document << HTML::RowEnd();
}

void Row::toHTML(HTML::Document& document) {
    document << HTML::RowStart();
    
    // Get the first child element which will point to the first column element of the row.
    tinyxml2::XMLElement * columnElement =  _rowXML->FirstChildElement();
    
    // Iterate through all the columns
    while(columnElement != nullptr) {
        document << HTML::Col(columnElement->GetText()) ;
        columnElement = columnElement->NextSiblingElement();
    }
    
    document << HTML::RowEnd();
}

}
