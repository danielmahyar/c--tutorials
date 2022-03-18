#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

const int WIDTH {20};
const int HEIGHT {20};

enum GameState {
	GOING,
	DONE,
	SETUP,
	EXIT
};

GameState state {SETUP};

enum PlayerState {
	EXPLORING,
	FIGHTING,
	SPOTTED,
	FLEEING,
	DEAD
};

struct Coordinates {
	int x, y;

	public:
		Coordinates(int x, int y) : x(x), y(y) {};
		~Coordinates() {};
		int get_x() const { return x; }
		int get_y() const { return y; }

		void set_x(int x) { this->x = x; }
		void set_y(int y) { this->y = y; }

		bool operator== (const Coordinates &rhs) const {
			return this->x == rhs.get_x() && this->y == rhs.get_y();
		};
};

class GameObject {
	private:
		int x, y, health, view_radius;

	public:
		GameObject(int x, int y, int health, int view_radius) : x(x), y(y), health(health),view_radius{view_radius} {};

		int get_x() const { return x; }
		int get_y() const { return y; }
		int get_health() const { return health; }

		void set_x(const int &x) { this->x = x; }
		void set_y(const int &y) { this->y = y; }
		void set_health(const int &health) { this->health = health; }

		vector<Coordinates> get_view_coordinates() {
			vector<Coordinates> temp {};
			for (int i {0}; i < view_radius; ++i) {
				Coordinates tl {x - i, y + i};
				Coordinates t {x, y + i};
				Coordinates tr {x + i, y + i};
				Coordinates r {x + i, y};
				Coordinates br {x + i, y - i};
				Coordinates b {x, y - i};
				Coordinates bl {x - i, y - i};
				Coordinates l {x - i, y};

				temp.push_back(tl);
				temp.push_back(t);
				temp.push_back(tr);
				temp.push_back(r);
				temp.push_back(br);
				temp.push_back(b);
				temp.push_back(bl);
				temp.push_back(l);
			}
			return temp;
		}
};

class Player : public GameObject {
	private:
		string name;
	public:
		Player(string name, int x, int y, int health, int view_radius) : GameObject(x, y, health, view_radius), name(name) {};
		void pick_up_item() {}

		string get_name() { return name; }
};

class Enemy : public GameObject {
	public:
		Enemy(int x, int y, int health, int view_radius) : GameObject(x, y, health, view_radius) {};
		void pick_up_item() {}
};
class Map {
	private:
		int width, height;
	public:
		Map(int width, int height) : width(width), height(height) {}

		int get_width() const { return width; }
		int get_height() const { return height; }

};

class Handler {
	private:
		vector<shared_ptr<GameObject>> objects;
		PlayerState player_state {EXPLORING};
		shared_ptr<Map> map;
		shared_ptr<GameObject> enemy_to_fight;
	public:
		Handler(shared_ptr<Map> map) : map(map) {};
		~Handler() {};

		vector<shared_ptr<GameObject>> get_objects() const { return objects; }
		void put_object(shared_ptr<GameObject> &obj) { objects.push_back(obj); }

		void handle_player_explore(shared_ptr<Player> &player) {
			const int player_x = player->get_x();
			const int player_y = player->get_y();
			const int map_width = map->get_width();
			const int map_height = map->get_height();


			if(player_x < 0 || player_y < 0 || player_x > map_width || player_y > map_height){
				cout << "You fell off the map." << endl;
				state = DONE;
				return;
			}

			if(player_x == map_width || player_y == map_height || player_x == 0 || player_y == 0){
				cout << "You have reached the end of the map." << endl;
				cout << "Proceeding will make you fall of the map. " << endl;
			}

			cout << "You are in (" << player_x << "," << player_y << ")" << endl;
			cout << "What would you like to do?" << endl;

			char option;
			cin >> option;

			switch(option){
				case 'W':
				case 'w':
					player->set_y(player_y + 1);
					cout << "You walked forward" << endl;
					break;
				case 'S':
				case 's':
					player->set_y(player_y - 1);
					cout << "You walked backward" << endl;
					break;
				case 'D':
				case 'd':
					player->set_x(player_x + 1);
					cout << "You walked backward" << endl;
					break;
				case 'A':
				case 'a':
					player->set_x(player_x - 1);
					cout << "You walked backward" << endl;
					break;
			}
		}

		void handle_player_spot(shared_ptr<Player> &player){
			cout << "Would you like to start a fight? (y/n)" << endl;
			char option;
			cin >> option;

			switch(option){
				case 'y':
					cout << "You have chosen to fight" << endl;
					player_state = FIGHTING;
					break;
				case 'n':
					cout << "You have chosen to leave" << endl;
					player->set_x(player->get_x() - 1);
					player->set_y(player->get_y() + 1);
					player_state = EXPLORING;
					break;
			}

		}

		void handle_player_combat(shared_ptr<Player> &player){
			cout << "Your health is: " << player->get_health() << endl;
			cout << "The enemy's health is " << this->enemy_to_fight->get_health() << endl;

			cout << "Your attack damage is 120AD" << endl;

			this->enemy_to_fight->set_health(this->enemy_to_fight->get_health() - 120);

			if(this->enemy_to_fight->get_health() < 100) {
				cout << "The enemy is dead." << endl;
				this->enemy_to_fight->set_health(0);
				player_state = EXPLORING;
			} 

		}

		PlayerState handle_player_state(shared_ptr<Player> &player) {
			if(player_state == FIGHTING) return player_state;
			Coordinates player_cor {player->get_x(), player->get_y()};
			for (auto &obj : objects){
				if(obj->get_health() <= 0) continue;
				for(auto &coor : obj->get_view_coordinates())
					if(coor == player_cor) {
						cout << player->get_name() << " can see a monster" << endl;
						this->enemy_to_fight = obj;
						this->player_state = SPOTTED;
						return player_state;
					}
			}
			player_state = EXPLORING;
			return player_state;
		}
};

int main () {
	shared_ptr<Map> m { new Map(20, 20) };
	Handler handler = Handler(m);
	shared_ptr<Player> player { new Player("Daniel", static_cast<int>(roundf(WIDTH / 2)), 2, 100, 4) };
	shared_ptr<GameObject> enemy { new Enemy(1, 2, 100, 4) };
	shared_ptr<GameObject> enemy2 { new Enemy(20, 20, 200, 6) };

	cout << enemy->get_health();

	handler.put_object(enemy);
	handler.put_object(enemy2);


	state = GOING;

	do{
		system("CLS");
		switch(
			handler.handle_player_state(player)
		){
			case EXPLORING:
				handler.handle_player_explore(player);
				break;
			case SPOTTED:
				handler.handle_player_spot(player);
				break;
			case FIGHTING:
				handler.handle_player_combat(player);
				break;
			case DEAD:
				state = DONE;
				break;
		}

	} while(state == GOING);

	do{
		cout << "You are dead." << endl;
		char option;
		cin >> option;
		state = EXIT;
	} while(state == DONE);

	return 0;
}
