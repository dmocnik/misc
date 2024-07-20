//Daniel Mocnik
//Homework 7
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
  int cont;
  printf ("Problem 1\n");
  //Initializes with an array of 10 random integers, then uses a for loop to sum all of them together and prints out the result, then uses a while loop to determine the highest number in the array and prints out the result
  int sum = 0;
  int highest = 0;
  int cur = 0;
  int nums[10] = {49, 15, 91, 97, 77, 82, 31, 66, 70, 34};  //sum = 612, highest = 97
  for (int i = 0; i < 10; i++) {
      sum = sum + nums[i];
  }
  printf("The sum is %d\n", sum);
  while (cur < 10) {
      if (nums[cur] > highest) {
          highest = nums[cur];
      }
      cur = cur + 1;
  }
  printf("The highest number is %d\n", highest);

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 2\n");
  //Initializes an array of 10 random doubles, then uses three separate functions to print the array, double all the numbers in the array, and calculate the average of all the numbers in the array, respectively.  
  int sz = 10;
  double average;
  double nums2[] = {51.7, 72.9, 64.4, 44.8, 26.9, 2.0, 42.6, 18.7, 6.6, 27.4}; //sum = 716, avg = 71.6
  void printArray(double nums2[], int sz);
  void modifyArray(double nums2[], int sz);
  double avgArray(double nums2[], int sz);
  printArray(nums2, sz);
  modifyArray(nums2, sz);
  printArray(nums2, sz);
  average = avgArray(nums2, sz);
  printf("Average value is %.1lf\n", average);

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 3\n");
  //Uses srand(time(NULL)) to randomize the seed, then initializes an array of 100 integers, then uses a for loop to fill it with random integers from 40 - 120, then uses another foor loop to print everything in the array.  
  srand(time(NULL));
  int array[100];
  for (int i = 0; i < 100; i++) {
      array[i] = rand() % 81 + 40;
  }
  for (int i = 0; i < 100; i++) {
      printf("%d\n", array[i]);
  }

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");
  return 0;
}

void printArray(double nums2[], int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%-10.1lf", nums2[i]);
    }
    printf("\n");
}

void modifyArray(double nums2[], int sz) {
    for (int i = 0; i < sz; i++) {
        nums2[i] = nums2[i] * 2;
    }
}

double avgArray(double nums2[], int sz) {
    double avg = 0;
    for (int i = 0; i < sz; i++) {
        avg = avg + nums2[i];
    }
    avg = avg / sz;
    return avg;
}
