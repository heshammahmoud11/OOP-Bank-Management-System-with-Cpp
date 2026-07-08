#pragma once

#include<iostream>
#include"clsMainScreen.h"
#include"clsUsers.h"
#include"clsScreen.h"
#include"Global.h"



class clsLoginScreen : protected clsScreen
{
private : 


    static bool _Login()
    {
        bool LoginFaild = false;
        string username, password;
        short FaildCnt = 0;

        do
        {

            if(LoginFaild) // Means -> if(LoginFaild == true)
            {
                FaildCnt++;
                cout << "\n\t Invalid Username/Password!\n\n";
                cout <<"\t\nYou have " << (3 - FaildCnt) << " Trial to Login.\n";
            }

            if(FaildCnt == 3)
            {
                cout << "\n System Locked After 3 Faild Trials, Try Again Later!\n";
                return false;  
            }

            cout << "\n\t Enter Username? : ";
            cin >> username;
            cout << "\n\t Enter Password : ";
            cin >> password;

            CurrentUser  = clsUsers::Find(username, password);

            LoginFaild = CurrentUser.isEmpty();


        }while(LoginFaild);

        CurrentUser.RegisterLogin();
        
        clsMainScreen::ShowMainMenu();

        return true;

    }

public : 
    static bool ShowLoginScreen()
    {
        system("clear");

        _DrawScreenHeader("\t  Login Screen");

        return  _Login();

    }
};