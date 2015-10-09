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
#include <array>

class File
{
    std::array<std::vector<std::string>, 2> lines;
    std::string tempLine, tempLine2;

public:
    void setFile(std::string const& firstFile, std::string const& secondFile) {
        std::ifstream fileOne(firstFile);
        if (!fileOne) throw std::runtime_error("error opening first file");

        std::ifstream fileTwo(secondFile);
        if (!fileTwo) throw std::runtime_error("error opening second file");
        while(getline(fileOne, tempLine)) {
            lines.at(0).push_back(tempLine);
        }

        std::cout << lines.at(0).size();
    };

};

int main(int argc, char *argv[]) {
    File getFile;
    getFile.setFile(argv[1], argv[2]);
}
