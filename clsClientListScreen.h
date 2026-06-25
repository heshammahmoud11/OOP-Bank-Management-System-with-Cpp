#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"iomanip"
using namespace std; 


class clsClientListScreen : protected clsScreen
{
private : 
    static void _PrintClientRecordLine(clsBankClient client)
    {
        cout << "| " << left << setw(15) << client.AccountNumber() ;
        cout << "| " << left << setw(25) << client.FullName() ;
        cout << "| " << left << setw(15) << client.GetPhone() ;
        cout << "| " << left << setw(25) << client.GetEmail() ;
        cout << "| " << left << setw(15) << client.GetPinCode() ;
        cout << "| " << left << setw(15) << client.GetAccountBalance();
    }

public : 

    void static ShowClientsList()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string title = "\t Client List Screen";
        string subTitle = "\t   ( " + to_string(vClients.size()) + " ) Client";

        clsScreen::_DrawScreenHeader(title, subTitle);
        

        cout <<"\n--------------------------------------------------------------------";
        cout << "-----------------------------------------------------------------\n" << endl;
        
        // Create List Header

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(25) << "Client Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(15) << "Pin Code";
        cout << "| " << left << setw(15) << "Balance";

        cout << "\n--------------------------------------------------------------------";
        cout << "-----------------------------------------------------------------\n" << endl;
        
        if(vClients.size() == 0)
        {
            cout << "\n\t\tthere is no clients available in the system!\n";
        }
        else
        {
            for(clsBankClient & c : vClients)
            {
                _PrintClientRecordLine(c);
                cout << endl;
            }
        cout <<"\n--------------------------------------------------------------------";
        cout << "-----------------------------------------------------------------\n" << endl;
        
        }

    }

};


