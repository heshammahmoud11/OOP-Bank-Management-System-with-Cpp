#pragma once
#include<iostream> 
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"


class clsCurrencyCalculator : protected clsScreen
{
private:
    static void _PrintCurrencyRecord(clsCurrency currency, string str = "Currency Card: ")
    {
        cout << "\n\t## Currency Card ##\n";
        cout <<"\t-----------------------------------\t\n";
        cout << "\t Country : " << currency.GetCountry() << endl; 
        cout << "\t Currency Code : " << currency.GetCurrencyCode() << endl; 
        cout << "\t Currency Name : " << currency.GetCurrencyName() << endl; 
        cout << "\t Currency Rate : " << currency.GetRate() << endl; 
        cout <<"\t-----------------------------------\t\n";
    }

    static clsCurrency _GetCurrency(string message)
    {
        string currencyCode = "";
        cout << message ;

        currencyCode = clsInputValidate::ReadString();

        while(!clsCurrency::IsCurrencyExist(currencyCode))
        {
            cout << "\nt\t Currency is not Found, Choose another one: ";
            currencyCode = clsInputValidate::ReadString();
        }

        clsCurrency currency = clsCurrency::FindByCode(currencyCode); 
        return currency;
    }

    static float _ReadAmount()
    {
        float num = 0; 
        cout << "\n\t Enter Amount to Exchange: ";
        num = clsInputValidate::ReadfloatNumber(); 

        return num;
    }

    static void _PrintCalculationsResult(float amount, clsCurrency currency1, clsCurrency currency2)
    {
        _PrintCurrencyRecord(currency1);
        float Amount_In_USD = currency1.Convert2USD(amount);
        cout << "\n\t " << amount << " " << currency1.GetCurrencyCode() << " = " << Amount_In_USD << " USD\n";

        if(currency2.GetCurrencyCode() == "USD")
        {
            return;
        }

        cout << "\n\t Convert From USD to: \n"; 
        _PrintCurrencyRecord(currency2);

        float currency2Amount = currency1.Convert2OtherCurrency(Amount_In_USD, currency2); 
        cout << "\n\t " << amount << " " << currency1.GetCurrencyCode() << " = " << currency2Amount << " " << currency2.GetCurrencyCode();
    }

public : 

   static void ShowCurrencyCalculatorScreen()
   {
     _DrawScreenHeader("\t Currency Calculator Screen");

     char ans = 'y';

     while(tolower(ans) == 'y')
     {
        clsCurrency currency1 = _GetCurrency("\n\t Enter Amount to Convert From: ");
        clsCurrency currency2 = _GetCurrency("\n\t Enter Amount to Convert To: ");
        float amount = _ReadAmount();

        _PrintCalculationsResult(amount, currency1, currency2); 

        cout << "\n\t Do You want to Perform Another Calculations? [Y/N]: "; 
        cin >> ans;
     }
     
    }
};