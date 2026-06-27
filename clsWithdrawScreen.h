#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iomanip>


class clsWithdrawScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string accountNumber = "";
        cout << setw(37) << left << "" << "Please, Enter Account Number: ";
        cin >> accountNumber;
        return accountNumber; 
    }

public : 
    
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t WithDraw Screen");


        string accountNumber = _ReadAccountNumber();

        while(!clsBankClient::IsClientExist(accountNumber))
        {
            cout << setw(37) << left << "" << "This Account [ " << accountNumber << " ] Not Exist, enter another one: \n";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(accountNumber);
        _PrintClientInfo(client);

        double amount = 0;
        cout << setw(37) << left << "" << "Enter the Amount to Withdraw: ";
        amount = clsInputValidate::ReadDblNumber();

        cout << setw(37) << left << "" << "Are you sure you wanna withdraw this amount? [Y/N]: ";
        char ans = 'n';
        cin >> ans;

        if(tolower(ans) == 'y')
        {
            // sufficient amount
            if(client.Withdraw(amount))
            {
                // cout << setw(37) << left << "" << "The Amount completed succesffully";
                cout << "The Amount completed succesffully \n";
                // cout << setw(37) << left << "" << "The New Balance is : " << client.GetAccountBalance();
                cout  << "The New Balance is : " << client.GetAccountBalance() << endl;
            }
            else
            {
                cout << setw(37) << left << "" << "\nInsufficient Amount\n";
                cout << setw(37) << left << "" << "\nThe Amount to withdraw: "<<  amount << endl;
                cout << setw(37) << left << "" << "\nYour Acual Balance is: "<<  client.GetAccountBalance() << endl;

            }
          
        }
        else {
            cout << setw(37) << left << "" << "The Operation was Cancelled";
        }
    }
    
}; 