#include <iostream>
using namespace std;

int main(){

	const double smallRoomPrice {25.0};
	const double largeRoomPrice {35.0};
	const double taxRate {0.06};
	const short int expirationDays {30};

	cout << "Welcome to Vocast Hotels!" << endl;

	cout << "Enter the amount of small rooms: ";
	short int smallRooms {0};
	cin >> smallRooms;

	cout << "Enter the amount of large rooms: ";
	short int largeRooms {0};
	cin >> largeRooms;

	const double roomCost {(smallRooms * smallRoomPrice) + (largeRooms * largeRoomPrice)};

	cout << "\nEstimate for carpet cleaning service:" << endl;
	cout << "Number of small rooms: " << smallRooms << endl;
	cout << "Number of large rooms: " << largeRooms << endl;
	cout << "Price per small room: $" << smallRoomPrice << endl;
	cout << "Price per large room: $" << largeRoomPrice << endl;
	cout << "Cost: $" << roomCost << endl;
	cout << "Tax: $" << roomCost * taxRate << endl;

	cout << "=======================" << endl;
	cout << "Total estimate: $" << roomCost * (1 + taxRate) << endl;
	cout << "This estimate is valid for " << expirationDays << " days";


	return 0;
}