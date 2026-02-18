#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class bigint
{
private:
    std::vector<int> digits; // reversed storage

    void normalize();
    size_t to_size_t() const;

public:
    // constructors
    bigint();
    bigint(unsigned long long n);
    bigint(const bigint& other);

    bigint& operator=(const bigint& other);

    // addition
    bigint operator+(const bigint& rhs) const;
    bigint& operator+=(const bigint& rhs);

    // increment
    bigint& operator++();
    bigint operator++(int);

    // digit shift
    bigint operator<<(size_t n) const;
    bigint& operator<<=(size_t n);

    bigint operator>>(const bigint& n) const;
    bigint& operator>>=(const bigint& n);

    // comparisons
    bool operator<(const bigint& rhs) const;
    bool operator<=(const bigint& rhs) const;
    bool operator>(const bigint& rhs) const;
    bool operator>=(const bigint& rhs) const;
    bool operator==(const bigint& rhs) const;
    bool operator!=(const bigint& rhs) const;

    // 👇 public read-only accessor for printing
    const std::vector<int>& getDigits() const;
};

// stream operator OUTSIDE class (no friend)
std::ostream& operator<<(std::ostream& os, const bigint& b);

#endif
