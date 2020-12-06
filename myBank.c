#include <stdio.h>
#include "myBank.h"
#define FIRSTACCOUNTNUM 901
#define LASTACCOUNTNUM 950
#define ROW 2
#define COL 50
// the first row of the array represent if the account is open or close, 1-open/not available  0- close/available.
// the second row contains the amount off each account
double accountArray[ROW][COL]={0};
int  closeAccount_counter=0;

void openAccount( ){
    int i=0;
    double amount;
    printf("Please enter amount for deposit: ");
    int amount_flag=scanf("%lf",&amount);
    if (amount_flag!=1)
        printf("Failed to read the amount\n");
    else{
        if (amount < 0) {
            printf("Invalid amount\n");
            return;
        }
        if (closeAccount_counter==50) {
            printf("there isn't available account\n");
            return;
        }

        while(accountArray[0][i]!=0)
        {
            i++;
        }
        accountArray[0][i]=1;
        accountArray[1][i]=amount;
        closeAccount_counter++;
        printf ("New account number is %d\n",i+FIRSTACCOUNTNUM);

    }
}
void checkBalance()
{
    int account_number;
    printf("Please enter account number:");
    int account_flag=scanf("%d",&account_number);
    if (account_flag!=1)
        printf ("Failed to read the account number\n");
    else if ((accountArray[0][account_number-FIRSTACCOUNTNUM]==1) && (account_number>=FIRSTACCOUNTNUM || account_number<=LASTACCOUNTNUM)){
        printf("The balance of account number %d is:%0.2lf\n",account_number,accountArray[1][account_number-FIRSTACCOUNTNUM]);
    }
}
void deposit()
{
    int account_number;
    double amount;
    printf("Please enter account number:");
    int account_flag=scanf("%d",&account_number);
    if (account_flag!=1)
        printf ("Failed to read the account number\n");
    else {
        if (account_number < FIRSTACCOUNTNUM || account_number > LASTACCOUNTNUM) {
            printf("Invalid account number\n");
            return;
        }
        if (accountArray[0][account_number-FIRSTACCOUNTNUM]==0) {
            printf("This account is closed\n");
            return;
        }
        printf("Please enter the amount to deposit: ");
        int amount_flag=scanf("%lf",&amount);
        if(amount_flag!=1)
            printf("Failed to read the amount\n");
        else{
            if(amount<0)
                printf("Cannot deposit a negative amount\n");
            else {
                accountArray[1][account_number - FIRSTACCOUNTNUM]+=amount;
                printf("The new balance is:%0.2lf\n", accountArray[1][account_number - FIRSTACCOUNTNUM]);
            }
        }
    }


}
void closeAccount ()
{
    int account_number=0;
    printf("Please enter account number:");
    int account_flag=scanf("%d",&account_number);
    if (account_flag!=1) {
        printf("Failed to read the account number\n");
    }
    else {
        if(account_number<0)
            return;
        if ((accountArray[0][account_number - FIRSTACCOUNTNUM] == 0)&& (account_number >= FIRSTACCOUNTNUM && account_number <= LASTACCOUNTNUM)){
            printf("This account is already closed\n");
        }
        else if ((account_number >= FIRSTACCOUNTNUM && account_number <= LASTACCOUNTNUM)&& (accountArray[0][account_number - FIRSTACCOUNTNUM] == 1)) {
            accountArray[0][account_number - FIRSTACCOUNTNUM] = 0;
            accountArray[1][account_number - FIRSTACCOUNTNUM] = 0;
            printf("Closed account number %d\n", account_number);
            closeAccount_counter--;
        }

    }
}
void withdraw(){
    int account_number=0;
    double amount=0;
    printf("Please enter account number: ");
    int account_flag=scanf ("%d",&account_number);
    if(account_flag!=1)
    {
        printf ("Failed to read the account number\n");
    }
    else{
        if ((accountArray[0][account_number - FIRSTACCOUNTNUM] == 0)&& (account_number >=FIRSTACCOUNTNUM && account_number <= LASTACCOUNTNUM))
        {
            printf("This account is closed\n");
        }
        else if ((accountArray[0][account_number - FIRSTACCOUNTNUM] == 1)&& (account_number >= FIRSTACCOUNTNUM && account_number <= LASTACCOUNTNUM))
        {
            printf("Please enter the amount to withdraw: ");
            int amount_flag= scanf("%lf",&amount);
            if (amount_flag==1)
            {
                if (accountArray[1][account_number - FIRSTACCOUNTNUM]-amount<0)
                    printf ("Cannot withdraw more than the balance\n");
                else {
                    accountArray[1][account_number - FIRSTACCOUNTNUM] -= amount;
                    printf("The new balance is: %0.2lf\n",accountArray[1][account_number - FIRSTACCOUNTNUM]);
                }
            }
        }
    }
    return;
}
void printAccounts (){
    for (int i = 0; i <COL ; ++i) {
        if (accountArray[0][i]==1)
        {
            printf("The balance of account number %d is: %0.2lf\n",i+FIRSTACCOUNTNUM,accountArray[1][i]);
        }
    }
    printf("\n");
}
void exitCode(){
    for (int i=0;i<ROW;i++)
        for (int j=0;j<COL;j++)
            accountArray[i][j]=0;

    printf("\n");
}
void addInterest (){
    int interest;
    printf("Please enter interest rate: ");
    int interest_flag=scanf("%d",&interest);
    if (interest_flag!=1)
        printf("Failed to read the interest rate\n");
    else{
        if(interest<0)
            printf("Invalid interest rate\n");
        else {
            for (int i = 0; i < COL; i++) {
                if(accountArray[0][i]==1){
                    accountArray[1][i] += (accountArray[1][i] * interest);
                    accountArray[1][i]/=100;
                }
            }
            printf("\n");
        }
    }

}




