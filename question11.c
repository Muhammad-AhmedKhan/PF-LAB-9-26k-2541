#include <stdio.h>
#include <stdlib.h>

int square(int x) {
	return x * x;
}

int negate(int x) {
	return -x;
}

int isEven(int x) {
	return (x % 2 == 0);
}

int isPositive(int x) {
	return (x > 0);
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
	int i;
	for (i = 0; i < n; i++) {
		*(arr + i) = fn(*(arr + i));
	}
}

int countIf(const int *arr, int n, int (*pred)(int)) {
	int count = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (pred(*(arr + i))) {
			count++;
		}
	}
	return count;
}

void printGeneric(void *data, char type, int n) {
	int i;
	if (type == 'i') {
		int *arr = (int *)data;
		for (i = 0; i < n; i++) {
			printf("%d", *(arr + i));
			if (i < n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	} else if (type == 'f') {
		float *arr = (float *)data;
		for (i = 0; i < n; i++) {
			printf("%.2f", *(arr + i));
			if (i < n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	} else if (type == 'c') {
		char *arr = (char *)data;
		for (i = 0; i < n; i++) {
			printf("%c", *(arr + i));
			if (i < n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	} else {
		printf("Invalid type '%c' for printGeneric\n", type);
	}
}

int main(int argc, char *argv[]) {
	int n = 0;
	int arr[] = {3, -2, 8, -5, 6};
	float farr[] = {1.50, 2.25};

	while (1) {
		printf("Enter n (1-50): ");
		scanf("%d", &n);
		if (n >= 1 && n <= 50) {
			break;
		}
	}

	int size = n < 5 ? n : 5;

	printf("Original: ");
	printGeneric(arr, 'i', size);

	applyToArray(arr, size, negate);
	printf("After negate: ");
	printGeneric(arr, 'i', size);

	printf("Positive values after negate: %d\n", countIf(arr, size, isPositive));
	printf("Even values after negate: %d\n", countIf(arr, size, isEven));

	printf("Float print (type f): ");
	printGeneric(farr, 'f', 2);

	printGeneric(arr, 'x', size);

	return 0;
}
