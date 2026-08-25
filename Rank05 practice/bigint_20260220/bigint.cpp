#include "bigint.hpp"


void	bigint::normalize(){
	while (digits.size() > 1 && digits.back() == 0)
		digits.pop_back();
}

size_t	bigint::to_size_t() const{
	size_t	result = 0;

	for (int i = digits.size() - 1; i >= 0; --i)
		result = result * 10 + digits[i];
	return (result);
}

bigint::bigint(){
	digits.push_back(0);
}

bigint::bigint(const bigint& other) : digits(other.digits){}

bigint::bigint(unsigned long long n){
	if (n == 0)
		digits.push_back(0);
	else
	{
		while (n)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
	}
}

bigint&	bigint::operator=(const bigint& other){
	if (this != &other)
		digits = other.digits;
	return (*this);
}

bigint::~bigint(){}

const std::vector<int>&	bigint::getDigits() const{
	return (digits);
}

std::ostream&	operator<<(std::ostream& os, const bigint& b){
	std::vector<int>	d = b.getDigits();
	for (int i = d.size() - 1; i >= 0; --i)
		os << d[i];
	return (os);
}

bigint	bigint::operator+(const bigint& rhs) const{
	bigint result;
	result.digits.clear();

	int	carry = 0;
	size_t	maxlen = std::max(digits.size(), rhs.digits.size());
	for (size_t i = 0; i < maxlen || carry; i++)
	{
		int sum = carry;
		if (i < digits.size())
			sum += digits[i];
		if (i < rhs.digits.size())
			sum += rhs.digits[i];
		result.digits.push_back(sum % 10);
		carry = sum / 10;
	}

	return (result);
}

bigint&	bigint::operator+=(const bigint& rhs){
	*this = *this + rhs;
	return (*this);
}

bigint	bigint::operator++(int){
	bigint	tmp(*this);
	++(*this);
	return (tmp);
}

bigint&	bigint::operator++(){
	*this += 1;
	return (*this);
}

bool	bigint::operator==(const bigint& other) const{
	return (digits == other.digits);
}

bigint	bigint::operator<<(size_t n) const{
	if (*this == 0)
		return (*this);
	bigint r(*this);
	r.digits.insert(r.digits.begin(), n, 0);

	return (r);
}
