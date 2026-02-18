#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class	bigint
{
private:
	std::vector<int>	digits;

	void	normalize();
	size_t	to_size_t() const;

public:
	bigint();
	bigint(unsigned long long n);
	bigint(const bigint& other);
	~bigint();

	bigint&	operator=(const bigint& other);

	bigint	operator+(const bigint& rhs) const;
	bigint&	operator+=(const bigint& rhs);

	bigint&	operator++();
	bigint	operator++(int);

	bigint	operator<<(size_t n) const;
	bigint&	operator<<=(size_t n);
	bigint	operator>>(const bigint& n) const;
	bigint&	operator>>=(const bigint& n);

	bool	operator<(const bigint& rhs) const;
	bool	operator<=(const bigint& rhs) const;
	bool	operator>(const bigint& rhs) const;
	bool	operator>=(const bigint& rhs) const;
	bool	operator==(const bigint& rhs) const;
	bool	operator!=(const bigint& rhs) const;

	const std::vector<int>	getDigits() const;
};

std::ostream&	operator<<(std::ostream& os, const bigint& b);

#endif