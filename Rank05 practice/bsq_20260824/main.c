#include "bsq.h"

int	main(int argc, char** argv)
{
	t_map	map;
	FILE	*fp;

	if (argc == 1)
	{
		if (read_map(stdin, &map))
		{
			solve_bsq(&map);
			print_map(&map);
			free_map(&map);
		}
		else
			fputs("map error\n", stderr);
	}
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			fp = fopen(argv[i], "r");

			if (read_map(fp, &map))
			{
				solve_bsq(&map);
				print_map(&map);
				free_map(&map);
			}
			else
				fputs("map error\n", stderr);

			fclose(fp);
		}

	}

	return (0);
}