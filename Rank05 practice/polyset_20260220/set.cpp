#include "set.hpp"

void	set::copy_from(const searchable_bag &other){
	bag_ptr = other.clone();
}

set::set() : bag_ptr(nullptr){}

set::set(const searchable_bag &other) : bag_ptr(nullptr){
	copy_from(other);
}

set::set(const set &other) : bag_ptr(nullptr){
	if (other.bag_ptr)
		copy_from(*other.bag_ptr);
}

set&	set::operator=(const set &other){
	if (this != &other){
		delete bag_ptr;
		bag_ptr = nullptr;
		if (other.bag_ptr)
			copy_from(*other.bag_ptr);
	}
	return (*this);
}

set::~set(){
	delete bag_ptr;
}

void	set::insert (int value){
	if (bag_ptr && !bag_ptr->has(value))
		bag_ptr->insert(value);
}

void	set::insert (int *array, int count){
	if (!bag_ptr)
		return ;
	for (int i = 0; i < count; i++)
	{
		if (bag_ptr && !bag_ptr->has(array[i]))
			bag_ptr->insert(array[i]);
	}
}

void	set::print() const{
	if (bag_ptr)
		bag_ptr->print();
}

void	set::clear(){
	if (bag_ptr)
		bag_ptr->clear();
}

bool set::has(int value) const{
	if (!bag_ptr)
		return (false);
	return (bag_ptr->has(value));
}

searchable_bag*	set::clone() const{
	return (new set(*this));
}

searchable_bag&	set::get_bag(){
	return (*bag_ptr);
}

const searchable_bag&	set::get_bag() const{
	return (*bag_ptr);
}
