#ifndef BANK_H
#define BANK_H
#include <Accounts.h>
#include <iostream>
#include<map>
#include <fstream>

class Bank
{
    private:
        map<int, Accounts> accounts_map;

    public:
        Bank();
        Accounts OpenAccount(string fname, string lname, float balance);
        Accounts BalanceEnquiry(int Acct_no);
        Accounts Deposit(int Acct_no, float amount);
        Accounts Withdraw(int Acct_no,float amount);
        void CloseAccount(int Acct_no);
        void showAllAccounts();
        ~Bank();

};
Bank::Bank()
{
    Accounts account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile)
    {
        //cout<<"Error in Opening File. File Not Found!"<<endl;
        return;
    }
    while(!infile.eof())
    {
        infile>>account;
        accounts_map.insert(pair<int,Accounts>(account.get_Acctno(),account));
    }
    account.set_LastAccountNo(account.get_Acctno());
    infile.close();
}

Accounts Bank::OpenAccount(string fname, string lname, float balance)
{
    ofstream outfile;
    Accounts account(fname,lname,balance);
    accounts_map.insert(pair<int,Accounts>(account.get_Acctno(),account));

    outfile.open("Bank.data", ios::trunc);
    map<int,Accounts>::iterator itr;
    for(itr=accounts_map.begin();itr!=accounts_map.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}

Accounts Bank::BalanceEnquiry(int Acct_no)
{
    map<int,Accounts>::iterator itr=accounts_map.find(Acct_no);
    return itr->second;
}

Accounts Bank::Deposit(int Acct_no, float amount)
{
    map<int,Accounts>::iterator itr=accounts_map.find(Acct_no);
    itr->second.Deposit(amount);
}

Accounts Bank::Withdraw(int Acct_no, float amount)
{
    map<int,Accounts>::iterator itr=accounts_map.find(Acct_no);
    itr->second.Withdraw(amount);
}
void Bank::CloseAccount(int Acct_no)
{
    map<int,Accounts>::iterator itr=accounts_map.find(Acct_no);
    cout<<"Account deleted"<<endl;
    accounts_map.erase(Acct_no);
}
void Bank::showAllAccounts()
{
    map<int,Accounts>::iterator itr;
    for(itr=accounts_map.begin();itr!=accounts_map.end();itr++)
    {
        cout<<"Account"<<itr ->first<<endl<<itr->second<<endl;
    }
}
Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data",ios::trunc);
    map<int,Accounts>::iterator itr;
    for(itr=accounts_map.begin();itr!=accounts_map.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
}

#endif // BANK_H
