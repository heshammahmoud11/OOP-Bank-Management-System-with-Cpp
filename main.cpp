#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsClientListScreen.h"
#include"clsLoginScreen.h"



using namespace std; 



int main()
{
    // clsMainScreen::ShowMainMenu();


    // Skip the "Circular referance" error.
    while (true)
       clsLoginScreen::ShowLoginScreen();

    return 0;
}




