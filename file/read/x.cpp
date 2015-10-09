#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <vector>

using namespace std;
using namespace boost::filesystem;

vector<string> files;
vector<string> directories;

int main()
{
	for ( boost::filesystem::recursive_directory_iterator end, dir("."); dir != end; ++dir ) {

		if(is_directory(*dir)){	
		       cout << "D " << *dir << endl;                                    	
		}
		else if(is_regular_file(*dir)){	
		       cout << "F " << *dir << endl;                                    	
		}
	}
}
