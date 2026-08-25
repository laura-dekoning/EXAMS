#ifndef SEARCHABLE_BAG_HPP
#define SEARCHABLE_BAG_HPP

#include "bag.hpp"

class searchable_bag : virtual public bag {
public:
	virtual ~searchable_bag() = default;
	virtual bool has(int) const = 0;
	virtual searchable_bag*	clone() const = 0;
};

#endif