#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *arr, int n) {
	int *start = arr;
	int *end = arr + n - 1;
	int temp;
	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void printArray(const int *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", *(arr + i));
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n = 0;
	int arr[20];
	int i;

	while (1) {
		printf("Enter number of songs: ");
		scanf("%d", &n);
		if (n >= 1 && n <= 20) {
			break;
		}
		printf("Invalid size\n");
	}

	printf("Enter song IDs: ");
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	printf("Original: ");
	printArray(arr, n);

	reverseArray(arr, n);

	printf("Reversed: ");
	printArray(arr, n);

	return 0;
}
