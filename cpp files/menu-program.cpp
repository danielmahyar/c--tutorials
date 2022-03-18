#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm> // std::min_element

using namespace std;

void displayMenu();
char readInput(const char);
bool hasData(vector<int>&);

int main(){
	bool quit {false};
	char choice {};
	vector<int> numbers {};

	while(!quit){
		displayMenu();

		cout << "\nEnter your choice: ";
		cin >> choice;
		choice = readInput(choice);

		switch(choice){
			case 'P':
				if(numbers.size() == 0){
					cout << "[] - the list is empty" << endl; 
					break;
				} else {
					string numToString {"["};

					for (auto num : numbers){
						numToString += " " + to_string(num);
					}

					cout << numToString + " ]"<< endl << endl;
					break;
				}
			case 'A':
				{
					int num {0};
					cout << "Enter a number to enter: ";
					cin >> num;
					numbers.push_back(num);
					cout << "\n" << numbers.at(numbers.size() - 1) << " added" << endl;
					break;
				}
			case 'M':
				{
					if(numbers.size() == 0){
						cout << "Unable to calculate mean - no data" << endl;
						break;
					} else {
						int sum {0};
						for (auto num : numbers){
							sum += num;
						}

						cout << "Mean value is: " << static_cast<double>(sum) / numbers.size() << endl;
						break;
					}
				}
			case 'S':
				{
					if(numbers.size() == 0){
						cout << "Unable to find smallest value- no data given" << endl;
						break;
					} else {
						int minVal = *min_element(numbers.begin(), numbers.end());
						cout << "The smallest number is: " << minVal << endl;
						break;	
					}
				}
			case 'L':
				{
					if(numbers.size() == 0){
						cout << "Unable to find largest value - no data given" << endl;
						break;
					} else {
						int maxVal = *max_element(numbers.begin(), numbers.end());
						cout << "The largest number is: " << maxVal << endl;
						break;
					}
				}
				break;
			case 'Q':
				quit = true;
				break;
		}
	}


	return 0;
}


void displayMenu(){
	cout << "P - Print numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "M - Display mean of the numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "Q - Quit" << endl;
}

char readInput(const char input){
	return toupper(input);
}