#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	int	cols;
	int	rows;

	char	obstacle;
	char	empty;
	char	full;

	char**	grid;
} t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
} t_square;


int		read_map(FILE *fp, t_map *map);
void	free_map(t_map *map);
void	print_map(t_map *map);
int		map_error(t_map *map);
void	solve_bsq(t_map *map);

#endif