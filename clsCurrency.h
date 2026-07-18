#pragma once
#include<iostream>
#include<fstream>
#include"clsString.h"
#include<vector>


class clsCurrency
{
private : 
   enum enMode {EmptyMode = 1, UpdateMode = 2};
   
   enMode _Mode;
   string _Country; 
   string _CurrencyCode;
   string _CurrencyName;
   float _Rate;

   static clsCurrency _ConvertLine2CurrencyObject(string line, string seperator = "#//#")
   {
      vector<string> vCurrency = clsString::Split(line, seperator);
      return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3])); 

   }

   static string _ConvertCurrencyObject2Line(clsCurrency currency, string seperator = "#//#") 
   {
      string line = "";

      line += currency.GetCountry() + seperator; 
      line += currency.GetCurrencyCode() + seperator; 
      line += currency.GetCurrencyName() + seperator;
      line += to_string(currency.GetRate()); 

      return line;
   }

   static vector<clsCurrency> _LoadCurrencyFromFile()
   {
      vector<clsCurrency> vCurrency;

      fstream myFile; 
      myFile.open("Currency.txt", ios::in) ;// read & get data from file 

      if(myFile.is_open())
      {
         string line = "";
         while(getline(myFile, line))
         {
            clsCurrency CurrencyObject = _ConvertLine2CurrencyObject(line);
            vCurrency.push_back(CurrencyObject);
         }
         myFile.close();
      }

      return vCurrency; 

   }
   
   // save all currency data in file -> Loop on whole vector, save data line by line
   static  void _SaveCurrencyData2File(vector<clsCurrency> vCurrency)
   {
      fstream myFile;
      myFile.open("Currency.txt", ios::out);

      string line;

      if(myFile.is_open())
      {
         for(clsCurrency & c : vCurrency)
         {
            line = _ConvertCurrencyObject2Line(c);
            myFile << line << endl;
         }

         myFile.close(); 
      }
   }

   void _Update()
   {
      vector<clsCurrency> _vCurrency = _LoadCurrencyFromFile();

      for(clsCurrency & c : _vCurrency)
      {
         if(c.GetCurrencyCode() == GetCurrencyCode())
         {
            // this currency in the file (c) == the currency code for current object (this)
            c = *this;
            break;
         }
      }

      _SaveCurrencyData2File(_vCurrency);
   }

   static clsCurrency _GetEmptyCurrencyObject()
   {
      return clsCurrency(enMode::EmptyMode,  "", "", "", 0);
   }


public : 

   clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
   {
      _Mode = Mode; 
      _Country = Country;
      _CurrencyCode = CurrencyCode;
      _CurrencyName = CurrencyName; 
      _Rate = Rate;
   }

   bool IsEmpty()
   {
      return (_Mode == enMode::EmptyMode);
   }

   string GetCountry()
   {
      return _Country;
   }

   string GetCurrencyCode()
   {
      return _CurrencyCode;
   }

   string GetCurrencyName()
   {
      return _CurrencyName;
   }

   void UpdateRate(float newRate)
   {
      _Rate = newRate;
      _Update();
   }

   float GetRate()
   {
      return _Rate;
   }

   static clsCurrency FindByCode(string currencyCode)
   {
      currencyCode = clsString::UpperAllString(currencyCode);

      fstream myFile;
      myFile.open("Currency.txt", ios::in); 

      if(myFile.is_open())
      {
         string line = ""; 
          while(getline(myFile, line))
          {
             clsCurrency currencyObject = _ConvertLine2CurrencyObject(line);

             if(currencyObject.GetCurrencyCode() == currencyCode )
             {
                myFile.close();
                return currencyObject; 
             }
          }

         myFile.close();
      }

      return _GetEmptyCurrencyObject();
   }

   static clsCurrency FindByCountry(string country)
   {
      // country = clsString::UpperAllString(country);
      country = clsString::UpperFirstLetterOfEachWord(country);

      fstream myFile;
      myFile.open("Currency.txt", ios::in);

      if(myFile.is_open())
      {
         string line = "";
         while(getline(myFile, line))
         {
            clsCurrency currency = _ConvertLine2CurrencyObject(line);
            if(currency.GetCountry() == country)
            {
               myFile.close();
               return currency;
            }
         }
      }
       
      return _GetEmptyCurrencyObject();
   }

   static bool IsCurrencyExist(string currencycode)
   {
      clsCurrency crn = clsCurrency::FindByCode(currencycode);
      return (!crn.IsEmpty());
   }

   static vector<clsCurrency> GetCurrenciesList()
   {
      return _LoadCurrencyFromFile();
   }

   float Convert2USD(float amount)
   {
      return (float) amount / GetRate();
   }

   float Convert2OtherCurrency(float amount, clsCurrency currency2)
   {
      float Amount_In_USD = Convert2USD(amount);

      if(currency2.GetCurrencyCode() == "USD")
      {
         return Amount_In_USD;
      }
      return  (float) (Amount_In_USD * currency2.GetRate());
   }

}; 