#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <iostream>
using namespace std;

class Player {

	private:
		int health;
		string name;		
	public:
		Player() : health{0}, name{"test"} { cout << "Default constructor" << endl; };
		Player(int, string);
		Player(string &);
		~Player();

		const string getName(){ return name; };
		const int getHealth(){ return health; }; 

		void attack();


};

#endif