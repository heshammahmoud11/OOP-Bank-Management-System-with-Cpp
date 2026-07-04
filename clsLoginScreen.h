#pragma once

#include<iostream>
#include"clsMainScreen.h"
#include"clsUsers.h"
#include"clsScreen.h"
#include"Global.h"


class clsLoginScreen : protected clsScreen
{
private : 
    static void _Login()
    {
        bool LoginFaild = false;
        string username, password;

        do
        {
            if(LoginFaild) // Means -> if(LoginFaild == true)
            {
                cout << "\n\t Invalid Username/Password!\n\n";
            }

            cout << "\n\t Enter Username? : ";
            cin >> username;
            cout << "\n\t Enter Password : ";
            cin >> password;

            CurrentUser  = clsUsers::Find(username, password);

            LoginFaild = CurrentUser.isEmpty();

        }while(LoginFaild);

        clsMainScreen::ShowMainMenu();

    }

public : 
    static void ShowLoginScreen()
    {
        system("clear");

        _DrawScreenHeader("\t  Login Screen");

        _Login();
    }
};