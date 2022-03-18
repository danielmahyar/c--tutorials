#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Player.hpp"
using namespace std;

class Enemy : private Player{
	using Player::Player;
	private:
		int moreData;
	public:
		const void talk();
}; 

#endif