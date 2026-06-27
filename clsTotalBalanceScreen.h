#pragma once 

#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtil.h"
#include<iomanip>



class clsTotalBalanceScreen : protected clsScreen
{

private : 

    static void PrintClientRecordBalanceLine(clsBankClient client)
    {
        cout << "| " << left << setw(20) << client.AccountNumber();
        cout << "| " << left << setw(20) << client.FullName();
        cout << "| " << left << setw(20) << client.GetAccountBalance();        
    }

public :
   static void ShowTotalBalanceScreen()
   {
    _DrawScreenHeader("\t Show Total Balance Screen");

    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\tBalances List ( " << vClients.size() << " ) client\n";

    cout << "\n--------------------------------------------------------------------";
    cout << "------------------------\n";

    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(20) << "Balance";

    cout << "\n------------------------------------------------------------------";
    cout << "--------------------------\n";

    double TotalBalance = clsBankClient::GetTotalBalances();

    if(vClients.size() == 0)
    {
        cout << "\t\t\tThere is no Clients avaiable in the system\n";
    }else
    {
        for(clsBankClient & c : vClients)
        {
            PrintClientRecordBalanceLine(c); 
            cout << endl;
        }
    }
    cout << "\n---------------------------------------------------------------------";
    cout << "------------------------\n";

    cout << "\t\t\t Total Balances = " << TotalBalance << endl;
    cout << "\t\t\t ( " << clsUtil::NumberToText(TotalBalance) << " ) "<< endl;
   }
};