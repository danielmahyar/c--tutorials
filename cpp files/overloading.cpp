#include <cstring>
#include <iostream>
using namespace std;

class Mystring{
	private:
		char *str;
	public:
		Mystring();
		Mystring(const char *str);
		Mystring(const Mystring &source);
		~Mystring();
		void display() const;
		int get_length() const;
		const char *get_str() const;
};

Mystring::Mystring() : str{nullptr}{
	str = new char[1];
	*str = '\0';
}

Mystring::Mystring(const char *s) : str{nullptr}{
	cout << s << endl;
	if(s == nullptr){
		str = new char[1];
		*str = '\0';
	} else {
		char test[5] = "Test";
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

Mystring::Mystring(const Mystring &source) : str{nullptr}{
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

Mystring::~Mystring(){
	delete [] str;
}

void Mystring::display() const {
	cout << str << ":" << get_length() << endl;
}

int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

int main(){
	Mystring empty;
	char larryChar[6] = {"Larry"};
	char *ptr = {larryChar};

	cout << *ptr << endl;

	Mystring larry("ptr");
	Mystring stooge {larry};

	empty.display();
	larry.display();
	stooge.display();


	return 0;
}