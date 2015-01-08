#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "xmlwriter.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>

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

  else cout << "Unable to open file"; 
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("[Usage:] $program.exe output_file.xml \n ");
	}
	else {

  Sleep(500);
  printf("output filename specified : %s\n",argv[1]);
  Sleep(500);
  printf("-----------------------\n");
  Sleep(500);

  // generate XML file from scratch
  ofstream f(argv[1]);
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

      printf("Generated file %s\n", argv[1]);

  return 0;

  	}
}