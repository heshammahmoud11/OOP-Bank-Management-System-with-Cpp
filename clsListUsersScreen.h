#pragma once

#include<iostream> 
#include<iomanip> 
#include"clsUsers.h" 
#include"clsScreen.h"

using namespace std;


class clsListUsersScreen : protected clsScreen
{
private : 
    static void _PrintUserRecord(clsUsers user)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << user.GetUserName();
        cout << "| " << left << setw(25) << user.FullName(); 
        cout << "| " << left << setw(15) << user.GetPhone(); 
        cout << "| " << left << setw(20) << user.GetEmail(); 
        cout << "| " << left << setw(15) << user.GetPassword(); 
        cout << "| " << left << setw(15) << user.GetPermission(); 
    }

public :
   
    static void ShowListUsersScreen ()
    {
        vector<clsUsers> vUsers = clsUsers::GetUsersList();

        string title = "\t   List Users Screen";
        string subTitle =  "\t    ( " + to_string(vUsers.size()) + " ) User(s)";

        _DrawScreenHeader(title, subTitle);


        // build the list header

        cout <<setw(8) << left << "" << "\n\t------------------------------------------------------------";
        cout << "----------------------------------------------------------------\n";
        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(15) << "Permission";
        cout <<setw(8) << left << "" << "\n\t------------------------------------------------------------";
        cout << "----------------------------------------------------------------\n";
        // build the body of the list
        if(vUsers.size() == 0)
        {
            cout << "\t\t\t NO Users Available in the System!";
        }
        else
        {
            for(clsUsers & c : vUsers)
            {
                _PrintUserRecord(c);
                cout << endl;
            }
        }

        cout <<setw(8) << left << "" << "\n\t------------------------------------------------------------";
        cout << "----------------------------------------------------------------\n";


    }
};