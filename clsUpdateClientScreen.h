#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"


class clsUpdateClientScreen : public clsScreen
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
    static void UpdateClient()
    {
        _DrawScreenHeader("\t Update Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();


        // before find client -> check first if it exist in the file or not !
        while(!clsBankClient::IsClientExist(AccountNumber))
        {
            // only if client not exist, apply this code
            cout << "\nAccount Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        // client exist in the file
        clsBankClient client1 = clsBankClient::Find(AccountNumber); 
        _PrintClientInfo(client1);

        cout << "\nUpdate Client Info:";
        cout << "\n---------------------------\n";

        _ReadClientInfo(client1);

        clsBankClient::enSaveResults SaveResult = client1.Save();

        switch (SaveResult)
        {
            case clsBankClient::enSaveResults::svSucceeded : 
            {
                cout << "\nAccount Updated Successfully :-)\n";
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject : 
            {
                cout << "\nError Account was not saved because it's Empty\n";
                break;
            }
        }


    }


};