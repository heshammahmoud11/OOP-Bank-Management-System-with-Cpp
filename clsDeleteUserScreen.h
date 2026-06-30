#pragma once

#include<iostream>
#include"clsUsers.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsDeleteUserScreen : protected clsScreen
{
private : 
   static void _PrintUser(clsUsers user)
   {
       cout << "\t ## User Info Card\n";
       cout << "\t _________________________\n";
       cout << "\t User First Name: " << user.GetFirstName() << endl;
       cout << "\t User Last  Name: " << user.GetLastName() << endl;
       cout << "\t User Phone     : " << user.GetPhone() << endl;
       cout << "\t User Email     : " << user.GetEmail() << endl;
       cout << "\t User Password  : " << user.GetPassword() << endl;
       cout << "\t User Permission: " << user.GetPermission() << endl;
       cout << "\t _________________________\n";
   }
public : 
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t  Delete User Screen");

        string username = "";
        cout << "\t Enter the UserName : ";
        username  = clsInputValidate::ReadString();

        while(!clsUsers::IsUserExist(username))
        {
            cout << "\n\t User is Not Exist, Enter another one: ";
            username = clsInputValidate::ReadString();
        }

        clsUsers user = clsUsers::Find(username);
        _PrintUser(user);
        
        char ans = 'n';
        cout << "\n\t Are You Sure You want to Delete This User? [Y/N]: ";
        cin >> ans;

        if(tolower(ans) == 'y')
        {
            if(user.Delete())
            {
                cout << "\n\t User Deleted Successfully -:) \n";
            }
            else
            {
                cout << "\n\t Error, User Was not Deleted!\n";
            }
        }

    }
}; 