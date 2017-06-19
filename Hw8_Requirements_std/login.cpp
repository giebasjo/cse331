/*
 * File   : HashTable.cpp
 * Author : giebasjo (Jordan Giebas)
 * Class  : CSE331
 * Proj   : Hw8
 * Created on December 5, 2016, 5:03 PM
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "HashTable.cpp"

using namespace std;
//definition of your entity.
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

//split string method to get key / value separated
vector<string> split( string line ) {

    string buf; // Have a buffer string
    stringstream ss(line); // Insert the string into a stream

    vector<string> retVec; // Create vector to hold our words

    while (ss >> buf)
        retVec.push_back(buf);

    return retVec;

}


int main()
{
    //Needed
    HashTable<Password, string> passwords(8);
    Password tempPass;
    string name;      // user-supplied name
    string pass;      // user-supplied password
    bool userFound;   // is user in table?
    string success = "Authentication Success";
    string failure = "Authentication Failure";

    //first we need to read from the document password.dat
    string line;
    ifstream inputFile ("password.dat");
    if ( inputFile.is_open() ) {

        while ( getline (inputFile,line) ) {

            //line = username password
            vector<string> userPassPair = split(line);

            //create Password object: init username/password
            tempPass.username = userPassPair[0];
            tempPass.password = userPassPair[1];

            //add this password object to our HashTable
            passwords.insert( tempPass );

        }

    }

    else {

        cout << "Unable to open file";

    }

    //everything's in our hash table, let's now prompt the user for login success/failure
    while ( 1 ) {

        //Prompt & Obtain username/password pair
        cout << "Login: ";
        cin >> name;
        cout << "Password: ";
        cin >> pass;

        //Set tempPass member vars
        tempPass.username = name;
        tempPass.password = pass;

        //check for user response in hash table
        if ( passwords.retrieve( tempPass.getKey(), tempPass ) ) {

            cout << success << endl;

        }
        else {

            cout << failure << endl;

        }


    }

    //close file
    inputFile.close();

    return 0;

}

