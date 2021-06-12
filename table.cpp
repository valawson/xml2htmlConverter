#include "table.h"


namespace xml2html {

Table::Table(tinyxml2::XMLElement * element) {
    tinyxml2::XMLElement * rowElement = element->FirstChildElement();
    
    // Create a row element for each row contained in the table.
    while (rowElement != nullptr)
    {
        _rows.emplace_back(new Row(rowElement));
        rowElement = rowElement->NextSiblingElement();
    }
}
    
void Table::toHTML(HTML::Document& document) {
    document << HTML::TableStart();
    
    // As long as there is at least one row, titles are needed for the table.
    // This assumes that the titles are the same for all rows.
    // The xml is expected to be well formatted to properly format the html.
    if(!_rows.empty()) {
        _rows.front()->titlesToHTML(document);
    }
    
    // Add all the rows to the HTML document.
    for (auto& row : _rows) {
        row->toHTML(document);
    }
    document << HTML::TableEnd();
}

}
