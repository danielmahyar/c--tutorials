#ifndef __PLAYER_H_
#define __PLAYER_H_
#include <string>
#include <iostream>
#include "GameObject.hpp"
#include "ObjectID.hpp"
using namespace std;



class Player: public GameObject {
	public:
		Player(string name, int health, int x, int y, int velX, int velY, ObjectID id);
		virtual void attack() override;
};

#endif