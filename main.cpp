#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "xmlwriter.h"

using namespace std;
using namespace	xmlw;

void insertdata(XmlStream &x) {
  string line;
  ifstream myfile ("DATALOG.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      x << tag("l") << chardata() << "-" << line << endtag();
    }
    myfile.close();
  }
}

int main()
{
  printf("hi\n");
  printf("-----------------------\n");

  // generate XML file from scratch
  ofstream f("output.xml");
  XmlStream xml(f);

  xml 
      << tag("blocks") 
          << attr("app") << "Snap! 4.0, http://snap.berkeley.edu"
          << attr("version") << "1"
            
            << tag("block-definition") 
              << attr("s") << "data reporterr"
              << attr("type") << "command"
              << attr("category") << "sensing"

            << tag("header") << endtag()
            << tag("code") << endtag()
            << tag("inputs") << endtag()

            << tag("script") 
              << tag("block") 
                << attr("s") << "doSetVar"
                    << tag("l") 
                      << chardata() << "datalist" 
                    << endtag()

                  << tag("block") 
                    << attr("s") << "reportNewList"

                    << tag("list");

                    insertdata(xml);  // insert data


      xml << endtag("block-definition"); // close all tags up to specified

  return 0;
}