
#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsUtil.h"
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionMenuScreen.h"
#include"clsManageUserScreen.h"
#include"Global.h"
#include"clsRegisterLoginScreen.h"
#include"clsCurrencyExchangeScreen.h"
using namespace std; 



// clsMainScreen inherited protectedly from clsScreen class (all public and protected calss in clsCreen) will be protected in (clsMainScreen)
class clsMainScreen : protected clsScreen
{
private :
    enum enMainMenuOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionMenu = 6,
        eManageUsers = 7, eRegisterLogin = 8,  eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 - 10] : ";
        short number = clsInputValidate::ReadDblNumberBetween(1, 9, "Enter Number From 1 to 10:  ");
        return number;
    }

    static void _GoBackToMainMenu()
    {
        cout << "\n" << setw(37) << left << "" << "\tPress any key to go back to Main Menu...\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        ShowMainMenu();
    }

    static void _ShowAllClientsListScreen()
    {
        clsClientListScreen::ShowClientsList();
    }
    
    static void _ShowAddNewClientScreen()
    {
        clsAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();   
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::FindClientScreen(); 
    }

    static void _ShowTransactionMenuScreen()
    {
        clsTransactionMenuScreen::ShowTransactionMenuScreen();
    
    }

    static void _ShowManageUsersScreen()
    {
        clsManageUserScreen::ShowManageUsersScreen();
    }

    static void _ShowRegisterLoginScreen()
    {
        // cout <<"\n register login screen will be here soon\n";
        clsRegisterLoginScreen::ShowRegisterLogin();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        // cout <<"\n\t\t Currency Exchange screen will be here soon\n";
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();

    }

    static void _Logiout()
    {
        CurrentUser = clsUsers::Find("", "");
    }


    static void _PerformMainMenuOptoin(enMainMenuOptions mainOption)
    {
        switch(mainOption)
        {
            case enMainMenuOptions::eListClients :
            {
                system("clear");
                _ShowAllClientsListScreen();
               _GoBackToMainMenu();
                break; 
            }
            case enMainMenuOptions::eAddNewClient : 
            {
                system("clear");
                _ShowAddNewClientScreen();
               _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eDeleteClient :
            {
                system("clear");
                _ShowDeleteClientScreen();
               _GoBackToMainMenu();
                break; 
            }
            case enMainMenuOptions::eUpdateClient : 
            {
                system("clear");
                _ShowUpdateClientScreen(); 
               _GoBackToMainMenu(); 
                break; 
            }
            case enMainMenuOptions::eFindClient :
            {
                system("clear");
                _ShowFindClientScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eShowTransactionMenu :
            {
                system("clear");
                _ShowTransactionMenuScreen();
               _GoBackToMainMenu();
                break; 
            }
            case enMainMenuOptions::eManageUsers :
            {
                system("clear");
                _ShowManageUsersScreen();
               _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eRegisterLogin :
            {
                system("clear");
               _ShowRegisterLoginScreen();
               _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eCurrencyExchange :
            {
                system("clear");
                _ShowCurrencyExchangeScreen();
               _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eExit :
            {
                system("clear");
                _Logiout();
                // Login
                break;
            }
        }
    }




public : 


     static void ShowMainMenu()
     {
        system("clear");
        
        //private function
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\tMain Menu\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Clients List\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n"; 
        cout << setw(37) << left << "" << "\t[4] Update Client.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] LogOut.\n"; 

        _PerformMainMenuOptoin((enMainMenuOptions)_ReadMainMenuOption());
     }

};