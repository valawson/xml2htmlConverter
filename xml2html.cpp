#include "xml2html.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include "HTML/HTML.h"

#include "table.h"
#include "row.h"

using namespace std;

namespace {

const std::string HTMLFileEnding = ".html";

/**
 Creates the same filename but, ending in html instead.
 */
std::string convertXmlFilenameToHTMLFilename(std::string filename) {
    return filename.substr(0,filename.find_last_of('.'))+ HTMLFileEnding;
}

/**
 Writes the file contents provided to the file created with the name provided.
 @param fileName : The write to write the content too.
 @param fileContents : The information to put into the file.
 */
void writeToFile(const std::string& fileName, const std::string& fileContents) {
    std::ofstream myFile(fileName);

    // Write to the file
    myFile << fileContents;

    // Close the file
    myFile.close();
}

/**
Generated the XMLDocuemnt object from the given file.
 @param fileName : The file to read the XML from.
 @return The XML document or nullptr if the document failed to be created.
*/
tinyxml2::XMLDocument* generateXmlDocument(const std::string& fileName) {
    tinyxml2::XMLDocument* xmlDoc = new tinyxml2::XMLDocument();
    tinyxml2::XMLError result = xmlDoc->LoadFile(fileName.c_str());
    if (result != tinyxml2::XML_SUCCESS) {
        // TODO Switch by error to provide more infomation on what went wrong.
        return nullptr;
    }
    return xmlDoc;
}

}

namespace xml2html {

bool Xml2htmlConverter::convertXMLToHTMLTable( const std::string& fileName )
{
    // Parse the XML into the XML Document
    auto xmlDocument(generateXmlDocument(fileName));
    if (!xmlDocument) {
        std::cerr << "XML document did not parse. Please check that the file exists and is in XML format." << std::endl;
        return 1;
    }
    
     // Create the table
    auto table = new Table(xmlDocument->FirstChildElement());
    
    // Create the HTML document
    HTML::Document document("");
    
    //Add the table to the HTML document
    table->toHTML(document);
    
    // Write to file
    writeToFile(convertXmlFilenameToHTMLFilename(fileName), document.toString());
    
    return 0;
    
}
}
