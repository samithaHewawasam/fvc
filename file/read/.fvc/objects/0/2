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

	boost::filesystem::path dir_frcs(".frcs");
	boost::filesystem::create_directory(dir_frcs); 
	
	boost::filesystem::path dir_frcs_objects(".frcs/objects");
	boost::filesystem::create_directory(dir_frcs_objects); 
	
	ofstream commit(".frcs/commit.log");
	ofstream index(".frcs/index.log");
}

int main() {
    FileFactory frcs;
}
