#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <ostream>
#include <exception>

class vect2
{
public:
	int	_x;
	int	_y;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2&	operator=(const vect2& other);
	~vect2();

	vect2		operator+(const vect2& other) const;
	vect2&		operator+=(const vect2& other);
	vect2&		operator++();
	vect2		operator++(int);
	vect2		operator-(const vect2& other) const;
	vect2&		operator-=(const vect2& other);
	vect2&		operator--();
	vect2		operator--(int);
	vect2		operator*(int scalar) const;
	vect2&		operator*=(int scalar);
	int&		operator[](int index);
	int const&	operator[](int index) const;
};

	std::ostream&	operator<<(std::ostream& out, const vect2& vector);

#endif