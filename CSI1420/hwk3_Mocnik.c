#include <stdio.h>

int main() {
    //Problem 1 - Asks user to input 3 grades.  These three grades are then converted from int to double using casting, and used to calculate the average grade, which is then output to the user. 
    printf("--=Problem 1=--\n");

    //Problem 1 Vars
    int grade1, grade2, grade3;

    //Problem 1 Code
    printf("Enter three homework grades ranging from 0 to 100\n");
    scanf("%d %d %d", &grade1, &grade2, &grade3);
    printf("Your average is %.2lf%%.\n", (double) (grade1 + grade2 + grade3) / 3);


    //Problem 2 - Asks the user to input the price and quantity of three items, one at a time.  Then displays the price, quantity, subtotal for each item, on a table, followed by the grand total, inlcuding tax.
    printf("--=Problem 2=--\n");

    //Problem 2 Vars
    double price1, price2, price3, total;
    double tax = .06;
    int quantity1, quantity2, quantity3;

    //Problem 2 Code
    printf("Enter price and quantity for item 1\n");
    scanf("%lf %d", &price1, &quantity1);
    printf("Enter price and quantity for item 2\n");
    scanf("%lf %d", &price2, &quantity2);
    printf("Enter price and quantity for item 3\n");
    scanf("%lf %d", &price3, &quantity3);
    total = ((price1 * quantity1) + (price2 * quantity2) + (price3 * quantity3)) + (((price1 * quantity1) + (price2 * quantity2) + (price3 * quantity3)) * tax);
    printf("%-10s %10s %10s\n", "Price", "Quantity", "Total");
    printf("%-10.2lf %10d %10.2lf\n", price1, quantity1, (price1 * quantity1));
    printf("%-10.2lf %10d %10.2lf\n", price2, quantity2, (price2 * quantity2));
    printf("%-10.2lf %10d %10.2lf\n", price3, quantity3, (price3 * quantity3));
    printf("Total is $%.2lf\n", total);
}