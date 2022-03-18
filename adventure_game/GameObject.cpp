#include "GameObject.hpp"

GameObject::GameObject(string name = "", int health = 100, int x = 0, int y = 0, int velX = 1, int velY = 1, ObjectID id = enemy)
	: name{name}, health{health}, x{x}, y{y}, velX{velX}, velY{velY}, id{id} 
{};

void GameObject::attack(){
	cout << "Gameobject is attacking" << endl;
}