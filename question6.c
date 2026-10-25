#include <stdio.h>
#include <stdlib.h>

int deposit(float *balance, float amount) {
	if (amount <= 0) {
		return 0;
	}
	*balance += amount;
	return 1;
}

int withdraw(float *balance, float amount) {
	if (amount <= 0 || amount > *balance) {
		return 0;
	}
	*balance -= amount;
	return 1;
}

int main(int argc, char *argv[]) {
	float balance = 1000.0;
	int choice;
	float amount;

	do {
		printf("Choose option (1-4): ");
		scanf("%d", &choice);

		if (choice == 1) {
			printf("Enter amount: ");
			scanf("%f", &amount);
			if (deposit(&balance, amount)) {
				printf("Amount deposited successfully.\n");
			} else {
				printf("Insufficient funds or invalid amount.\n");
			}
		} else if (choice == 2) {
			printf("Enter amount: ");
			scanf("%f", &amount);
			if (withdraw(&balance, amount)) {
				printf("Amount withdrawn successfully.\n");
			} else {
				printf("Insufficient funds or invalid amount.\n");
			}
		} else if (choice == 3) {
			printf("Current balance: %.2f\n", balance);
		} else if (choice == 4) {
			printf("Goodbye.\n");
		} else {
			printf("Invalid option\n");
		}
	} while (choice != 4);

	return 0;
}
