#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

string returnSingleFromFileLine(string file, int num) {

    ifstream getFile(file.c_str());
    string line1;
    int index = 0;
    while (getline(getFile, line1)) {
        index++;
        if(num == index)
            break;

    }
    
    return line1;

}

int readlastLine(string file) {

    int index3 = 0;
    ifstream indexLog(file.c_str());
    string line;
    while (getline(indexLog, line)) {
        index3++;
        if (indexLog.eof())
            break;

    }
    return index3;
}

void commit() {


    ofstream commit;
    commit.open("b.txt");

    for(int i = 1; i <= readlastLine("a.patch"); i++) {

	if(returnSingleFromFileLine("a.patch", i).at(0) == '+'){
	
		commit << returnSingleFromFileLine("a.patch", i).substr(1) << endl;
	
	}else if(returnSingleFromFileLine("a.patch", i).at(0) == '-'){
	
		commit << "" << endl;
	
	}
	
	
    }
}



int main(){

 commit();

}
