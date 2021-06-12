# XML2HTML Converter

This XML to HTML Converter currently supports converting tables from XML to HTML. 

It is written to support additional conversions in the future. 
It has also been created in a way to easily add support for sorting data within the tables during conversion.


## Converting Tables
The XML file is expected to be in this format to convert to a table. If it is in a different format, it will not break but, the table output will not be as shown below. The expected XML format of the tables is:

    <table_name>
        <row_element_A>
            <column_element_1> Column Content 1A</column_element_1>
            <column_element_2> Column Content 2A</column_element_2>
        </row_element_A>
        <row_element_B>
            <column_element_1> Column Content 1B</column_element_1>
            <column_element_2> Column Content 2B</column_element_2>
        </row_element_B>
    </table_name>

The names of the XML elements can be any value. For example, the table element does not need to be named table_name. The value given for the column elements will be used as the column title. 

The above XML code would result in a table in this format in HTML:
| column_element_1 | column_element_2 |
|--|--|
| Column Content 1A | Column Content 2A |
| Column Content 1B | Column Content 2B |

## Building

To build use the command:

    make
 
 To use, pass the name of the file via command line:

    ./xml2html cd_catalog.xml
    
## Testing
The tests cover basic use cases such as no file passed in, an incorrect file, improper XML file and expected XML file. 
To run these basic tests:

    make test
   



## 3rd Party Libraries

### tinyxml2
The library can be found here: https://github.com/leethomason/tinyxml2
TinyXML-2 is released under the zlib license.

###  HTML Builder
The can be found here: https://github.com/SRombauts/HtmlBuilder
HTML Builder is released under the MIT License (MIT).

## License
The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
