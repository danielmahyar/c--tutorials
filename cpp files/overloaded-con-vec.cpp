#include <iostream>
#include <vector>
using namespace std;

class Vector2d {
	private:
		double *x, *y;
	public:
		Vector2d(double x = 0, double y = 0);
		Vector2d(const Vector2d &source);
		Vector2d(Vector2d &&move);
		~Vector2d();
		void display () const;
		Vector2d &operator= (const Vector2d &rhs);
		Vector2d &operator= (Vector2d &&rhs);
		bool operator == (const Vector2d &rhs) const;
		Vector2d operator + (Vector2d const &);
		friend Vector2d operator - (Vector2d const &, Vector2d const &);
		friend Vector2d operator * (Vector2d const &, Vector2d const &);
		friend Vector2d operator * (Vector2d const &, int &&);
};

//Constructor 2 args and used for delagation
Vector2d::Vector2d(double x, double y) : x{new double(x)}, y{new double(y)}{
}

//Copy assignment
Vector2d &Vector2d::operator=(const Vector2d &rhs){
	cout << "Using copy assignment" << endl;
	if(this == &rhs)
		return *this;
	
	delete x;
	delete y;
	
	x = new double(*rhs.x);
	y = new double(*rhs.y);

	return *this;
}

//Move assignment
Vector2d &Vector2d::operator=(Vector2d &&rhs){
	cout << "Using move assignment" << endl;
	if(this == &rhs)
		return *this;

	delete x;
	delete y;

	x = new double(*rhs.x);
	y = new double(*rhs.y);

	rhs.x = nullptr;
	rhs.y = nullptr;

	return *this;
}
//Copy constructor
Vector2d::Vector2d(const Vector2d &source){
	cout << "Copy constructur" << endl;
	this->x = new double(*source.x);
	this->y = new double(*source.y);
}

//Move constructor
Vector2d::Vector2d(Vector2d &&move){
	cout << "Move constructor" << endl;
	x = move.x;
	y = move.y;

	move.x = nullptr;
	move.y = nullptr;
}

//Destructor
Vector2d::~Vector2d(){
	cout << "Destructor" << endl;
	delete x;
	delete y;
}

void Vector2d::display() const{
	cout << "Vector: (" << *x << ", " << *y << ")" << endl;
}

Vector2d Vector2d::operator+ (Vector2d const &rhs){
	return Vector2d(*x + *(rhs.x), *y + *(rhs.y));
}
Vector2d operator - (Vector2d const &vec1, Vector2d const &vec2){
	return Vector2d(*(vec1.x) - *(vec2.x), *(vec1.y) - *(vec2.y));
}

Vector2d operator * (const Vector2d  &vec1, Vector2d const &vec2){
	return Vector2d(*(vec1.x) * *(vec2.x), *(vec1.y) * *(vec2.y));
}

Vector2d operator * (Vector2d const &vec1, int &&scalar){
	return Vector2d(*(vec1.x) * scalar, *(vec1.y) * scalar);
}

bool Vector2d::operator== (const Vector2d &rhs) const {
	const bool xSame = (*x == *(rhs.x));
	const bool ySame = (*y == *(rhs.y));

	if(xSame && ySame)
		return true;
	else
		return false;

}

int main(){
	vector<Vector2d> vectors {};

	Vector2d vec1(2, 6), vec2(5,6);
	Vector2d vec3 = vec1 + vec2 + vec2;
	vec1.display();
	vec2.display();
	vec3.display();

	vectors.push_back(vec1);
	vectors.push_back(vec2);
	vectors.push_back(Vector2d(3, 6));

	for(Vector2d vector : vectors)
		vector.display();
	
	vec1 = vec2 * 2;

	if(vec1 == vec2)
		cout << "Vector 1 and 2 are the same" << endl;
	else
		cout << "Vector 1 and 2 are different" << endl;

	return 0;
}