#include <iostream>
#include <memory>
#include <string>
#include "GameObject.hpp"
#include "Player.hpp"
using namespace std;

int main() {
	unique_pt<GameObject> test{ new Player("Daniel") };

	return 0;
}