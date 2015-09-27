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
using namespace std;

class File{

  public:
      string fileName;
      string fileCreated;
      string fileModified;
      string fileLine;
      double fileSize;

    public:
      File(string fileName);

};

File::File(string fileName){
  ifstream getFile (fileName);
  if (getFile.is_open())
    {
      cout << "File is open";
    }
}

int main(){
  File file1("1.txt");
}
