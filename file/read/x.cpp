#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <vector>
#include <typeinfo>

using namespace std;
using namespace boost::filesystem;

int i = 0;

class FileFactory {
public:
    void setFile(string name, string path, int i);
    FileFactory();
private:
    string name;
    string path;
};

FileFactory::FileFactory(void) {

	boost::filesystem::path dir("objects");
	boost::filesystem::create_directory(dir); 

}

void FileFactory::setFile(string name, string path, int i) {
    name = name;
    path = path;
    
    string line;
    
    ifstream getFile(name);
    
   while(getline(getFile, line)) {
   
   
   string dir_path = "objects/" + to_string(i);

	boost::filesystem::path dir(dir_path);
	boost::filesystem::create_directory(dir);        


   }

    
}


int main() {
    FileFactory file;
    for ( boost::filesystem::recursive_directory_iterator end, dir("."); dir != end; ++dir ) {
                   
        if(is_regular_file(*dir)){
        
        i++;
		file.setFile(
		    dir->path().filename().native(),
		    dir->path().native(),
		    i
		);     
        
        }
  

    }
}
