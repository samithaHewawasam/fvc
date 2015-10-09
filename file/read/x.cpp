#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <vector>
#include <typeinfo>

using namespace std;
using namespace boost::filesystem;

class FileFactory {
public:
    void setFile(string name, string path);
    FileFactory();
private:
    string name;
    string path;
};

FileFactory::FileFactory(void) {

}

void FileFactory::setFile(string name, string path) {
    name = name;
    path = path;
    
    cout << name <<endl;
}


int main() {
    FileFactory file;
    for ( boost::filesystem::recursive_directory_iterator end, dir("."); dir != end; ++dir ) {
        file.setFile(
            dir->path().filename().native(),
            dir->path().native()
        );
    }
}
