#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class	set : public searchable_bag {
	private:
	searchable_bag	*bag_ptr;

	public:
	set();
	set(searchable_bag &);
	set(const set &);
	set &operator=(const set &other);
	~set();

	void insert (int);
	void insert (int *, int);
	void print() const;
	void clear();

	bool	has(int value) const;

	searchable_bag&	get_bag();
	const searchable_bag&	get_bag() const;
};

#endif