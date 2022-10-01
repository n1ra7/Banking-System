#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include<iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class Accounts
{
    private:
        int Acct_no;
        string Firstname;
        string Lastname;
        float Balance;
        static int NextAcctNo;

    public:
        Accounts(){}
        Accounts(string firstname, string lastname, float balance);
        string get_Firstname();
        string get_Lastname();
        int get_Acctno();
        float get_Balance();
        void Deposit(float amount);
        void Withdraw(float amount);
        void set_LastAccountNo(int Acct_no);
        int get_LastAccoutNo();
        friend ofstream& operator<<( ofstream& ofs, Accounts& acc);
        friend ifstream& operator>>( ifstream& ifs, Accounts& acc);
        friend ostream & operator<<( ostream &  os, Accounts& acc);


};
int Accounts::NextAcctNo=0;

Accounts::Accounts(string firstname, string lastname, float balance)
{
    Firstname = firstname;
    Lastname = lastname;
    Balance = balance;
    Acct_no = NextAcctNo;
}
string Accounts::get_Firstname()
{
    return Firstname;
}
string Accounts::get_Lastname()
{
    return Lastname;
}
int Accounts::get_Acctno()
{
    return Acct_no;
}
float Accounts::get_Balance()
{
    return Balance;
}
void Accounts::Deposit(float amount)
{
    Balance = Balance + amount;
}
void Accounts::Withdraw(float amount)
{
    Balance = Balance - amount;
}
void Accounts::set_LastAccountNo(int Acct_no)
{
    NextAcctNo=Acct_no;
}
int Accounts::get_LastAccoutNo()
{
    return NextAcctNo;
}

ofstream& operator<<( ofstream& ofs, Accounts& acc)
{
    ofs<<acc.Acct_no<<endl;
    ofs<<acc.Firstname<<endl;
    ofs<<acc.Lastname<<endl;
    ofs<<acc.Balance<<endl;
    return ofs;
}
ifstream& operator>>( ifstream& ifs, Accounts& acc)
{
    ifs>>acc.Firstname;
    ifs>>acc.Lastname;
    ifs>>acc.Acct_no;
    ifs>>acc.Balance;
    return ifs;
}

ostream & operator<<( ostream &  os, Accounts& acc)
{
    os<<"Firstname: "<<acc.get_Firstname()<<endl;
    os<<"Lastname: "<<acc.get_Lastname()<<endl;
    os<<"Acctno: "<<acc.get_Acctno()<<endl;
    os<<"Balance: "<<acc.get_Balance()<<endl;
    return os;
}

#endif // ACCOUNTS_H
