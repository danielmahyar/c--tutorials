#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


int main(){
	string word_search;
	long signed int word_counter = 0;
	long signed int word_search_found = 0;

	ifstream file {"romeojuliet.txt"};
	ofstream file_out {"found.txt"};
	if(!file) return 1;
	if(!file_out) return 1;

	cout << "What word do you want to search for?: ";
	cin >> word_search;

	string word;
	while(file >> word){
		++word_counter;
		if(word.find(word_search) != string::npos){
			++word_search_found;
			file_out << word << endl;
			cout << word << " ";
		}
	}

	cout << endl << "Found the substring: " << word_search << " this many times: " << word_search_found << endl;
	cout << "I searched through " << word_counter << " words";

	file.close();
	return 0;
}