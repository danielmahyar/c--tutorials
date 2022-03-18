#include <iostream>
#include <vector>
#include "String.hpp"
using namespace std;

int main(){
	vector<String> names;
	String daniel {"Danielddddddddddddddddddddd"};
	String larry {"Larry"};

	String larryAndDaniel = daniel + larry;

	daniel++;
	daniel *= 2;
	
	cout << "Testing " << endl;
	cout << daniel << endl;
	
	return 0;
}