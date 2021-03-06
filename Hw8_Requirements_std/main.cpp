
#include <iostream>
#include <cmath>
#include "HashTable.cpp"

using namespace std;

struct Account
{
    int acctNum;              // (Key) Account number
    float balance;            // Account balance

    int getKey () const { return acctNum; }
    static unsigned int hash(const int& key) { return abs( key ); }

};

struct Password
{
    void setKey ( string newKey ) { username = newKey; }
    string getKey () const { return username; }
    static unsigned int hash(const string& str)
    {
        int val = 0;

        for (int i=0; i<str.length(); i++)
            val += str[i];
        return val;
    }
    string username, password;
};

/*
int main() {


    HashTable<Account,int> accounts(11);    // List of account
    Account acct;                         // A single account

    int searchKey;                        // An account key

    // Read in information on a set of accounts.

    cout << endl << "Enter account information (acct_num balance) for 5 accounts: " << endl;

    for ( int i = 0; i < 5; i++ )
    {
        cin >> acct.acctNum >> acct.balance;
        accounts.insert(acct);
    }

    // Checks for accounts and prints records if found

    cout << endl;
    cout << "Enter account number (<EOF> to end): ";

    //WARNING ! Uncomment the following when testing...
    while ( cin >> searchKey )
    {
       if ( accounts.retrieve(searchKey,acct) )
           cout << acct.acctNum << " " << acct.balance << endl;
       else
           cout << "Account " << searchKey << " not found." << endl;
    }


    return 0;


}
*/
