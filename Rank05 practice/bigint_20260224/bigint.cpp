#include "bigint.hpp"

bigint::bigint() : digits.push_back(0) {}

bigint::bigint(unsigned long long n){
	if (n == 0)
		digits.push_back(0);
	for (size_t i = 0; i < n.size(); i++)
	{
		digits.push_back(n % 10);
		n /= 10;
	}
}

void	bigint::normalize(){
	while (digits && digits.back() == 0)
		digits.pop_back();
}

size_t	bigint::to_size_t() const{

	size_t	result = 0;

	for (size_t i = digits.size(); i >= 0; --i)
		result = result * 10 + digits[i];

	return result;
}

bigint::bigint(const bigint &src) : data(src.data) {}

bigint&	bigint::operator=(const bigint &src){
	if (this != &src)
		data = src.data;
	return (*this);
}

bigint::~bigint(){}

std::vector<int>&	bigint::getDigits(){
	return (digits);
}

std::ostream&	operator<<(std::ostream& os, const bigint &b){
	std::vector<int>&	d = b.getDigits();
	for (int i = d.size(); i > 0; --i)
		os << d[i];
	return os;
}

bigint&	bigint::operator>>=(const bigint &n){
	size_t	shift = n.to_size_t();

	if (shift >= digits.size()){
		digits.assign(1,0);
		return *this;
	}
		
	digits.erase(digits.begin(), digits.begin() + shift);
	digits.normalize();
	return *this;
}

bigint	bigint::operator>>(const bigint &n){
	bigint	r(*this);
	r >>= n;
	return r;
}

bigint	bigint::operator+(int value){

}

bigint	bigint::operator(){

}
bigint	bigint::operator(){

}
bigint	bigint::operator(){

}
bigint	bigint::operator(){

}
bigint	bigint::operator(){

}