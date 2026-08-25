#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class bigint
{
	private:
		std::vector<int>	digits;

		void	normalize();
		size_t	to_size_t() const;

	public:
		bigint();
		bigint(unsigned long long n);
		bigint(const bigint &src);
		bigint&	operator=(const bigint &src);
		~bigint();

		bigint&	getDigits();
		bigint	operator();

		bigint&	operator++();
		bigint	operator++(int);
		bigint	operator+(const bigint &rhs) const;
		bigint&	operator+=(const bigint &rhs);
		bigint&	operator<<=(size_t n);
		bigint	operator<<(size_t n);
		bigint&	operator>>=(const bigint &n);
		bigint	operator>>(const bigint &n);


};

std::ostream&	operator<<(std::ostream& os, const bigint &b);

#endif
