#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const size_t WIDTH {40};
const string TITLE {"Scores"};
const string AVERAGE {"AVERAGE"};
int title_length = TITLE.length();

int main() {

	ifstream response_file {"responses.txt"};

	if(!response_file){
		cout << "No response file" << endl;
		return 1;
	}

	//Get correct code for grading
	string correct_code;
	vector <int> student_scores {};
	getline(response_file, correct_code);

	cout << setw((WIDTH - title_length) / 2) << "" << TITLE << endl;
	cout << setw(WIDTH) << setfill('-') << "" << endl;
	cout << setfill(' ');

	while(!response_file.eof()){
		string student_name {}; 
		string student_answer {}; 
		int student_score {0};
		getline(response_file, student_name);
		getline(response_file, student_answer);

		for(int i {0}; i < student_answer.length(); i++)
			(student_answer.at(i) == correct_code.at(i)) ? student_score++ : student_score;
		student_scores.push_back(student_score);
	
		cout << setw(WIDTH) << left << student_name << right << student_score << endl;
	}

	int summed_score {0};
	for(auto &student_score : student_scores)
		summed_score += student_score;
	double average = static_cast<double>(summed_score) / student_scores.size();
	cout << setw(WIDTH) << setfill('-') << "" << endl;
	cout << setprecision(2) << setfill(' ');
	cout << setw(WIDTH)  << left << AVERAGE << right << average << endl;

	response_file.close();
	

	return 0;
}