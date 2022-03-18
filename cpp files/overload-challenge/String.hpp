#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
using namespace std;

class String {
	private:
		char *string;
	public:
		String();
		String(const char *string);
		String(const String &);
		String(String &&);
		~String();

		//Methods
		const void display();

		//Operator overloading:
		String &operator= (const String &rhs);
		String &operator= (String &&rhs);
		String operator+ (const String &rhs);
		String &operator+= (const char *string);
		String &operator*= (int &&);
		String &operator++ ();
		String operator++ (int);
		String &operator-- ();
		bool operator== (const String &rhs);
		bool operator!= (const String &rhs);
		bool operator< (const String &rhs);
		bool operator> (const String &rhs);

		friend istream &operator>>(istream &, String &);
		friend ostream &operator<< (ostream &os, const String &);



};

#endif