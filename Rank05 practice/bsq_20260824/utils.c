#include "bsq.h"

int	read_map(FILE *fp, t_map *map)
{
	char*	line = NULL;
	size_t	len = 0;
	__ssize_t	read;

	if (fscanf(fp, "%d %c %c %c", &map->rows, &map->empty, &map->obstacle, &map->full) != 4)
		return (-1);

	if (is_print(map->empty) || is_print(map->obstacle) || is_print(map->full))
		return(map_error(map));

	if ((map->empty == map->obstacle) || (map->obstacle == map->full) || (map->full == map->empty))
		return(map_error(map));

	map->grid = (char*)malloc(sizeof(char*) * map->rows);
	if (!map->grid)
		return (-1);

	read = getline(&line, &len, fp);
	map->cols = read;

	for (int i = 0; i < map->rows; i++)
	{
		map->grid[i] = malloc(sizeof(char) * (read));
		if (!map->grid[i])
			return (-1);

		if (read != map->cols)
			return (-1);
		if (line[read - 1] != '\n')
			return (-1);
		else
		{
			for (int j = 0; j < read; j++)
			{
				if (line[j] != map->empty || line[j] != map->obstacle)
					return(map_error(map));
				map->grid[i][j] = line[j];
			}
			map->grid[i][read - 1] = '\0';
		}
		read = getline(&line, &len, fp);
		if (read == -1)
			return (-1);
	}
}

void	print_map(t_map *map)
{
	if (!map->grid)
		return;

	for (int i = 0; i < map->rows; i++)
	{
		fprintf(stdout, "%s", map->grid[i]);
	}
}

void	free_map(t_map *map)
{
	if (!map->grid)
		return;
	
	for (int i = 0; i < map->rows; i++)
	{
		if (map->grid[i])
			free(map->grid[i]);
	}
	free(map->grid);
	map->grid = NULL;
}

int	is_print(char c)
{
	if (c > 126 || c < 33)
		return (0);
	return (1);
}