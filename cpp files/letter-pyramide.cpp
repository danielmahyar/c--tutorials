#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input{};
	cout << "Welcome - Enter your numbers or characters here: ";
	getline(cin, input);

	/*
		1) Iterate over all characters
		2) Use position (index) to iterate up
		3) After deiterate given position i
	*/
	for (int i{0}; i < input.length(); i++)
	{
		for (int space{i}; space < input.length(); space++)
			cout << " ";

		for (int j{0}; j <= i; j++)
			cout << input[j];

		for (int k{i}; k > 0; --k)
			cout << input[k - 1];

		cout << endl;
	}

	return 0;
}