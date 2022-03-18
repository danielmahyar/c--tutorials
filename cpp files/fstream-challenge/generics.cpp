#include <iostream>
#include <string>

class Human {
	private:
		std::string name;
		int value;
		static int count;
	public:
		Human(){
			count++;
		};
		~Human();
		static int get_count(){
			return count;
		}
};


int main(){
	Human h {};
	Human h1 {};

	std::cout << Human::get_count();

	return 0;
}