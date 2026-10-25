#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bubblesort(int *arr, int n){
	int i, j , temp;
	for(i = 0; i < n - 1; i++) {
		for( j = 0; j < n - i -1; j ++){
			if (*(arr + j) > *(arr + (j + 1))){
			
			temp = *(arr + j);
			*(arr + j) = *(arr + ( j + 1));
			*(arr + ( j + 1)) = temp;
		}
	}
} }



void print(int *arr, int n) {
	for (int i = 0; i < n; i++){
		printf(" %d ", *(arr + i));
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n;

	int arr[20];
	int valid = 0;
	int i;
	int number = 0;
	while(valid == 0){		
		printf("enter upto 20 scores");
		scanf("%d", &number);
		if(number < 1 || number> 20){
			printf("invalid number");
		}
		else{
			valid = 1;
		}
	}	
	
	for(i = 0; i < number; i++){
		scanf("%d", &n);
		arr[i] = n;
	}
	
	printf("Before Sort\n");
	print(arr, number);
	
	bubblesort(arr, number);
	
	printf("after sort");
	print(arr, number);
	return 0;
}