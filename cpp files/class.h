#include <string>
using namespace std;

class Account {
	private:
		string name {"Daniel"};
		int balance {100};
	public:
		void setName(string name){
			this->name = name;
		}
		
		int currentBalance(){
			return this->balance;
		}
};