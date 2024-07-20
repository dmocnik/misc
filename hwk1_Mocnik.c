#include <stdio.h>

int main() {
    //Problem 1 - Prompts user for year, sales, costs, and calculates profit, and stores those values into their respective variables
    printf("--=Problem 1=--\n");

    //Problem 1 Variables
    int year;
    double sales;
    double costs;
    double profit;

    //Problem 1 Code
    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the sales for the year: ");
    scanf("%lf", &sales);

    printf("Enter the costs for the year: ");
    scanf("%lf", &costs);

    profit = sales - costs;

    printf("The total profit for %d was $%lf.\n", year, profit);
    printf("Sales for %d were $%lf, and the costs were $%lf.\n", year, sales, costs);


    //Problem 2 - Calcluates discounted price by prompting user for original price and discount percentage, stores into variables, and outputs to user.
    printf("--=Problem 2=--\n");
    //Problem 2 Variables
    double price1;
    double discount;

    //Problem 2 Code
    printf("Enter a price: ");
    scanf("%lf", &price1);

    printf("Enter the percentage to be discounted: ");
    scanf("%lf", &discount);

    printf("Your discounted price is: %f\n", price1 - (price1 * discount));


    //Problem 3 - Calculates total from multiple quantities of an item, including sales tax, which are input by the user.  Outputs new total to user.  
    printf("--=Problem 3=--\n");
    //Problem 3 Variables
    int quantity;
    double price2;
    double subtotal;

    //Problem 3 Code
    printf("Enter the price of the item you would like to buy followed by the quantity: ");
    scanf("%lf %d", &price2, &quantity);
    subtotal = quantity * price2;
    printf("Your total cost is %f\n", (subtotal * .06) + subtotal);


    //Problem 4 - Calculates average grade from 3 exams which are input by the user.  Converts average from int to double and outputs to user.  
    printf("--=Problem 4=--\n");
    //Problem 4 Variables
    int exam1;
    int exam2;
    int exam3;

    //Problem 4 Code
    printf("Enter exam 1 grade: ");
    scanf("%d", &exam1);
    printf("Enter exam 2 grade: ");
    scanf("%d", &exam2);
    printf("Enter exam 3 grade: ");
    scanf("%d", &exam3);
    double avg = (double) (exam1 + exam2 + exam3) / 3;
    printf("Your average exam grade is %lf\n", avg);
}