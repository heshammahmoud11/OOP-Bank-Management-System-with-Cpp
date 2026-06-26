#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"


class clsDeleteClientScreen : protected clsScreen
{
private : 
    static void _PrintClient(clsBankClient client)
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

    static void DeleteClient()
    {

        _DrawScreenHeader("\t Delete Client Screen");

        string AccountNumber = "";
        cout << "\nEnter Account Number to Delete: ";
        AccountNumber = clsInputValidate::ReadString();

        while(!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Not Found, Enter another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintClient(client);

        cout << "\nAre You Sure Do You want to Delete This Client?[Y/N]: ";

        char ans = 'n';
        cin >> ans;

        if(tolower(ans) == 'y')
        {
            if(client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                // _PrintClient(client);
            }else
            {
                cout << "\nError, Client Was not Deleted\n";
            }
        }

    }
    
};