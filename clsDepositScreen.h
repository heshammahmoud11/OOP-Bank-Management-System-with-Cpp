#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
private : 

    static void _PrintClientInfo(clsBankClient client)
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

   static void ShowDepositScreen()
   {
      _DrawScreenHeader("\t Deposit Screen");

      string accountNumber; 
      cout << "Enter Account Number to Deposit: ";
      accountNumber = clsInputValidate::ReadString();

      while(!clsBankClient::IsClientExist(accountNumber))
      {
         cout <<"\t this account number not exist, enter another one : ";
         accountNumber = clsInputValidate::ReadString();
      }

      clsBankClient client = clsBankClient::Find(accountNumber);
      _PrintClientInfo(client);

      double amount = 0;
      cout << "\t Enter the Amount to Deposit: ";
      amount = clsInputValidate::ReadDblNumber();    

      
      cout <<"\n Are you sure you wanna peform this transaction?[Y/N] : ";
      char ans = 'n';
      cin >> ans;

      if(tolower(ans) == 'y') 
      {
         client.Deposit(amount);
         cout << "\n Amount Deposited Successfully\n";
         cout << "\n New Balance is : " << client.GetAccountBalance() << endl;
      }else 
      {
        cout << "\n Operation Was Cancelled\n";
      }
   }
};

