#include <stdio.h>
#include <stdlib.h>

int countNeighbours(int (*grid)[5], int row, int col) {
	int count = 0;
	int dr, dc, r, c;
	for (dr = -1; dr <= 1; dr++) {
		for (dc = -1; dc <= 1; dc++) {
			if (dr == 0 && dc == 0) {
				continue;
			}
			r = row + dr;
			c = col + dc;
			if (r >= 0 && r < 5 && c >= 0 && c < 5) {
				count += (grid[r][c] & 1);
			}
		}
	}
	return count;
}

void nextGeneration(int (*grid)[5]) {
	int r, c, neighbors, currentState, nextState;
	for (r = 0; r < 5; r++) {
		for (c = 0; c < 5; c++) {
			neighbors = countNeighbours(grid, r, c);
			currentState = grid[r][c] & 1;
			nextState = 0;
			if (currentState == 1) {
				if (neighbors == 2 || neighbors == 3) {
					nextState = 1;
				}
			} else {
				if (neighbors == 3) {
					nextState = 1;
				}
			}
			if (nextState == 1) {
				grid[r][c] |= 2;
			}
		}
	}
	for (r = 0; r < 5; r++) {
		for (c = 0; c < 5; c++) {
			grid[r][c] >>= 1;
		}
	}
}

void printGrid(int (*grid)[5]) {
	int r, c;
	for (r = 0; r < 5; r++) {
		for (c = 0; c < 5; c++) {
			printf("%d", grid[r][c] & 1);
			if (c < 4) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int grid[5][5] = {0};
	int gens = -1;
	int g;

	grid[1][2] = 1;
	grid[2][2] = 1;
	grid[3][2] = 1;

	while (gens < 0 || gens > 50) {
		printf("Enter number of generations (0-50): ");
		scanf("%d", &gens);
		if (gens < 0 || gens > 50) {
			printf("Invalid number\n");
		}
	}

	for (g = 0; g <= gens; g++) {
		printf("Generation %d:\n", g);
		printGrid(grid);
		if (g < gens) {
			nextGeneration(grid);
		}
	}

	return 0;
}
