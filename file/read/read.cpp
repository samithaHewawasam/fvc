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

class File
{
    const char *lines[];
    std::vector<std::string> v(lines, std::end(lines));
    std::string lineOne;
    std::string lineTwo;
public:
    void readFile(std::string const& firstFile, std::string const& secondFile) {
      ifstream fileOne(firstFile);
      if (!fileOne) throw std::runtime_error("error opening first file");

      ifstream fileTwo(secondFile);
      if (!fileTwo) throw std::runtime_error("error opening second file");

        int x=0;
        int y=0;
        while(getline(fileOne, lineOne)) {
            line[x][0] = lineOne;
            x++;
        }
        while(getline(fileTwo, lineTwo)) {
            line[y][1] = lineTwo;
            y++;
        }

        for(int i=0; 50; i++) {
            cout<<line[i][0]<<endl;
        }
    };
};

int main(int argc, char *argv[]) {
    File getFile;
    getFile.readFile(argv[1], argv[2]);
}
