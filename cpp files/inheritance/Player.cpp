#include <iostream>
#include "Player.hpp"


Player::Player(int health = 100, string name = "none") : health{health}, name{name}{

}

Player::Player(string &name) : Player(0, name) {}

Player::~Player(){

}

void Player::attack(){
	cout << "Player " << name << " is attacking" << endl;
}