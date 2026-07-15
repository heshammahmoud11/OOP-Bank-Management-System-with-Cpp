#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsClientListScreen.h"
#include"clsLoginScreen.h"
#include <unistd.h>


using namespace std; 


int main()
{
    // clsMainScreen::ShowMainMenu();


    // Skip the "Circular referance" error.
    // sleep(7);

    while (true)
    {
        if(!clsLoginScreen::ShowLoginScreen())
        {
            break; 
        }
    }

    return 0;
}




