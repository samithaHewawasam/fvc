#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string returnSingleFromFileLine(string file, int num) {

    ifstream getFile(file.c_str());
    string line;
    int index = 1;
    while (getline(getFile, line)) {
        if(num == index)
            break;            
        index++;
    }
    
    return line;

}

int readlastLine(string file) {

    int index = 1;
    ifstream indexLog(file.c_str());
    string line;
    while (getline(indexLog, line)) {
        if (indexLog.eof())
            break;
       index++;

    }
    return index;
}

void check() {

    int getTheLineNumber = 0;
    if(readlastLine("a.txt") > readlastLine("b.txt"))
        getTheLineNumber = readlastLine("a.txt");
    else
        getTheLineNumber = readlastLine("b.txt");

    ofstream patch;
    patch.open("a.patch", ios_base::app);

    // b.txt = previous file in the corresponding object
    // a.txt = actual file in working directory

    for(int i = 1; i < getTheLineNumber; i++) {

        if(returnSingleFromFileLine("a.txt", i) == returnSingleFromFileLine("b.txt", i)) {

            patch << "" << endl;

        } else if(returnSingleFromFileLine("a.txt", i) != returnSingleFromFileLine("b.txt", i)) {

            if(!returnSingleFromFileLine("a.txt", i).empty() && returnSingleFromFileLine("b.txt", i).empty()) {

                patch << "+" << returnSingleFromFileLine("a.txt", i) << endl;

            } else if(!returnSingleFromFileLine("b.txt", i).empty() && returnSingleFromFileLine("a.txt", i).empty()) {

                patch << "-" << returnSingleFromFileLine("b.txt", i) << endl;

            }else{
            
                patch << "+" << returnSingleFromFileLine("a.txt", i) << endl;
            
            }

        }


    }
}

int main() {

    check();

}



