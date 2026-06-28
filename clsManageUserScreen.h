#pragma once

#include<iostream>
#include<iomanip>
#include<limits>
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsManageUserScreen : protected clsScreen
{
private : 
    enum enManageUsersMenu
    {
        eListUsers = 1, eAddNewUser = 2,
        eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5, eMainMenu = 6
    }; 

    static void _GoBack2ManageScreenMenu()
    {
        cout << setw(37) << left << "" << "\t Press any key to go back to Manage Users Menu...\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        ShowManageUsersScreen();
    }

    static short ReadManageUsersMenuOption()
    {
        short num;
        cout << setw(37) << left << "" << "\tEnter number between [1 - 6] : ";
        num = clsInputValidate::ReadDblNumberBetween(1, 6);
        return num;
    }

    static void _ShowListUsersScreen()
    {
        cout << setw(37) << left << "" << "\t List Users will be here soon\n";
    }

    static void _ShowAddNewUserScreen()
    {
        cout << setw(37) << left << "" << "\t Add New Users will be here soon\n";
    }

    static void _ShowDeleteUserScreen()
    {
        cout << setw(37) << left << "" << "\t Delete Users will be here soon\n";
    }
    
    static void _ShowUpdateUserScreen()
    {
        cout << setw(37) << left << "" << "\t Update Users will be here soon\n";
    }

    static void _ShowFindUserScreen()
    {
        cout << setw(37) << left << "" << "\t Find Users will be here soon\n";
    }

    static void _ShowMainMenuScreen()
    {
        cout << setw(37) << left << "" << "\t Go To Main Menu will be here soon\n";
    }

    static void _PerformManageUsersMenu(enManageUsersMenu option) 
    {
        switch(option)
        {
            case enManageUsersMenu::eListUsers : 
            {
                system("clear");
                _ShowListUsersScreen();
                _GoBack2ManageScreenMenu();
                break;
                
            }
            case enManageUsersMenu::eAddNewUser : 
            {
                system("clear");
                _ShowAddNewUserScreen();
                _GoBack2ManageScreenMenu();
                break;
                
            }
            case enManageUsersMenu::eDeleteUser : 
            {
                system("clear");
                _ShowDeleteUserScreen();
                _GoBack2ManageScreenMenu();
                break;
                
            }
            case enManageUsersMenu::eUpdateUser : 
            {
                system("clear");
                _ShowUpdateUserScreen();
                _GoBack2ManageScreenMenu();
                break;
                
            }
            case enManageUsersMenu::eFindUser : 
            {
                system("clear");
                _ShowFindUserScreen();
                _GoBack2ManageScreenMenu();
                break;
                
            }
            case enManageUsersMenu::eMainMenu : 
            {
                
            }
            
        }
    }

    

public : 
    static void ShowManageUsersScreen()
    {
        system("clear");

        clsScreen::_DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "=============================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "=============================================\n";
        
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n"; 
        cout << setw(37) << left << "" << "\t[5] Find User.\n"; 
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n"; 

        cout << setw(37) << left << "" << "=============================================\n";

        _PerformManageUsersMenu((enManageUsersMenu) ReadManageUsersMenuOption()); 

    }
}; 


