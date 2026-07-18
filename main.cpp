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
    while (true)
    {
        if(!clsLoginScreen::ShowLoginScreen())
            break; 
    }
    return 0;
}




