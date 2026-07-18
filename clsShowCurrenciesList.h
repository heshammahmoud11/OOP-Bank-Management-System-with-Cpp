#pragma once

#include<iostream> 
#include<iomanip> 
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"


class clsShowCurrenciesList : protected clsScreen
{
private : 
    static void _PrintCurrencyRecord(clsCurrency currency)
    {
        cout << "| " << left << setw(30) << currency.GetCountry();
        cout << "| " << left << setw(15) << currency.GetCurrencyCode();
        cout << "| " << left << setw(40) << currency.GetCurrencyName();
        cout << "| " << left << setw(12) << currency.GetRate();
    }

public : 
    
    static void ShowCurrenciesList()
    {
        system("clear");

        vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string title = "\t  Currencies List Screen\n";
        string subTit = "\t  Number of Currencies is ( " + to_string(vCurrency.size()) + " ) Currency(s)\n";

        _DrawScreenHeader(title, subTit);

        cout <<"\n--------------------------------------------------------------------------------";
        cout <<"---------------------------------------\n";

        // Create Header of Table
        cout << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(15) << "Currency Code";
        cout << "| " << left << setw(40) << "Currency Name";
        cout << "| " << left << setw(12) << "Rate ($)";

        cout <<"\n--------------------------------------------------------------------------------";
        cout <<"------------------------------------\n";

        if(vCurrency.size() == 0)
        {
            cout << setw(20) << "\t No Currencies Avaliable in the Table\n";
        }else
        {
            for(clsCurrency & c : vCurrency)
            {
                _PrintCurrencyRecord(c);
                cout << endl;
            }
        }
        cout <<"\n--------------------------------------------------------------------------------";
        cout <<"-------------------------------------\n";

    }
};