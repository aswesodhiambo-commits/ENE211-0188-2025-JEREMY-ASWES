#include <stdio.h>
#include <stdbool.h>

#define STORED_PIN   1234
#define MAX_ATTEMPTS 3

static double balance = 1000.00;



static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}


static bool readInt(int *value)
{
    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        return false;
    }
    clearInputBuffer();
    return true;
}

static bool readAmount(double *value)
{
    if (scanf("%lf", value) != 1) {
        clearInputBuffer();
        return false;
    }
    clearInputBuffer();
    return true;
}


bool login(void)
{
    int pin;

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf("Enter your PIN: ");

        if (readInt(&pin) && pin == STORED_PIN) {
            printf("Login successful.\n");
            return true;
        }

        printf("Incorrect PIN. Attempts remaining: %d\n", MAX_ATTEMPTS - attempt);
    }

    printf("Too many failed attempts. Access denied.\n");
    return false;
}


void showMenu(void)
{
    printf("\n===== ATM MENU =====\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}



void checkBalance(void)
{
    printf("Your current balance is: %.2f\n", balance);
}

void deposit(double amount)
{

    if (amount <= 0) {
        printf("Invalid amount. Deposit must be a positive number.\n");
        return;
    }
    balance += amount;
    printf("Deposited %.2f. New balance: %.2f\n", amount, balance);
}

void withdraw(double amount)
{

    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be a positive number.\n");
        return;
    }
    if (amount > balance) {
        printf("Insufficient funds. Your balance is %.2f\n", balance);
        return;
    }
    balance -= amount;
    printf("Withdrew %.2f. New balance: %.2f\n", amount, balance);
}



int main(void)
{
    int choice;
    double amount;

    printf("=== Welcome to the ATM ===\n");

    if (!login())
        return 1;

    do {
        showMenu();

        if (!readInt(&choice)) {
            printf("Invalid input. Please enter a number from 1 to 4.\n");
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1:
            checkBalance();
            break;

        case 2:
            printf("Enter amount to deposit: ");
            if (readAmount(&amount))
                deposit(amount);
            else
                printf("Invalid amount. Please enter a number.\n");
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            if (readAmount(&amount))
                withdraw(amount);
            else
                printf("Invalid amount. Please enter a number.\n");
            break;

        case 4:
            printf("Thank you for using the ATM. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
