//Daniel Mocnik
//Homework 6
#include <stdio.h>
int main () {
  int cont;
  printf ("Problem 1\n");
  //Asks user for a letter, then uses a function to convert the character to uppercase via passing by value
  char letter;
  char result;
  char processLetter(char letter);
  printf("Enter a letter\n");
  scanf(" %c", &letter);
  result = processLetter(letter);
  if (result == '#') {
    printf("You didn't enter a letter\n");
  } else {
    printf("%c\n", result);
  }

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 2\n");
  //Same thing as problem 1, except uses passing by reference
  char letter2;
  char *c;
  void processLetter2(char *c);
  c = &letter2;
  printf("Enter a letter\n");
  scanf(" %c", &letter2);
  processLetter2(&letter2);
  if (letter2 == '#') {
    printf("You didn't enter a letter\n");
  } else {
    printf("%c\n", letter2);
  }

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 3\n");
  //Asks user to input a letter, then converts it to uppercase using a function, then uses another function to determine what room number the user gets
  char letter3;
  int roomNum;
  char makeUpperCase(char letter3);
  int roomNumber(char letter3);
  printf("Enter a letter\n");
  scanf(" %c", &letter3);
  letter3 = makeUpperCase(letter3);
  if (letter3 != '#') {
      roomNum = roomNumber(letter3);
      printf("%c     %d\n", letter3, roomNum);
  } else {
      printf("You didn't enter a letter\n");
  }

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 4\n");
  //Asks user to input grades for participation, homework, and three exam grades, then uses a function to calculate the overall percentage according to the weights of each category and outputs it to the user.  Then uses another function to determine what letter the user receivies based on the perentage.
  double part, hw, exam1, exam2, exam3, points;
  char grade;
  double calcPoints(double part, double hw, double exam1, double exam2, double exam3);
  char calcGrade(double points);
  printf("Enter your grade for Class Participation\n");
  scanf(" %lf", &part);
  printf("Enter your grade for Homework\n");
  scanf(" %lf", &hw);
  printf("Enter your grade for Exam 1\n");
  scanf(" %lf", &exam1);
  printf("Enter your grade for Exam 2\n");
  scanf(" %lf", &exam2);
  printf("Enter your grade for Exam 3\n");
  scanf(" %lf", &exam3);
  points = calcPoints(part, hw, exam1, exam2, exam3);
  printf("Your class points are %.1lf\n", points);   
  grade = calcGrade(points);
  printf("Your grade is %c\n", grade);

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  return 0;
}

char processLetter(char letter) {
  if (letter >= 97 && letter < 122) {
    letter = letter - 32;
    return letter;
  } else if (letter >= 65 && letter < 90) {
    return letter;
  } else {
    return '#';
  }
}

void processLetter2(char *c) {
  if (*c >= 97 && *c < 122) {
    *c = *c - 32;
  } else if (*c >= 65 && *c < 90) {
    //nothing
  } else {
    *c = '#';
  }
}

char makeUpperCase(char letter3) {
  if (letter3 >= 97 && letter3 < 122) {
      letter3 = letter3 - 32;
      return letter3;
  } else if (letter3 >= 65 && letter3 < 90) {
      return letter3;
  } else {
      return '#';
  }
}

int roomNumber(char letter3) {
  if (letter3 == 'A' || letter3 == 'B' || letter3 == 'C' || letter3 == 'D' || letter3 == 'E') {
      return 100;
  } else if (letter3 == 'F' || letter3 == 'G' || letter3 == 'H' || letter3 == 'I' || letter3 == 'J' || letter3 == 'K') {
      return 200;
  } else if (letter3 == 'L' || letter3 == 'M' || letter3 == 'N' || letter3 == 'O' || letter3 == 'P' || letter3 == 'Q' || letter3 == 'R' || letter3 == 'S') {
      return 300;
  } else if (letter3 == 'T' || letter3 == 'U' || letter3 == 'V' || letter3 == 'W' || letter3 == 'X' || letter3 == 'Y' || letter3 == 'Z') {
      return 400;
  }
}

double calcPoints(double part, double hw, double exam1, double exam2, double exam3) {
    double result;
    result = ((part * 0.2) + (hw * 0.2) + (exam1 * 0.2) + (exam2 * 0.2) + (exam3 * 0.2));
    return result;
}

char calcGrade(double points) {
  if (points >= 90) {
      return 'A';
  } else if (points >= 77 && points < 90) {
      return 'B';
  } else if (points >= 66 && points < 77) {
      return 'C';
  } else if (points >= 60 && points < 66) {
      return 'D';
  } else if (points < 60) {
      return 'F';
  }
}