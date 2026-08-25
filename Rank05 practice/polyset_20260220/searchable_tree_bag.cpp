#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){
	tree_bag();
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other){}

searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag &other){
	if (this != &other)
		tree_bag::operator=(other);
	return (*this);
}

searchable_bag*	searchable_tree_bag::clone() const{
	return (new searchable_tree_bag(*this));
}

bool	searchable_tree_bag::has(int value) const{
	node	*current = tree;
	while (current != nullptr){
		if (current->value < value)
			current = current->l;
		if (current->value > value)
			current = current->r;
		else
			return (true);
	}
	return (false);
}
