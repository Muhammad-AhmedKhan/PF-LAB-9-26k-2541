#include <stdio.h>
#include <stdlib.h>

int isValidMark(int m) {
	if (m >= 0 && m <= 100) {
		return 1;
	}
	return 0;
}

void findMinMax(int arr[], int size, int *min, int *max) {
	int i;
	*min = *arr;
	*max = *arr;
	for (i = 1; i < size; i++) {
		if (*(arr + i) < *min) {
			*min = *(arr + i);
		}
		if (*(arr + i) > *max) {
			*max = *(arr + i);
		}
	}
}

int main(int argc, char *argv[]) {
	int arr[5];
	int i, min, max;

	for (i = 0; i < 5; i++) {
		printf("Enter mark %d: ", i + 1);
		int m;
		scanf("%d", &m);
		if (isValidMark(m)) {
			arr[i] = m;
		} else {
			printf("Invalid mark, enter again\n");
			i--;
		}
	}

	findMinMax(arr, 5, &min, &max);

	printf("Lowest mark: %d\n", min);
	printf("Highest mark: %d\n", max);

	return 0;
}
