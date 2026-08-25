#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	int	rows;
	int	cols;

	int	empty;
	int	obstacle;
	int	full;

	char**	grid;
} t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
} t_square;


int		read_map(FILE *fp, t_map* map);
void	solve_bsq(t_map* map);
void	print_map(t_map* map);
void	free_map(t_map* map);

#endif
