#include "life.h"

int	main(int argc, char** argv)
{
	int	width;
	int	height;
	int	it;
	char	buffer;
	char**	grid;
	bool	pen = false;


	if (argc != 4)
		return (-1);
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	it = atoi(argv[3]);

	// if (read(0, &buffer, 1024) == -1)
	// 	return (-1);

	grid = calloc(sizeof(char *), (height + 1));
	if (!grid)
		return (-1);
	for (int i = 0; i < height; i++)
		grid[i] = calloc(sizeof(char), (width + 1));

	int i = 0;
	int j = 0;
	while (read(0, &buffer, 1) > 0)
	{
		if (buffer == 'x')
			pen = true;
		else if (buffer == 'w')
			i--;
		else if (buffer == 's')
			i++;
		else if (buffer == 'a')
			j--;
		else if (buffer == 'd')
			j++;
		if (pen == true)
			grid[i][j] = '1';
	}


}