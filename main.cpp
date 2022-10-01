#include <iostream>
#include <Accounts.h>
#include <Bank.h>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    Bank b;
    Accounts acc;

    int choice;
    string fname, lname;
    int accountNumber;
    float balance, amount;

    cout<<"******Banking System******"<<endl;
    while(choice < 7)
    {
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";

        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter First Name: ";
            cin>>fname;
            cout<<"Enter Last Name: ";
            cin>>lname;
            cout<<"Enter initial Balance: ";
            cin>>balance;
            acc=b.OpenAccount(fname,lname,balance);
            cout<<"Congratulation Account is Created"<<endl;
            cout<<acc;
            break;
        case 2:
            cout<<"Enter the Account Number: ";
            cin>>accountNumber;
            acc=b.BalanceEnquiry(accountNumber);
            cout<<"Your Account Details"<<endl;
            cout<<acc;
            break;
        case 3:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Enter Balance:";
            cin>>amount;
            acc=b.Deposit(accountNumber, amount);
            cout<<"Amount is Deposited"<<endl;
            cout<<acc;
            break;
        case 4:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Enter the Amount to Withdraw: "<<endl;
            cin>>amount;
            acc=b.Withdraw(accountNumber,amount);
            cout<<"Amount withdrawn"<<endl;
            cout<<acc;
            break;
        case 5:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            b.CloseAccount(accountNumber);
            cout<<"Account Closed"<<endl;
            cout<<acc;
            break;
        case 6:
            b.showAllAccounts();
            break;
        default :
            cout<<"/nEnter correct choice"<<endl;
            exit(0);
        }
    }
    return 0;
}
