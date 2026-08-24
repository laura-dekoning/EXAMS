#include "bsq.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	min3(int a, int b, int c)
{
	return (min(min(a, b), c));
}
void	solve_bsq(t_map *map)
{
	t_square sq;
	int**	dp = malloc(sizeof(int*) * map->rows);

	if (!dp)
		return (map_error(map));
	for (int i = 0; i < map->rows; i++)
	{
		dp[i] = malloc(sizeof(int) * map->cols);
		if (!dp[i])
			return (map_error(map));
	}

	sq.size = 0;
	sq.col = 0 ;
	sq.row = 0;

	for (int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->cols; j++)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);

			if (dp[i][j] > sq.size)
			{
				sq.size = dp[i][j];
				sq.row = i;
				sq.col = j;
			}
		}
	}
	for (int r_start = sq.row - sq.size + 1; r_start <= sq.row; r_start++)
	{
		for (int c_start = sq.col - sq.size + 1; c_start <= sq.col; c_start++)
			map->grid[r_start][c_start] = map->full;
	}

	for (int i = 0; i < map->rows; i++)
		free(dp[i]);
	free(dp);
}