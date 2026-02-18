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

bigint::bigint(unsigned long long n){
	if (n == 0)
		digits.push_back(0);
	else{
		while (n)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
	}
}

bigint::bigint(const bigint& other){
	digits = other.digits;
}

bigint::~bigint(){}

bigint&	bigint::operator=(const bigint& other){
	digits = other.digits;
	return (*this);
}

bigint	bigint::operator+(const bigint& rhs) const{
	bigint	result;
	result.digits.clear();

	int	carry = 0;
	size_t	maxlen = std::max(digits.size(), rhs.digits.size());
	for (size_t i = 0; i < maxlen || carry; ++i)
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

bigint&	bigint::operator++(){
	*this += 1;
	return (*this);
}

bigint	bigint::operator++(int){
	bigint tmp(*this);
	++*this;
	return (tmp);
}

bigint	bigint::operator<<(size_t n) const{
	if (*this == 0)
		return (*this);
	
	bigint	r(*this);
	r.digits.insert(r.digits.begin(), n, 0);
	return (r);
}

bigint&	bigint::operator<<=(size_t n){
	if (*this == 0)
		return (*this);
	digits.insert(digits.begin(), n, 0);
	return (*this);
}

bigint	bigint::operator>>(const bigint& n) const{
	bigint	r(*this);
	r >>= n;
	return (r);
}

bigint&	bigint::operator>>=(const bigint& n){
	size_t	shift = n.to_size_t();

	if (shift >= digits.size())
	{
		digits.assign(1, 0);
		return (*this);
	}
	digits.erase(digits.begin(), digits.begin() + shift);
	normalize();
	return (*this);
}

bool	bigint::operator<(const bigint& rhs) const{
	if (digits.size() != rhs.digits.size())
		return (digits.size() < rhs.digits.size());
	for (int i = digits.size() - 1; i >= 0; --i){
		if (digits[i] != rhs.digits[i])
			return (digits[i] < rhs.digits[i]);
	}
	return false;
}

bool	bigint::operator<=(const bigint& rhs) const{
	return (!(*this > rhs));
}

bool	bigint::operator>(const bigint& rhs) const{
	return (rhs < *this);
}

bool	bigint::operator>=(const bigint& rhs) const{
	return (!(*this < rhs));
}

bool	bigint::operator==(const bigint& rhs) const{
	return (digits == rhs.digits);
}

bool	bigint::operator!=(const bigint& rhs) const{
	return (!(*this == rhs));
}

const std::vector<int>	bigint::getDigits() const{
	return (digits);
}

std::ostream&	operator<<(std::ostream& os, const bigint& b){
	const std::vector<int>&	d = b.getDigits();

	for (int i = d.size() - 1; i >= 0; i--)
		os << d[i];

	return (os);
}
