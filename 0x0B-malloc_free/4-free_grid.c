#include <stdlib.h>

/**
 * free_grid - allocate memory grid
 * @grid: pointer to 2D array
 * @height: array
 * Return: void
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
