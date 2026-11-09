#include <stdio.h>
#include <string.h>

int main(void)
{
    int registrationNumber, marks, choice = 1;
    char name[50], grade, comment[20], status[20];

    while (choice == 1) {
        printf("\n---STUDENT INFORMATION---\n");

        printf("Registration: ");
        if (scanf("%d", &registrationNumber) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Name: ");
        scanf(" %49[^\n]", name);

        do {
            printf("Marks (0-100): ");
            if (scanf("%d", &marks) != 1) {
                while (getchar() != '\n');
                marks = -1;
            }
        } while (marks < 0 || marks > 100);

        strcpy(status, marks < 40 ? "FAILED" : "PASSED");

        if (marks >= 70)      grade = 'A';
        else if (marks >= 60) grade = 'B';
        else if (marks >= 50) grade = 'C';
        else if (marks >= 40) grade = 'D';
        else                  grade = 'F';

        switch (grade) {
            case 'A': strcpy(comment, "Excellent"); break;
            case 'B': strcpy(comment, "Very Good"); break;
            case 'C': strcpy(comment, "Good");      break;
            case 'D': strcpy(comment, "Pass");      break;
            default:  strcpy(comment, "Failed");    break;
        }

        printf("\n---STUDENT RESULTS---\n");
        printf("Registration Number: %d\n", registrationNumber);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Status: %s\n", status);
        printf("Grade: %c\n", grade);
        printf("Comment: %s\n", comment);

        printf("Do you want to enter another student? (1=Yes, 0=No): ");
        if (scanf("%d", &choice) != 1) break;
    }
    return 0;
}
