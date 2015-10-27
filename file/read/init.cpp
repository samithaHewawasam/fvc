#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <vector>
#include <typeinfo>
#include <bitset>

using namespace std;
using namespace boost::filesystem;

class FileFactory {
public:
    void setFile(string name, string path, int i);
    string readFile(string name);
    FileFactory();
private:
    string name;
    string path;
};

FileFactory::FileFactory(void) {

	boost::filesystem::path dir_fvc(".fvc");
	boost::filesystem::create_directory(dir_fvc); 
	
	boost::filesystem::path dir_frcs_objects(".fvc/objects");
	boost::filesystem::create_directory(dir_fvc_objects); 
	
	ofstream commit(".fvc/commit.log");
	ofstream index(".fvc/index.log");
}

int main() {
    FileFactory fvc;
}
