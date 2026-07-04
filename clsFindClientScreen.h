#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
{
private: 
    static void _PrintclientInfo(clsBankClient client)
    {
        cout << "\n## Client Record\n";
        cout << "________________________\n";
        cout << "client Name : " << client.GetFirstName() << endl;
        cout << "Account Number: " << client.GetLastName() << endl;
        cout << "Email : "      << client.GetEmail() << endl;
        cout << "Phone Number: " << client.GetPhone() << endl;
        cout << "Account Number: " << client.AccountNumber() << endl;
        cout << "Pin Code: " << client.GetPinCode() << endl;
        cout << "Balance: " << client.GetAccountBalance() << endl;
    }

public : 
   static void FindClientScreen()
   {

        if(!CheckAccessRights(clsUsers::enPermission::pFindClient))
        {
            return;
        }

      _DrawScreenHeader("Find Client Screen");

      string accountNumber;
      cout << "Please Enter The Account Number: ";
      accountNumber = clsInputValidate::ReadString();

      // if account number not found
      while(!clsBankClient::IsClientExist(accountNumber))
      {
         cout << "\nAccount Number Not exist, please enter another one? ";
         accountNumber = clsInputValidate::ReadString();
      }

      // Search about the account Num in the file
      // this function will return an Object from file(full of info / or empty object)
      clsBankClient client = clsBankClient::Find(accountNumber);

      if(!client.IsEmpty())
      {
        cout << "\nClient Found :-)\n"; 
      }else 
      {
        cout << "\nClient was not found :-(\n"; 
      }

      _PrintclientInfo(client);

   }

};