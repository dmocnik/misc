#include <stdio.h>

int main() {
    //Problem 3 - Asks user if they drive an electric or non-electric car, and calculates how much gas they used based on what the MPG of their car type is and how many miles they drove
    printf("--=Problem 3=--\n");

    //Problem 3 Variables
    char car;
    double mpg;
    double miles;
    double gallons;

    //Problem 3 Code
    printf("Enter \"E\" if you have an electric car or \"N\" for non-electric: ");
    scanf(" %c", &car);
    if (car == 'E' || car == 'e') {
        printf("Your car is electric.\n");
        mpg = 40.5;
    } else {
        printf("Your car is non-electric.\n");
        mpg = 24.5;
    }
    printf("Enter number of miles driven: ");
    scanf("%le", &miles);
    gallons = (double) miles / mpg;
    printf("You used approx. %.2f gallons of gas when you drove %.1f miles.\n", gallons, miles);


    //Problem 4 - Asks user to type in any number between 10 and 20, and responds with message based on whether they followed the directions or not
    printf("--=Problem 4=--\n");

    //Problem 4 Variables
    int num;

    //Problem 4 Code
    printf("Please enter a number between 10 and 20\n");
    scanf("%d", &num);
    if (num >= 10 && num <= 20) {
        printf("Correct! Good job.\n");
    } else {
        printf("Wrong! Try again.\n");
    }
}