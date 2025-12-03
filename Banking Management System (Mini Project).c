#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

struct Account accounts[100];
int count = 0;

void createAccount() {
    printf("\n--- Create Account ---\n");
    printf("Enter account number: ");
    scanf("%d", &accounts[count].accNo);
    printf("Enter name: ");
    scanf("%s", accounts[count].name);
    printf("Enter initial deposit: ");
    scanf("%f", &accounts[count].balance);
    count++;
    printf("Account created successfully!\n");
}

void deposit() {
    int acc;
    float amt;
    printf("Enter account number: ");
    scanf("%d", &acc);
    for(int i=0;i<count;i++) {
        if(accounts[i].accNo == acc) {
            printf("Enter deposit amount: ");
            scanf("%f", &amt);
            accounts[i].balance += amt;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int acc;
    float amt;
    printf("Enter account number: ");
    scanf("%d", &acc);
    for(int i=0;i<count;i++) {
        if(accounts[i].accNo == acc) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amt);
            if(amt > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amt;
                printf("Withdrawal successful! Remaining balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance() {
    int acc;
    printf("Enter account number: ");
    scanf("%d", &acc);
    for(int i=0;i<count;i++) {
        if(accounts[i].accNo == acc) {
            printf("Account holder: %s\n", accounts[i].name);
            printf("Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n=== Banking Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
