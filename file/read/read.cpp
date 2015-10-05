/*
  *Project: Revision Control System;
  *Author:Samitha Hewawasam;
  *Date:2015-09-27;
  *Tool:atom text editor;
  *Compiler:g++;
  *OS:ubuntu 14.04;
  *Extra Tools: astyle prity print
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class File
{
    std::lines<std::vector<std::string>, 2>;
    std::string lineOne;
    std::string lineTwo;
public:
    void readFile(std::string const& firstFile, std::string const& secondFile) {
      ifstream fileOne(firstFile);
      if (!fileOne) throw std::runtime_error("error opening first file");

      ifstream fileTwo(secondFile);
      if (!fileTwo) throw std::runtime_error("error opening second file");

        while(getline(fileOne, lineOne)) {
          lines[0].push_back(lineOne);
        }
        while(getline(fileTwo, lineTwo)) {
          lines[1].push_back(lineTwo);
        }

        for(int i=0; 50; i++) {
            cout<<lines[i][0]<<endl;
        }
    };
};

int main(int argc, char *argv[]) {
    File getFile;
    getFile.readFile(argv[1], argv[2]);
}
