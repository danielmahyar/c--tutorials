#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec {1, 2, 3};

	int result {0};
	
	for (int i = 0; i < vec.size(); i++){
		for (int j = i + 1; j < vec.size(); j++){
			result += vec.at(i) * vec.at(j);
		}
	}

	cout << result << endl;

	return 0;
}