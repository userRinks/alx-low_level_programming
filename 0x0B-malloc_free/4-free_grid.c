#include <stdlib.h>

/**
 * free_grid - free memory grid
 * @grid: pointer to 2D array
 * @height: array
 * Return: void
 */

void free_grid(int **grid, int height)
{
	int p;

	for (p = 0; p < height; p++)
	{
		free(grid[p]);
	}
	free(grid);
}
