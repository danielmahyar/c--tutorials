#include <iostream>
#include <string>
#include "Player.hpp"
#include "Enemy.hpp"
int main(){

	string name = {"Test"};

	Player test {100, name};
	test.attack();

	Enemy enemy;
	enemy.talk();

	return 0;
}