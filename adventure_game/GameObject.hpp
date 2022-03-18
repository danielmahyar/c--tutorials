#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_
#include <string>
#include <iostream>
#include "ObjectID.hpp"
using namespace std;


class GameObject {
	private:
		int health, x, y, velX, velY;
		string name;
		ObjectID id;
	public:
		GameObject(string name, int health, int x, int y, int velX, int velY, ObjectID id);

		virtual void attack();
		virtual ~GameObject() { };

};

#endif