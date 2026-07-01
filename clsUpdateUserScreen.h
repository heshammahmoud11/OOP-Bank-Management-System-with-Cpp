#pragma once

#include<iostream>
#include"clsUsers.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsUpdateUserScreen :  protected clsScreen
{
private  : 
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

    static void _ReadUserInfo(clsUsers & user)
    {
        cout << "Enter First Name : ";
        user.SetFirstName(clsInputValidate::ReadString());

        cout << "Enter Last Name: " ;
        user.SetLastName(clsInputValidate::ReadString());

        cout << "Enter Email " ;
        user.SetEmail(clsInputValidate::ReadString());

        cout << "Enter Phone : " ;
        user.SetPhone(clsInputValidate::ReadString());

        cout  << "Enter password: " ;
        user.SetPassword(clsInputValidate::ReadString());

        cout << "Enter permissin: " ;
        _ReadPermission2Set();
        
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

        return permission;
   }


public : 

    static void ShowUpdateUserScreen()
    {
        // system("clear");

        _DrawScreenHeader("\t  Update User Screen");

        string username = "";
        cout << "\t Enter User Name to Update : ";
        username = clsInputValidate::ReadString();

        while(!clsUsers::IsUserExist(username))
        {
            cout << "\n\t The User is Not Exist, Enter another one: ";
            username = clsInputValidate::ReadString();
        }

        clsUsers user = clsUsers::Find(username);
        _PrintUser(user);

        char ans = 'n';
        cout << "\n\t Are you sure you want to Update this User? [Y/N]: ";
        cin >> ans;

        if(tolower(ans) == 'y')
        {
            cout << "\n\t Update User Info\n";
            cout << "-----------------------------\n";

            _ReadUserInfo(user);

            // save user in file
            
            clsUsers::enSaveResults SaveUser = user.Save(); 

            switch(SaveUser)
            {
                case  clsUsers::enSaveResults::svSucceded :
                {
                    cout << "\n\t User Updated Successfully.\n";
                    _PrintUser(user); 
                    break ;
                }
                case clsUsers::enSaveResults::svFaildEmptyObject : 
                {
                    cout << "\n\tError, User Can't Updated \n";
                    break;
                }
            }
        }

    }


};