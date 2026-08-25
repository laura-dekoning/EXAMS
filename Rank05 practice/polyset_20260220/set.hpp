#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class	set : public searchable_bag
{
private:
	searchable_bag	*bag_ptr;

	void	copy_from(const searchable_bag &other);

public:
	set();
	set(const searchable_bag &other);
	set(const set &other);
	set&	operator=(const set &other);
	~set();

	void insert (int) override;
	void insert (int *, int) override;
	void print() const override;
	void clear() override;
	bool has(int value) const override;

	searchable_bag*	clone() const override;
	searchable_bag&	get_bag();
	const searchable_bag&	get_bag() const;
};

#endif