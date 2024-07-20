//Daniel Mocnik
//Homework 8
#include <stdio.h>
#include <string.h>
int main () {
  int cont;
  printf ("Problem 1\n");
  //Uses a while loop to count the number of upper and lowercase letters in a string array that has been initialized using the {} syntax.  
  char str1[] = {'H','e','l','l','o',',',' ','D','a','n','i','e','l','.'};
  int upper = 0;
  int lower = 0;
  int index = 0;
  while (str1[index] != '\0') {
      if (str1[index] >= 65 && str1[index] <= 90) {
          
          upper = upper + 1;
      } else if (str1[index] >= 97 && str1[index] <= 122) {
          lower = lower + 1;
      }
      index++;
  }
  printf("The sentence: ");
  printf("%s\n", str1);
  printf("It has %d uppercase characters.\n", upper);
  printf("It has %d lowercase characters.\n", lower);


  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 2\n");
  //Asks user for two words, then prints the words back out in alphabetical order, or says that the words are the same.  
  char word1[20];
  char word2[20];
  printf("Enter first word\n");
  scanf("%s", word1);
  printf("Enter second word\n");
  scanf("%s", word2);
  int cmp = strcmp(word1, word2);
  if (cmp == 0) {
      printf("The words are the same\n");
  } else if (cmp > 0) {
      printf("%s  %s\n", word2, word1);
  } else {
      printf("%s  %s\n", word1, word2);
  }


  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 3\n");
  //Asks the user for their name, then uses the strcat() function to add a message to their name as a string, and outputs their name + the message.
  char str2[50];
  printf("Enter your name\n");
  scanf("%s", str2);
  strcat(str2, ": you're a winner!\n");
  printf("%s", str2);


  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  printf ("Problem 4\n");
  //Asks the user the enter a sentence, then uses a for loop with a switch statement to check each letter of the sentence to see if it is a vowel.  It counts the vowels then outputs the number to the user.
  char sen[50];
  int vowels = 0;
  printf("Enter a sentence\n");
  fgets(sen, 50, stdin);
  fgets(sen, 50, stdin);  //Needed two fgets lines since the first one reads a newline character from one of the previous scanf's somewhere, which essentially makes the program skip over the input.
  int len = strlen(sen);
  for (int i = 0; i < len; i++) {
      switch (sen[i]) {
      case 65: //A
          vowels = vowels + 1;
          break;
      
      case 97: //a
          vowels = vowels + 1;
          break;
      
      case 69: //E
          vowels = vowels + 1;
          break;
      
      case 101: //e
          vowels = vowels + 1;
          break;
      
      case 73: //I
          vowels = vowels + 1;
          break;
      
      case 105: //i
          vowels = vowels + 1;
          break;
      
      case 79: //O
          vowels = vowels + 1;
          break;
      
      case 111: //o
          vowels = vowels + 1;
          break;
      
      case 85: //U
          vowels = vowels + 1;
          break;
      
      case 117: //u
          vowels = vowels + 1;
          break;
      
      default:
          break;
      }
  }
  printf("It has %d vowels\n", vowels);

  printf ("Enter an integer to continue\n");
  scanf (" %d", &cont);
  puts ("");


  return 0;
}