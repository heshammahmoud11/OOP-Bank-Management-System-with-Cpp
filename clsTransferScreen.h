#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"Global.h"



class clsTransferScreen : protected clsScreen
{

private : 
     static void _PrintClientCard(clsBankClient client)
     {
        cout <<"\n\t\t ## Client Card ##\n";
        cout <<"\t\t________________________________\n";
        cout << "\n\t\t Full Name     : " << client.FullName()  << endl;
        cout << "\t\t AccountNumber : " << client.AccountNumber()  << endl;
        cout << "\t\t Balance       : " << client.GetAccountBalance()  << endl;
        cout <<"\t\t________________________________\n";
     }

     static string _ReadAccountNumber(string messg)
     {
        string accNum;
        cout << messg; 
        accNum = clsInputValidate::ReadString(); 

        while(!clsBankClient::IsClientExist(accNum))
        {
            cout << "\n\t\t This Account Number is Not Exist, Enter another one: ";
            accNum = clsInputValidate::ReadString();
        }

        return accNum;
     }

     static float _ReadAmount(clsBankClient SourceClient)
     {
        float amount; 
        cout <<"\n\t\t Enter Transfer Amount : ";
        amount = clsInputValidate::ReadfloatNumber();

        while(amount > SourceClient.GetAccountBalance())
        {
            cout << "\n\t\t Amount Exceeds the available balance, Enter another Amount: ";
            amount = clsInputValidate::ReadDblNumber();   
        }

        return amount;

     }

public : 
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t\t Transfer Screen\n");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\t Enter Account Number to Transfer From: "));
        _PrintClientCard(SourceClient); 


        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\t Enter Account Number to Transfer To: "));
        _PrintClientCard(DestinationClient); 

         
        float amount = _ReadAmount(SourceClient);

        char ans = 'n';
        cout <<"\n\t\t Are you Sure You want to Perform This Operation ?[Y/N] : ";
        cin >> ans;

        if(tolower(ans) == 'y')
        {
            if(SourceClient.Transfer(amount, DestinationClient, CurrentUser.GetUserName()))
            {
                cout <<"\n\t\t Transfer Done Successfully\n";

                // here i will add register login for  any transfer operation

            }else
            {
                cout << "\n\t\t Transfer Faild\n";
            }
        }

        _PrintClientCard(SourceClient);
        _PrintClientCard(DestinationClient);


    }
};