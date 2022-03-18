#include "Player.hpp"


Player::Player(string name = "", int health = 100, int x = 0, int y = 0, int velX = 1, int velY = 1, ObjectID id = player)
	: GameObject(name, health, x, y, velX, velY, id)
{};

void Player::attack() {
	cout << "attack" << endl;
}

