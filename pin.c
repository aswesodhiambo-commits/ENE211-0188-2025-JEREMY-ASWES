#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    #define WAIT_ONE_SECOND() Sleep(1000)
#else
    #include <unistd.h>
    #define WAIT_ONE_SECOND() sleep(1)
#endif

int main(void) {
    const char *correctPin = "9999";
    char userPin[20];
    int attempt;
    int granted = 0;
    int choice;


    while (!granted) {
        attempt = 0;

        while (attempt < 3 && !granted) {
            printf("Enter PIN: ");
            scanf("%19s", userPin);

            int length = strlen(userPin);

            if (length > 4) {
                printf("PIN is too long\n");
            } else if (length < 4) {
                printf("PIN is too short\n");
            } else if (strcmp(userPin, correctPin) == 0) {
                granted = 1;
            } else {
                printf("Access Denied\n");
                attempt++;
                if (attempt < 3) {
                    printf("Attempts remaining: %d\n", 3 - attempt);
                }
            }
        }

        if (!granted) {
            printf("Access Blocked\n");
            printf("Please wait 5 seconds before trying again...\n");
            for (int i = 5; i >= 1; i--) {
                printf("%d...\n", i);
                fflush(stdout);
                WAIT_ONE_SECOND();
            }
            printf("\nYou may try again.\n");
        }
    }


    do {
        printf("\n=== Device Menu ===\n");
        printf("1. Open Door\n");
        printf("2. Change Username\n");
        printf("3. Change PIN\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        int result = scanf("%d", &choice);
        if (result == EOF) {
            break;
        }
        if (result != 1) {

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            choice = 0;
        }

        switch (choice) {
            case 1:
                printf("Access granted. Door unlocked\n");
                break;
            case 2:
                printf("Change username feature coming soon.\n");
                break;
            case 3:
                printf("Change PIN feature coming soon.\n");
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
