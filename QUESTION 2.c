#include <stdio.h>
#include <stdlib.h>

void swapValues(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char *argv[]) {
	int priceA, priceB;

	printf("Enter price A: ");
	scanf("%d", &priceA);
	printf("Enter price B: ");
	scanf("%d", &priceB);

	printf("Before swap: A = %d, B = %d\n", priceA, priceB);

	swapValues(&priceA, &priceB);

	printf("After swap: A = %d, B = %d\n", priceA, priceB);

	return 0;
}
