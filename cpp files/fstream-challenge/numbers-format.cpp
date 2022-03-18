#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const string FILENAME {"romeojuliet.txt"};
const int SPACING {20};


void check_file(const ifstream &file){
	if(!file){
		cerr << "Error opening file" << endl;
	}
}

void check_file(const ofstream &file){
	if(!file){
		cerr << "Error making file" << endl;
	}
}

int main(){
	long unsigned int line_counter {0};
	string line;
	ifstream file_read {"romeojuliet.txt"};
	ofstream file_write {"(formatted) " + FILENAME};
	check_file(file_read);
	check_file(file_write);

	while(getline(file_read, line)){
		cout << line << endl;
		if(line.length() == 0)
			file_write << line << endl;
		else {
			++line_counter;
			file_write << line_counter << endl;
			// file_write << line_counter << setw(SPACING - to_string(line_counter).length()) << "" << line << endl;
		}
	}

	cout << "Copying done" << endl;

	file_read.close();
	file_write.close();

	return 0;
}