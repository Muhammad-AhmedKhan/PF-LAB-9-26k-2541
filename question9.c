#include <stdio.h>
#include <stdlib.h>

int sumShelf(const int *shelf, int count) {
	int sum = 0;
	int j;
	for (j = 0; j < count; j++) {
		sum += *(shelf + j);
	}
	return sum;
}

int findLargestShelf(const int *counts, int numShelves) {
	int i, maxIdx = 0;
	for (i = 1; i < numShelves; i++) {
		if (*(counts + i) > *(counts + maxIdx)) {
			maxIdx = i;
		}
	}
	return maxIdx;
}

int main(int argc, char *argv[]) {
	int shelfA[] = {101, 102, 103};
	int shelfB[] = {201, 202};
	int shelfC[] = {301, 302, 303, 304};

	int *shelves[] = {shelfA, shelfB, shelfC};
	int counts[] = {3, 2, 4};
	int i;

	for (i = 0; i < 3; i++) {
		int total = sumShelf(shelves[i], counts[i]);
		printf("Shelf %d ID total: %d\n", i + 1, total);
	}

	int largest = findLargestShelf(counts, 3);
	printf("Shelf with the most books: Shelf %d (%d books)\n", largest + 1, counts[largest]);

	return 0;
}
