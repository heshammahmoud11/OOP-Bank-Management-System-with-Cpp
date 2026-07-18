#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"


class clsFindCurrencyScreen : protected clsScreen
{
private : 
    static void _PrintCurrencyRecord(clsCurrency currency)
    {
        cout << "\n\t## Currency Card ##\n";
        cout <<"\t-----------------------------------\t\n";
        cout << "\t Country : " << currency.GetCountry() << endl; 
        cout << "\t Currency Code : " << currency.GetCurrencyCode() << endl; 
        cout << "\t Currency Name : " << currency.GetCurrencyName() << endl; 
        cout << "\t Currency Rate : " << currency.GetRate() << endl; 
        cout <<"\t-----------------------------------\t\n";
    }

      
    static void _ShowResult(clsCurrency currency)
    {
        if(currency.IsEmpty())
        {
            cout << "\n\tCurrency is Not Exist -:( \n";
        }
        else
        {
            cout <<"\n\t Currency Found -:)\n";
            _PrintCurrencyRecord(currency);
        }
    }
public : 

    static void ShowFindCurrencyScreen()
    {
        system("clear");

        _DrawScreenHeader("\t  Find Currency Screen\n");

        int num; 
        cout << "\t Find By : [1] Currency Code | [2] Currency Name: ";
        cin >> num;

        if(num == 1)
        {
            cout << "\n\t Please Enter Currency Code: ";
            string code = "";
            code = clsInputValidate::ReadString();

            clsCurrency currency = clsCurrency::FindByCode(code);
            _ShowResult(currency);
        }
        else
        {
            cout << "\n\t Please Ener Country Name: ";
            string name = "";
            name = clsInputValidate::ReadString();

            clsCurrency currency = clsCurrency::FindByCountry(name);
            _ShowResult(currency);
        }
    }
}; 