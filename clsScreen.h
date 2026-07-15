#pragma once

#include<iostream>
#include"Global.h"
#include"clsDate.h"
using namespace std;



class clsScreen
{
protected :
  static void _DrawScreenHeader(string title, string subTitle = " ")
  {
    cout << "\t\t\t\t\t-------------------------------------------";
    cout << "\n\n\t\t\t\t\t   "<< title;

    if(subTitle != "")
    {
        cout << "\n\t\t\t\t\t " << subTitle;
    }

    cout << "\n\t\t\t\t\t------------------------------------------\n";

    // Add Logedin User & Current Date

    cout << "\n\t\t\t\t\t User: " << CurrentUser.GetUserName() << endl;
    cout << "\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n\n";
  }

  static bool CheckAccessRights(clsUsers::enPermission permission)
  {
    if(!CurrentUser.CheckAccessPermission(permission)) 
    {
        cout << "\t\t\t\t\t__________________________________________\n\n";
        cout << "\t\t\t\t\t      Access Denied! Contact Your Admin.\n";
        cout << "\t\t\t\t\t__________________________________________\n\n";

        return false;
    }
    else 
        return true;
  }
};

