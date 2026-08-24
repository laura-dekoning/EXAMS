#include "set.hpp"

set::set() : bag_ptr(0) {}

set::set(searchable_bag &other) : bag_ptr(&other) {}

set::set(const set &other) : bag_ptr(other.bag_ptr) {}

set& set::operator=(const set &other){
	if (this != &other)
		bag_ptr = other.bag_ptr;
	return *this;
}

set::~set(){}

void set::insert (int value){
	if (bag_ptr && !bag_ptr->has(value))
		bag_ptr->insert(value);
}

void set::insert (int *data, int count){
	if (bag_ptr)
	{
		for (int i = 0; i < count; i++)
			if (!bag_ptr->has(data[i]))
				bag_ptr->insert(data[i]);
	}
}

void set::print() const{
	if (bag_ptr)
		bag_ptr->print();
}

void set::clear(){
	if (bag_ptr)
		bag_ptr->clear();
}

bool	set::has(int value) const{
	return (bag_ptr && bag_ptr->has(value));
}


searchable_bag&	set::get_bag(){
	return (*bag_ptr);
}
const searchable_bag&	set::get_bag() const{
	return (*bag_ptr);
}