#pragma once

#include<iostream>
#include<iomanip>
#include<limits>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsShowCurrenciesList.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateRateScreen.h"
#include"clsCurrencyCalculator.h"


class clsCurrencyExchangeScreen : protected clsScreen
{
private : 
    enum enCurrencyExchangeOption
    {
        eListcurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalc = 4,
        eMainMenu = 5
    };

    static void _GoBack2CurrencyMenu()
    {
        cout << setw(37) << left << "" << "\t Press any Key to go back to Currency Menu...\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        ShowCurrencyExchangeScreen();

    }
    
    static short _ReadCurrencyExchangeOption()
    {
        short num; 
        cout << setw(37) << left << "" << "\t Choose what you want to do from [1 : 5]: ";
        num = clsInputValidate::ReadDblNumberBetween(1, 5, "\n\t\tNot Valid, Enter Number From 1 to 5: ");
        return num;
    }

    static void _ShowCurrenciesList()
    {
        // cout <<"\n\t List currencies screen will be here soon\n";
        clsShowCurrenciesList::ShowCurrenciesList();
    }

    static void _ShowFindCurrency()
    {
        // cout <<"\n\t Find currency screen will be here soon\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRate()
    {
        // cout << "\n\t Update Rate Screen will be here soon\n";
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }
    static void _ShowCurrencyCalculator()
    {
        // cout <<"\n\t Currency calculator screen will be here soon\n";
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
    }
    static void _ShowMainMenu()
    {
        cout <<"\n\t Main Menu will be here soon\n";
    }

    static void _PerformCurrencyExchangeMenu(enCurrencyExchangeOption option)
    {
        switch(option)
        {
            case enCurrencyExchangeOption::eListcurrencies : 
            {
                system("clear");
                _ShowCurrenciesList();
                _GoBack2CurrencyMenu();
                break;
            }
            case enCurrencyExchangeOption::eFindCurrency : 
            {
                system("clear");
                _ShowFindCurrency();
                _GoBack2CurrencyMenu();
                break;
            }
            case enCurrencyExchangeOption::eUpdateRate : 
            {
                system("clear");
                _ShowUpdateRate();
                _GoBack2CurrencyMenu();
                break;
            }
            case enCurrencyExchangeOption::eCurrencyCalc : 
            {
                system("clear");
                _ShowCurrencyCalculator();
                _GoBack2CurrencyMenu();
                break;
            }
            case enCurrencyExchangeOption::eMainMenu : 
            {

            }
        }
    }

public : 
     
    static void ShowCurrencyExchangeScreen()
    {
        system("clear");

        _DrawScreenHeader("\t  Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "\t================================================\n";
        cout << setw(37) << left << "" << "\t\t   Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "\t================================================\n";
        cout << setw(37) << left << "" << "\t [1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t [2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t [3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t [4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t [5] Main Menu.\n";
        cout << setw(37) << left << "" << "\t================================================\n";

        _PerformCurrencyExchangeMenu((enCurrencyExchangeOption)_ReadCurrencyExchangeOption());
    }
};