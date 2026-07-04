#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include<limits>
#include<iomanip>
#include"clsTotalBalanceScreen.h"

class clsTransactionMenuScreen : protected clsScreen
{
private : 
    enum enTransactionMenu 
    {
        eDiposit = 1, eWithdraw = 2,
        eTotalBalance = 3, eGoToMainMenu = 4
    };

    static short ReadTransactionMenuOption()
    {
        short num;
        cout << setw(37) << left << "" << "\tEnter a Number between [1 - 4] : ";
        num = clsInputValidate::ReadIntNumberBetween(1, 4);

        return num;

    }

    static void _GoBack2TransactionMenu()
    {
        cout << "\n" << setw(37) << left << "" << "\tPress Any key to go back to transactin menu\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        ShowTransactionMenuScreen();
    }

    static void _ShowDepositSecreen()
    {
        clsDepositScreen::ShowDepositScreen(); 
    }

    static void _ShowWithDrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen(); 
    }

    static void _ShowTotalBalanceScreen()
    {
        // cout << "Total Balance Screen will be here soon\n";
        clsTotalBalanceScreen::ShowTotalBalanceScreen();
        

    }
    
    static void _GoBack2MainMenu()
    {
        
    }


    // this is the API will attach between (frot end & back end)

    static void _PerformTransactionMenuScreen(enTransactionMenu option)
    {
        switch(option)
        {
            case enTransactionMenu::eDiposit : 
            {
                system("clear");
                _ShowDepositSecreen();
                _GoBack2TransactionMenu();
                break;
            }
            case enTransactionMenu::eWithdraw : 
            {
                system("clear");
                _ShowWithDrawScreen();
                _GoBack2TransactionMenu();
                break;
            }
            case enTransactionMenu::eTotalBalance :
            {
                system("clear");
                _ShowTotalBalanceScreen();
                _GoBack2TransactionMenu();
                break;
            }
            case enTransactionMenu::eGoToMainMenu :
            {
                // _GoBack2MainMenu();
                // break;
            }
        }
    }

public : 

    static void ShowTransactionMenuScreen()
    {

        if(!CheckAccessRights(clsUsers::enPermission::pTransactions))
        {
            return;
        }

        cout << system("clear");
        clsScreen::_DrawScreenHeader("\t Transaction Menu Screen");

        cout <<setw(37) << left << "" << "===================================================\n";
        cout <<setw(37) << left << "" << "\t\t Transaction Menu\n";
        cout <<setw(37) << left << "" << "===================================================\n";
        cout <<setw(37) << left << "" << "\t[1] Deposit\n";
        cout <<setw(37) << left << "" << "\t[2] WithDraw\n";
        cout <<setw(37) << left << "" << "\t[3] Total Balance\n";
        cout <<setw(37) << left << "" << "\t[4] Go Back to Main Menu\n";
        cout <<setw(37) << left << "" << "===================================================\n";

        _PerformTransactionMenuScreen((enTransactionMenu) ReadTransactionMenuOption());
    }

}; 