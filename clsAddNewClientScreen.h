#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"


class clsAddNewClientScreen : protected clsScreen
{
private : 
   static void _ReadClientInfo(clsBankClient &client)
    {
        cout << "\nEnter First Name  : ";
        client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Last Name: ";
        client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email : ";
        client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone : ";
        client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Pin Code: ";
        client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance : ";
        client.SetAccountBalance(clsInputValidate::ReadfloatNumber());
    }

    static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.GetFirstName();
        cout << "\nLastName    : " << client.GetLastName();
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.GetEmail();
        cout << "\nPhone       : " << client.GetPhone();
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.GetPinCode();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";

    };

    

public : 
   
   static void AddNewClient()
   {
      clsScreen::_DrawScreenHeader("\t Add New client Screen");

      string clientNumber = "";
      cout << "Enter the Client Number: ";
      clientNumber = clsInputValidate::ReadString();


      while(clsBankClient::IsClientExist(clientNumber))
      {
         cout <<"\nThis Client Number already exist, please enter another one\n";
         clientNumber = clsInputValidate::ReadString();
      }

      // read client info from the user

      clsBankClient client = clsBankClient::GetAddNewClientObject(clientNumber);
      _ReadClientInfo(client);

      // save data in the file

      clsBankClient::enSaveResults saveClient = client.Save();

      switch(saveClient)
      {
        case clsBankClient::enSaveResults::svSucceeded : 
        {
            cout << "\nAccount Addedd Successfully:-)\n";
            _PrintClient(client); 
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject : 
        {
            cout << "\nError, Account was not save because it's Empty\n";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists :
        {
            cout << "\nError, Account was not save becasuse Account number is used!\n";
            break;
        }
      }

   }
   
}; 