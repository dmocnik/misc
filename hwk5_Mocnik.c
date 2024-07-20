//Daniel Mocnik
//Homework 5
#include <stdio.h>
int
main ()
{
  int cont;
  printf ("Problem 1\n");
  //Asks user to enter an int, then uses a while loop to determine the number of times the int has to be doubled until it is more than 100 
  int num1;
  int count = 0;
  printf("Enter an integer\n");
  scanf("%d", &num1);
  while (num1 <= 100) {
    num1 = num1 * 2;
    ++count;
    printf("%d\n", num1);
  }
  printf("It took you %d times to multiply by 2 to be >= 100.\n", count);

  printf ("Enter an integer to continue\n");
  scanf ("%d", &cont);
  puts ("");


  printf ("Problem 2\n");
  //Asks user to enter an int, then uses a for loop to print an amount of *'s that matches what the user entered.
  int stars;
  printf("Enter a positive integer for number of stars to print out\n");
  scanf("%d", &stars);
  for (int i = 0; i < stars; ++i) {
    printf("*");
  }
  printf("\n");

  printf ("Enter an integer to continue\n");
  scanf ("%d", &cont);
  puts ("");


  printf ("Problem 3\n");
  //Continually asks user to input positive numbers until they enter "-1", then prints the total of all the numbers that were entered.  
  int num3 = 0;
  int sum = 0;
  while (num3 != -1) {
    printf("Enter a positive number to sum.  Enter -1 to stop\n");
    scanf("%d", &num3);
    if (num3 != -1) {
      sum = sum + num3;
    }
  }
  printf("The sum is %d\n", sum);

  printf ("Enter an integer to continue\n");
  scanf ("%d", &cont);
  puts ("");


  printf ("Problem 4\n");
  //Uses a do while loop to print every 5th muliple of 5 degrees C in both C and F in a table format
  int celsius = 5;
  printf("Celsius Farenheit\n");
  do {
    printf("%5d %8d\n", celsius, ((celsius * 9 / 5) + 32));
    celsius = celsius + 5;
  } while (celsius <= 30);

  printf ("Enter an integer to continue\n");
  scanf ("%d", &cont);
  puts ("");


  printf ("Problem 5\n");
  //Uses a while loop to determine when the population of India will surpass the population of China
  int year = 2016;
  double china = 1.37;
  double india = 1.31;
  while (china > india) {
    china = china + (china * .0066);
    india = india + (india * .013);
    year = year + 1;
  }
  printf("India will surpass China in the year %d given constant rate of growth\n", year);

  return 0;
}
