#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0){};

vect2::vect2(int x, int y) : _x(x), _y(y){};

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y){};

vect2&	vect2::operator=(const vect2& other){
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

vect2::~vect2(){
	std::cout << "Destructed" << std::endl;
}

vect2	vect2::operator+(const vect2& other) const {
	return (vect2(_x + other._x, _y + other._y));
}

vect2&	vect2::operator+=(const vect2& other){
	_x += other._x;
	_y += other._y;
	return (*this);
}

vect2&	vect2::operator++(){
	++_x;
	++_y;
	return (*this);
}

vect2	vect2::operator++(int){
	vect2	old(*this);

	_x++;
	_y++;
	return (old);
}

vect2	vect2::operator-(const vect2& other) const {
	return (vect2(_x - other._x, _y - other._y));
}

vect2&	vect2::operator-=(const vect2& other){
	_x -= other._x;
	_y -= other._y;
	return (*this);
}

vect2&	vect2::operator--(){
	--_x;
	--_y;
	return (*this);
}

vect2	vect2::operator--(int){
	vect2	old(*this);

	_x--;
	_y--;
	return (old);
}

vect2	vect2::operator*(int scalar) const {
	return (vect2(_x * scalar, _y * scalar));
}

vect2&	vect2::operator*=(int scalar){
	_x *= scalar;
	_y *= scalar;
	return (*this);
}

int&	vect2::operator[](int index){
	if (index == 0)
		return (_x);
	return (_y);
}

int const&	vect2::operator[](int index) const {
	if (index == 0)
		return (_x);
	return (_y);
}

std::ostream&	operator<<(std::ostream& out, const vect2& vector){
	out << "{" << vector._x << "," << vector._y << "}";
	return (out);
}