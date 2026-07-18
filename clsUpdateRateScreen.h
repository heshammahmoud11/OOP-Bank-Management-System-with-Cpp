#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsUpdateRateScreen : protected clsScreen
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

    static float _ReadRate()
    {
        float num = 0;
        cout <<"\n\tEnter a New Rate: ";
        num = clsInputValidate::ReadfloatNumber();
        return num;
    }
public : 

   static void ShowUpdateRateScreen()
   {
      system("clear");

      _DrawScreenHeader("\t  Update Rate Screen");

      cout << "\n\t Enter the Currency Code : "; 
      string code = "";
      code = clsInputValidate::ReadString();

      while(!clsCurrency::IsCurrencyExist(code))
      {
        cout <<"\n\t Currency is Not Exist, Enter Currency code Again: ";
        code = clsInputValidate::ReadString();
      }

      clsCurrency currency = clsCurrency::FindByCode(code);
      _PrintCurrencyRecord(currency);

      cout << "\n\t Are you Sure you wanna Update the Rate of this Currency ? [Y/N] : ";
      char ans = 'n';
      cin >> ans;

      if(tolower(ans) == 'y')
      {
        cout <<"\n\t##UPdate Current Rate\n";
        cout <<"\t---------------------\n";

        currency.UpdateRate(_ReadRate());

        cout << "\n\t Currency Rate Updated Successfully\n"; 
        _PrintCurrencyRecord(currency); 
      }
   }
}; 