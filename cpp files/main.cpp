#include <iostream>
#include <vector>
using namespace std;

void printGuestList(const string&, const string&, const string&);
void clearGuestList(string&, string&, string&);
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int q {0};
	for(size_t i {0}; i < array.size(); i++){
		if(q == sequence.size())
			return true;
		if(array.at(i) == sequence.at(q))
			q++;
	}
	if(q == sequence.size())
		return true;
	else
		return false;
}
int main(){
	isValidSubsequence(vector<int>{5, 1, 22, 25, 6, -1, 8, 10}, vector<int>{1, 6, -1, 10});


	return 0;
}

void printGuestList(const string &guest_1, const string &guest_2, const string &guest_3){
	cout << "Guest 1: " << guest_1 << endl;
	cout << "Guest 2: " << guest_2 << endl;
	cout << "Guest 3: " << guest_3 << endl;
}

void clearGuestList(string &guest_1, string &guest_2, string &guest_3){
	guest_1 = guest_2 = guest_3 = " ";
}
