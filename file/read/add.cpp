#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/filesystem.hpp>


using namespace std;
using namespace boost::filesystem;


/*
 * Reading last line of the index.log and return last line number
 */

int readlastLine() {

    int index = 1;
    ifstream indexLog(".fvc/index.log");
    string line;
    while (getline(indexLog, line)) {
        if (indexLog.eof())
            break;
        index++;

    }
    return index;
}

/*
 *  get whole file contents and return to the file_get_contents function
 */


string file_get_contents (string path ) 
{
    ostringstream contents;
    ifstream file(path);
    contents << file.rdbuf();
    return (contents.str());
}


/*
 * Create clone objects in the ./.fvc/objects[@]/ if not exits
 */

int createCloneObject(string name) {

    try
    {
        if(!boost::filesystem::exists(".fvc/objects/" + name)) {
            boost::filesystem::path dir(".fvc/objects/" + name);
            boost::filesystem::create_directory(dir);
            
		ofstream objectLog;
		objectLog.open(".fvc/object.log", ios_base::app); // ios_base:app flag use to append text to file
                objectLog << name;      
        }       

    }
    catch (filesystem_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
   return readlastLine();   	   

}

/*
 * Create clone of files in the ./.fvc/objects[@]/[@] if not exits
 */
 
void createCloneOfIndexFiles(int objectFile, string cloneFile, string inFile){

         ofstream index;
         index.open(".fvc/objects/"+to_string(objectFile)+"/"+to_string(readlastLine()), ios_base::app);
         index << inFile;
         
         if(!boost::filesystem::exists(".fvc/objects/"+to_string(objectFile)+"c/"+to_string(readlastLine()))) {
         
         
         
         } 
} 


  

class FileFactory {
public:
    void setFile(string name, string path, int i);
    string readFile(string name);
    void writeToIndexlog(string name, string path, string isFile, int cloneObj);
    FileFactory();
private:
    string name;
    string path;
};


FileFactory::FileFactory(void) {}

void FileFactory::setFile(string name, string path, int i) {
    name = name;
    path = path;

    if(!boost::filesystem::exists(".fvc/objects/" + name)) {

        cout << "file found at" << path << endl;

    }
}

void FileFactory::writeToIndexlog(string name, string path, string isFile, int cloneObj) {


    try
    {
        ofstream indexLog;
        indexLog.open(".fvc/index.log", ios_base::app); // ios_base:app flag use to append text to file

        indexLog << cloneObj << " " << isFile << " " <<  path << " " << name << endl;            
        
    }
    catch (filesystem_error &e)
    {
        std::cerr << e.what() << '\n';
    }

}

int main() {
    FileFactory file;
    
    int currentCloneObject = createCloneObject(to_string(readlastLine()));
    
    int i = 0;
    for ( boost::filesystem::recursive_directory_iterator end, dir("."); dir != end; ++dir ) {

        /*
         * Remove .fvc folder and a.out while directory iteratting
         */

        if(dir->path().filename().native() == ".fvc") {

            dir.no_push();

        }

        /*
         * use post fix i to count index
         */

        i++;

        /*
         * use setFile function to set Filename and the path
         */
        file.setFile(
            dir->path().filename().native(),
            dir->path().native(),
            i
        );

        /*
         * Check if the file is_directory or a regular file.
         * direcoty::D regular_file::R
         */

        string isFile, inFile;

        if(is_regular_file(*dir)){ 
            isFile = 'R';
            inFile = file_get_contents(dir->path().native());
            
        // Clonning files while adding to index.log 
        
        createCloneOfIndexFiles(currentCloneObject, dir->path().filename().native(), inFile);
        
        }
        else if(is_directory(*dir))
            isFile = 'D';

        /*
         * Let's lookup for the index. use an Id to ref file structure.
         */

        file.writeToIndexlog(dir->path().filename().native(), dir->path().native(), isFile, currentCloneObject);
        


    }
}
