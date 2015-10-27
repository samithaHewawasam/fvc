#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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

void commit() {
    
	fstream commits("t.txt" , fstream::in | fstream::out);

	for (int i = 1; i < readlastLine("a.patch"); i++)
	{
	
	    std::stringstream ss;

	    std::string line = returnSingleFromFileLine("a.patch", i);
	    
		if (!line.empty()) 
		{
			if (line.at(0) == '+') 
			{
				ss.str(line.substr(1));
			}
			else if (line.at(0) == '-')
			{
				ss.str("");
			}
		}
		else 
		{
			ss.str(returnSingleFromFileLine("b.txt", i));
		}
		
		cout << ss.str() << endl;
		ss.clear();

		
	}
	
}



int main() {

    commit();

}
