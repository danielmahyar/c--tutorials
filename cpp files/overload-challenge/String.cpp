#include <iostream>
#include <cstring>
#include "String.hpp"
using namespace std;

//Default constructor
String::String() : string{nullptr}{
	string = new char[1];
	*string = '\0';
}

//Default constructor
String::String(const char *str) : string{nullptr}{
	if(str == nullptr)
		string = new char[1]{'\0'};
	else {
		string = new char[strlen(str) + 1];
		strcpy(string, str);
	}
}

//Copy constructor
//!REMEMBER DEEP COPY
String::String(const String &source){
	cout << "Copy constructor" << endl;
	string = new char[strlen(source.string) + 1];
	strcpy(string, source.string);
}

//Move constructor
String::String(String &&move){
	cout << "Move constructor" << endl;
	string = move.string;
	move.string = nullptr;
}

//Deconstructor
String::~String(){
	delete [] string;

}


//Methods
const void String::display(){
	cout << *this << endl;
}



//Operator overloading

String &String::operator=(const String &rhs){
	if(this == &rhs)
		return *this;
	
	delete string;
	string = new char[strlen(rhs.string) + 1];
	strcpy(string, rhs.string);

	return *this;
}

String &String::operator=(String &&rhs){
	if(this == &rhs)
		return *this;
	delete [] string;
	string = new char[strlen(rhs.string) + 1];
	strcpy(string, rhs.string);
	rhs.string = nullptr;
	return *this;
}

String String::operator+(const String &rhs){
	char *temp = new char[strlen(string) + 1];
	strcpy(temp, string);
	strcat(temp, rhs.string);
	return String(temp);
}

String &String::operator+=(const char *string){
	strcat(this->string, string);
	return *this;
}

String &String::operator*=(int &&i){
	char *temp = new char[strlen(string) + 1];
	strcpy(temp, string);
	for (size_t j {0}; j < i; j++)
		strcat(temp, string);
	strcpy(string, temp);
	return *this;
}

String &String::operator++(){
	for (size_t i = 0; i < strlen(string); i++)
		string[i] = toupper(string[i]);

	return *this;
}

String String::operator++(int){ //Pre
	String temp{*this};
	operator++();
	return temp;
}

bool String::operator==(const String &rhs){
	return strcmp(string, rhs.string);
}

bool String::operator!=(const String &rhs){
	return !strcmp(string, rhs.string);
}

bool String::operator<(const String &rhs){
	if(strcmp(string, rhs.string) == -1)
		return true;
	else
		return false;
}

bool String::operator>(const String &rhs){
	if(strcmp(string, rhs.string) == 1)
		return true;
	else
		return false;
}

istream &operator>>(istream &in, String &rhs){
	char *temp = new char[1000];
	in >> temp;
	rhs = String{temp};
	delete [] temp;
	return in;
}

ostream &operator<<(ostream &os, const String &rhs){
	os << rhs.string << endl;

	return os;
}