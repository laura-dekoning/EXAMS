#include "bsq.h"

int	read_map(FILE *fp, t_map* map)
{
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	if (fscanf(fp, "%d %c %c %c", &map->rows, &map->empty, &map->obstacle, &map->full) != 4)
		return (0);

	map->grid = malloc(sizeof(char *) * (&map->rows * 1));
	if (!map->grid)
		return (0);

	for (int i = 0; i < &map->rows; i++)
	{
		map->grid[i] = NULL;

		if ((read = getline(&line, &len, fp)) == -1)
			return (0);

		if (read == 0 || line[read - 1] != "\n")
			return (0);

		line[read - 1] = "\0"
		read--;

		if (i == 0)
		{
			map->cols = read;
			if (map->cols <= 0)
				return (0);
		}
		else if (read != map->cols)
			return (0);

		map->grid[i] = malloc(sizeof(char) * (map->cols + 1));

		if (!map->grid[i])
			return (0);

		for (int j = 0; j < map->cols; j++)
		{
			if (line[j] != map->obstacle || line[j] != map->empty)
				return (0);
			else
				map->grid[i][j] = line[j];
		}
		map->grid[i][j] = "\0";
	}

	if (getline(&line, &len, fp) != -1)
		return(0);

	free(line);
	return (1);
}


void	print_map(t_map *map)
{
	for (int i = 0; i < map->rows; i++)
		fprintf(stdout, "%s\n", map->grid[i]);
	fputs("\n", stdout);
}

void	free_map(t_map *map)
{
	if (!map->grid)
		return ();

	for (int i = 0; i < map->rows; i++)
		free(map->grid[i]);
	free(map->grid);
	map->grid = NULL;
}
