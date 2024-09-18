#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login(void);
void display(void);
void checkBalance(int balance);
void withdraw(int *account_num);
void deposit(int *account_num);
void changePIN(int *account_num);
float balance=150000;
// #define A 1000
char originalpin[5] = "1234";  // Storing PIN as a string
int main() {
    int choice=0,user=0;
    while(1) {
        printf("\n");
        printf("\033[2J \033[H");   //used to clear the terminal command
        login();                   // calling function
        display();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nYour current balance is %.2f",balance);
                break;
            case 2:
                withdraw(&user);
                break;
            case 3:
                deposit(&user);
                break;
            case 4:
                changePIN(&user);
                break;
            case 5:
                printf("Thank you for using our ATM!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void display(void) {
    printf("=============================================================================\n");
    printf("    *      **********  *       *      *       *   ********   *     *  *     *\n");
    printf("   *  *         *      * *    * *     * *    * *  *          * *   *  *     *\n");
    printf("  ******        *      *  *  *  *     *  *  *  *  ********   *  *  *  *     *\n");
    printf(" *      *       *      *   *    *     *   *    *  *          *   * *  *     *\n");
    printf("*        *      *      *        *     *        *  ********   *    **  *******\n");
    printf("=============================================================================\n");
    printf("\n");
    printf("OPTIONS ARE GIVEN BELOW:\n");
    printf("\n");
    printf("*************************************************************\n");
    printf("      1. Check Balance of current bank account       \n");
    printf("      2. Withdraw money from your bak account        \n");
    printf("      3. Deposit amount to your bank account         \n");
    printf("      4. Change PIN of your bank account             \n");
    printf("      5. Exit                                        \n");
    printf("*************************************************************\n");
}
void login(void) {
    int accountNumber;
    printf("===========================================================================================\n");
    printf("********  *********  **********      ***********   *     *   *******  *******       *       \n");
    printf("*         *       *       *                *       **    *   *     *     *         * *       \n");
    printf("*         *       *       *                *       * *   *   *     *     *        *   *      \n");
    printf("********  *********       *                *       *  *  *   *     *     *       *     *     \n");
    printf("        * *       *       *                *       *   * *   *     *     *      *********     \n");
    printf("        * *       *       *                *       *    **   *     *     *     *         *    \n");
    printf("********* *********  ***********     ***********   *     *   *******  ******* *           *   \n");
    printf("===============================================================================================\n");
    printf("\n");
    printf("Enter account number: ");
    scanf("%i", &accountNumber);
    printf("Enter account pin: ");
    scanf("%s", originalpin);
    if(accountNumber == 1234) {
        printf("\nLogin successful!\n");
    } else {
        printf("Invalid account number.Try again.\n");
        exit(1);
    }
}
/*void checkBalance(int balance) {
    printf("\nYour current balance is: %.2f\n", balance);
    printf("%.2f\n", balance);
}*/
void withdraw(int *account) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if(amount > 0 && amount <=balance) {
        balance -= amount;
        printf("\nWithdrawal successful.Your new balance is:%.2f\n", balance);
    } else {
        printf("\nInsufficient balance or invalid amount.\n");
    }
    getchar(); // To consume newline character left by scanf
    getchar(); // To pause execution
}
void deposit(int *account) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    if(amount > 0) {
        balance += amount;
        printf("Deposit successful. Your new balance is:%.2f\n", balance);
    } else {
        printf("Invalid amount.\n");
    }
    getchar();
    getchar();
}
void changePIN(int *account) {
    char newPIN[5];
    printf("Enter new PIN: ");
    scanf("%4s", newPIN);
    if(strlen(newPIN) == 4) {
        strcpy(originalpin, newPIN);
        printf("PIN changed successfully.\n");
    } else {
        printf("Invalid PIN. It must be 4 digits.\n");
    }
    getchar();
    getchar();
}

