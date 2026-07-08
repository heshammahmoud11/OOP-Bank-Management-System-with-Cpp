#pragma once

#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsUsers.h"
#include"clsScreen.h"

using namespace std;


class clsAddNewUserScreen : protected clsScreen
{
private : 
   static void _ReadUserInfo(clsUsers & user)
   {
     cout << "\t## Enter User Info\n";

     cout << "\t Enter the First name: ";
     user.SetFirstName(clsInputValidate::ReadString());

     cout << "\t Enter the last Name: ";
     user.SetLastName(clsInputValidate::ReadString());

     cout << "\t Enter the Email: ";
     user.SetEmail(clsInputValidate::ReadString());

     cout << "\t Enter The Phone: ";
     user.SetPhone(clsInputValidate::ReadString());


     cout << "\t Enter the Password: ";
     user.SetPassword(clsInputValidate::ReadString());

     cout << "\t Enter the Permission: ";
     user.SetPermission(_ReadPermission2Set());
   }

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

   static int _ReadPermission2Set()
   {
       int permission = 0;
       char ans = 'n';

       cout << "\nDo You Want to give Full Access ? [Y/N] : ";
       cin >> ans;
       if(tolower(ans) == 'y')
       {
          return -1;
       }

        cout << "\nDo you want to give access to : \n";

        cout << "\nShow Client List ? [Y/N] :"; 
        cin >> ans;
        if(tolower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pListClients;
        }

        cout << "\nAdd New Client ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pAddNewClient; 
        }

        cout << "\nDelete Client ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pDeleteClient; 
        }
        cout << "\nUpdate Client ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pUPdateClient; 
        }

        cout << "\nFind Client ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pFindClient; 
        }

        cout << "\nTransactions ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pTransactions; 
        }

        cout << "\nManage Users ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pManageUsers; 
        }

        cout << "\nRegister Login ? [Y/N] : ";
        cin >> ans;
        if(towlower(ans) == 'y')
        {
            permission += clsUsers::enPermission::pRegisterLogin; 
        }

        return permission;
   }

public : 
    static void ShowAddNewUserScreen()
    {
        system("clear");

        _DrawScreenHeader("\t  Add New User Screen");

        string username = ""; 
        cout << setw(8) << left << "" << "Enter user name: ";
        username = clsInputValidate::ReadString();

        while(clsUsers::IsUserExist(username))
        {
            cout << "\tThis User Aleardy Exist, Please Enter Another One : ";
            username = clsInputValidate::ReadString(); 

        }

        clsUsers user = clsUsers::GetAddNewUserObject(username);
        _ReadUserInfo(user);

        // save data in file

        clsUsers::enSaveResults SaveUser = user.Save();


        switch (SaveUser)
        {
            case clsUsers::enSaveResults::svSucceded : 
            {
                cout << "\n\t User Added Successfully -:)\n";
                _PrintUser(user);
                break;
            }
            case clsUsers::enSaveResults::svFaildEmptyObject : 
            {
                cout << "\t Error, User Not Saved because it's Empty\n"; 
                break;
            }
            case clsUsers::enSaveResults::svFaildUserExist : 
            {
                cout << "\tUser Not Saved, it's Already Used!\n";
                break;
            }
        }

    }
};