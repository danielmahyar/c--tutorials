#include <iostream>
using namespace std;

int main(){
	int scores[] {100, 95, 78};
	int *p {scores};

	cout << "Should print the same: " << endl;
	cout << *(scores + 2) << " " << *(p + 2);

	return 0;
}