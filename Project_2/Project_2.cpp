// Project_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#define COKE_COST 0.55
#define PEPSI_COST 0.45
#define WATER_COST 0.85


//Return type = double
//function name = getPayment
//argument / parameters = cost (double)
double getPayment(double &cost) {
	double amountReceived = 0;
	int moneyChoice = 0;
	while (amountReceived < cost) {
		printf("Please insert\n1. Nickel \n2. Dime \n3. Quarter \n4. Dollar Bill\n");
		scanf("%d", &moneyChoice);
		if (moneyChoice == 1)
			amountReceived += .05;
		else if (moneyChoice == 2)
			amountReceived += .10;
		else if (moneyChoice == 3)
			amountReceived += 0.25;
		else if (moneyChoice == 4)
			amountReceived += 1.00;
	}
	return amountReceived;
}

//Return type = void - nothing
//Function Name = giveChange 
//Argument 1 = payment (double)
//Argument 2 = cost (double)
void giveChange(double &payment, double &cost) {
	int overPay = (payment - cost) * 100;
	double change = payment - cost;
	int quarterChange = overPay / 25;
	overPay = overPay - (quarterChange * 25); // is also equal to overPay = overPay % 25;
	int dimeChange = overPay / 10;
	overPay = overPay % 10;
	int nickelBack = overPay / 5; //look at this photograph!
	overPay = overPay - (nickelBack * 5);

	printf("Change is: %.2lf\n%i Quarters \n%i Dimes \n%i Nickels\n\n", change, quarterChange, dimeChange, nickelBack);
}

int main()
{
	int cokeCount = 10;
	int pepsiCount = 10;
	int waterCount = 10;

	int drinkChoice = 0;
	double paymentReceived = 0.0;
	double cost = 0;
	//as long as one of these counts are greater than 0 we will keep asking them to buy soda
	while (cokeCount > 0 || pepsiCount > 0 || waterCount > 0) {
		printf("Would you like to buy a drink : 1 for Coke, 2 for Pepsi, and 3 for water.");
		scanf("%d", &drinkChoice);

		//display price to customer
		//update quantity of drink

		if (drinkChoice == 1 && cokeCount > 0) {//coke
			printf("Cost = %.2lf\n", COKE_COST);
			cost = COKE_COST;
			paymentReceived = getPayment(cost);
			cokeCount--;
			giveChange(paymentReceived, cost);
			//receiving money from customer until total payment is reached
		}
		else if (drinkChoice == 2 && pepsiCount > 0) {//pepsi
			printf("Cost = %.2lf\n", PEPSI_COST);
			cost = PEPSI_COST;
			paymentReceived = getPayment(cost);
			pepsiCount--;
			giveChange(paymentReceived, cost);
			//receiving money from customer until total payment is reached
		}
		else if (drinkChoice == 3 && waterCount > 0) {//water
			printf("Cost = %.2lf\n", WATER_COST);
			cost = WATER_COST;
			paymentReceived = getPayment(cost);
			waterCount--;
			giveChange(paymentReceived, cost);
			//receiving money from customer until total payment is reached
		}
		else {
			printf("Please select a drink that isn't sold out.\n");
		}
	}//end while
	printf("THE VENDING MACHINE IS SOLD OUT, THAT'S ALL FOLKS!");
    return 0;
}



