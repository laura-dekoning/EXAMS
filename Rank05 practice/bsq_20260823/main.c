#include "bsq.h"

int	main(int argc, char** argv)
{
	FILE*	fp;
	t_map	map;

	if (argc ==1)
	{
		if (read_map(stdin, &map))
		{
			solve_bsq(&map);
			print_map(&map);
			free_map(&map);
		}
		else
		{
			free_map(&map);
			fprintf(stderr, "map error\n");
		}

		return (0);
	}
	else
	{
		int	i = 1;
		while (argv[i])
		{
			fp = fopen(argv[i], "r");
			if (!fp)
			{
				fprintf(stderr, "map error\n");
				return (1);
			}
			if (read_map(fp, &map))
			{
				solve_bsq(&map);
				print_map(&map);
				free_map(&map);
			}
			else
			{
				free_map(&map);
				fprintf(stderr, "map error\n");
			}

			fclose(fp);

			return (0);
		}
	}

}