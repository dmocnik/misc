#include <stdio.h>

int main() {
    //Problem 1 - Asks user for gender using a single character, then asks for their weight, and calculates how many calories the user needs to ingest in order to maintain their weight based off of the gender they specified.
    printf("--=Problem 1=--\n");

    //Problem 1 Vars
    char gender;
    int weight;

    //Problem 1 Code
    printf("Enter M, F, or N for gender\n");
    scanf("%c", &gender);
    printf("Enter your weight in pounds\n");
    scanf("%d", &weight);
    if (gender == 'F') {
        printf("You need approx. %d calories per day to maintain your weight.\n", weight * 10);
    } else {
        printf("You need approx. %d calories per day to maintain your weight.\n", weight * 11);
    }


    //Problem 2 - Prompts user to enter a score for an exam, then provides a little bit of feedback on their score using nested if/else statements based on what score they entered.  
    printf("--=Problem 2=--\n");

    //Problem 2 Vars
    int score;

    //Problem 2 Code
    printf("Enter your exam score\n");
    scanf("%d", &score);
    if (score > 100 || score <= 0) {
        printf("You entered an invalid score\n");
    } else {
        if (score >= 80) {
            printf("Awesome!\n");
        } else if (score >= 60) {
            printf("Nice.\n");
        } else {
            printf("You should study more.\n");
        }
    }

    
    //Problem 3 - Prompts user to enter a grade, then assigns them a group if the number they entered is 1 through 6, otherwise returns saying that the grade is invalid
    printf("--=Problem 3=--\n");

    //Problem 3 Vars
    int grade;

    //Problem 3 Code
    printf("Enter your grade\n");
    scanf("%d", &grade);
    switch (grade) {
        case 1:
            printf("Group A\n");
            break;
        case 2:
            printf("Group A\n");
            break;
        case 3:
            printf("Group B\n");
            break;
        case 4:
            printf("Group B\n");
            break;
        case 5:
            printf("Group C\n");
            break;
        case 6:
            printf("Group C\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    } 
}