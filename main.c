#include <stdio.h>
#include "myBank.h"
int main(){

    char transaction_type=' ';
    int exit = 0;

    while(exit!=1){
        printf("\nPlease choose a transaction type:\n");
        printf(" O-Open Account\n"
               " B-Balance Inquiry\n"
               " D-Deposit\n"
               " W-Withdrawal\n"
               " C-Close Account\n"
               " I-Interest\n"
               " P-Print\n"
               " E-Exit\n");
            int choise_flag= scanf(" %c", &transaction_type);
            if (choise_flag!=1)
                printf("Invalid transaction type\n");
            else {
                switch (transaction_type) {

                    case 'O':
                        openAccount();
                        break;

                    case 'B':
                        checkBalance();
                        break;

                    case 'D':
                        deposit();
                        break;

                    case 'W':
                        withdraw();
                        break;

                    case 'C':
                        closeAccount();
                        break;

                    case 'I':
                        addInterest();
                        break;

                    case 'P':
                        printAccounts();
                        break;

                    case 'E':
                        exitCode();
                        exit = 1;
                        break;

                    default:
                        printf("Invalid transaction type\n");
                }
            }
    }

    return 0;
}