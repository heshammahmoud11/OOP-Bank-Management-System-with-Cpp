#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsDate.h"


class clsRegisterLoginScreen : protected clsScreen
{
private : 
    static void _PrintUserLoginRecord(clsUsers::stUserRecord userRecord)
    {
        cout << "\t\t| " << left << setw(20) << userRecord.DateTime;
        cout << "\t\t| " << left << setw(20) << userRecord.UserName;
        cout << "\t\t| " << left << setw(20) << userRecord.Password;
        cout << "\t\t| " << left << setw(10) << userRecord.Permission;
    }

public :

    static void ShowRegisterLogin()
    {

        if(!CheckAccessRights(clsUsers::enPermission::pRegisterLogin))
        {
            return;
        }


        vector<clsUsers::stUserRecord> vLoginUsers = clsUsers::GetUserLoginList();

        string title = "\t Login Register List Screen\n";
        string subTit = "\t Number is " + to_string(vLoginUsers.size()) + " User\n";
        // string subTitle = "\t adf " << vUsers.size() << " Register(s)\n";

        _DrawScreenHeader(title, subTit);

        cout << "\n\t\t---------------------------------------------------------------";
        cout << "------------------------------------------------------------------\n";

        // Create Screen Heaser

        cout << "\t\t| " << left << setw(20) << "Date/Time";
        cout << "\t\t| " << left << setw(20) << "UserName";
        cout << "\t\t| " << left << setw(20) << "Password";
        cout << "\t\t| " << left << setw(10) << "Permissino";

        cout << "\n\t\t---------------------------------------------------------------";
        cout << "------------------------------------------------------------------\n";

        if(vLoginUsers.size() == 0)
        {
            cout <<"\n\t No Users Login to the System Right Now.!\n";
        }else
        {
            for(clsUsers::stUserRecord & c : vLoginUsers)
            {
                _PrintUserLoginRecord(c);
                cout << endl;
            }
        }
        cout << "\n\t\t---------------------------------------------------------------";
        cout << "------------------------------------------------------------------\n";


    }

};