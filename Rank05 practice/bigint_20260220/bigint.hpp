#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class	bigint{
	private:
		std::vector<int>	digits;

		void	normalize();
		size_t	to_size_t() const;
	public:
		bigint();
		bigint(const bigint& other);
		bigint(unsigned long long n);
		bigint&	operator=(const bigint& other);
		~bigint();

		const std::vector<int>&	getDigits() const;

		bigint	operator+(const bigint& rhs) const;
		bigint&	operator+=(const bigint& rhs);
		bigint	operator++(int);
		bigint&	operator++();
		bool	operator==(const bigint& other) const;
		bigint	operator<<(size_t n) const;

};

std::ostream&	operator<<(std::ostream& os, const bigint& b);

#endif