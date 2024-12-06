#include <stdio.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void addAccount(struct Account accounts[], int *numAccounts);
void deposit(struct Account accounts[], int numAccounts);
void withdraw(struct Account accounts[], int numAccounts);
void checkBalance(struct Account accounts[], int numAccounts);

int main() {
    struct Account accounts[100];
    int numAccounts = 0;
    int choice;

    do {
        printf("\n==============================\n");
        printf("  WELCOME TO BANK MANAGEMENT SYSTEM  \n");
        printf("==============================\n");

        printf("\nPlease choose an option:\n");
        printf("[1] Add Account\n");
        printf("[2] Deposit Money\n");
        printf("[3] Withdraw Money\n");
        printf("[4] Check Balance\n");
        printf("[5] Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
                break;
            case 5:
                printf("\nThank you for using the Bank Management System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addAccount(struct Account accounts[], int *numAccounts) {
    struct Account newAccount;
    printf("\nEnter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;
    accounts[*numAccounts] = newAccount;
    (*numAccounts)++;
    printf("\nAccount added successfully!\n");
}

void deposit(struct Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("\nAmount deposited successfully!\n");
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void withdraw(struct Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("\nAmount withdrawn successfully!\n");
            } else {
                printf("\nInsufficient balance!\n");
            }
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void checkBalance(struct Account accounts[], int numAccounts) {
    int accountNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("\nAccount Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found!\n");
}