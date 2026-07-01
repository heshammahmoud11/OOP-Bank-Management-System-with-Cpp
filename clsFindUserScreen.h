#pragma once

#include<iostream> 
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUsers.h"

class clsFindUserScreen : protected clsScreen
{
    static void _PrintUser(clsUsers user)
    {
        cout << "\n\t ## User Info Card\n";
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
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find Use Screen");

        string username = "";
        cout << "\n\t Enter User Name : ";
        username  = clsInputValidate::ReadString();

        while(!clsUsers::IsUserExist(username))
        {
            cout <<"\n\tThe User Name Not Exist, Enter another one: ";
            username = clsInputValidate::ReadString();
        }

        clsUsers user = clsUsers::Find(username);
        
        if(!user.isEmpty())
        {
            cout << "\n\t User Found -:)\n";
        }else
        {
            cout << "\n\t User Was not Found -:(\n";
        }

        _PrintUser(user);

    }
}; 