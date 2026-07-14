#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"


class clsTransferLogScreen : protected clsScreen
{
private : 
    static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecord log)
    {
        cout << "\t\t| " << left << setw(25) << log.DateTime;
        cout << "| " << left << setw(12) << log.SourceClient;
        cout << "| " << left << setw(12) << log.DestinationClient;
        cout << "| " << left << setw(12) << log.amount;
        cout << "| " << left << setw(15) << log.srcBalance;
        cout << "| " << left << setw(15) << log.destBalance;
        cout << "| " << left << setw(12) << log.userName;
    }

public : 
   
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTransferLogRecord> vTranferLog = clsBankClient::GetTransferLogList();


        string title = "\t Transfer Log Screen";
        string subTit = "\nt Transfer Log List Screen ( " + to_string(vTranferLog.size()) + " ) Record(s)\n";

       _DrawScreenHeader(title, subTit);

      cout << "\n\t\t----------------------------------------------------------------------";
      cout << "---------------------------------------------------\n";

      // Create the Table Header
      cout <<"\t\t| " << left << setw(25) << "Date & Time";
      cout <<"| " << left << setw(12) << "Src Client";
      cout <<"| " << left << setw(12) << "Dest Client";
      cout <<"| " << left << setw(12) << "Amount";
      cout <<"| " << left << setw(15) << "Src Balance";
      cout <<"| " << left << setw(15) << "Dest Balance";
      cout <<"| " << left << setw(12) << "UserName";

      cout << "\n\t\t----------------------------------------------------------------------";
      cout << "----------------------------------------------------\n";

      if(vTranferLog.size() == 0)
      {
        cout <<"\n\t\t No Transfer Logs Available\n";
      }else
      {
         for(clsBankClient::stTransferLogRecord & c : vTranferLog)
         {
            _PrintTransferLogRecord(c);
            cout << endl;
         }
      }

      
      cout << "\n\t\t----------------------------------------------------------------------";
      cout << "---------------------------------------------------\n";
      
      
    }
};