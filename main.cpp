#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsUtil.h"
using namespace std; 

void ReadClientInfo(clsBankClient &client)
{
    cout << "\nEnter First Name  : ";
    client.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter Last Name: ";
    client.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email : ";
    client.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone : ";
    client.SetPhone(clsInputValidate::ReadString());

    cout << "\nEnter Pin Code: ";
    client.SetPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance : ";
    client.SetAccountBalance(clsInputValidate::ReadfloatNumber());
}

void PrintClientRecordLine(clsBankClient client)
{
    cout << "| " << left << setw(15) << client.AccountNumber() ;
    cout << "| " << left << setw(20) << client.FullName() ;
    cout << "| " << left << setw(15) << client.GetPhone() ;
    cout << "| " << left << setw(25) << client.GetEmail() ;
    cout << "| " << left << setw(15) << client.GetPinCode() ;
    cout << "| " << left << setw(15) << client.GetAccountBalance();
}

void PrintClientRecordBalanceLine(clsBankClient client)
{
    cout << "| " << left << setw(20) << client.AccountNumber();
    cout << "| " << left << setw(20) << client.FullName();
    cout << "| " << left << setw(20) << client.GetAccountBalance();
}

void UpdateClient()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();


    // before find client -> check first if it exist in the file or not !
    while(!clsBankClient::IsClientExist(AccountNumber))
    {
        // only if client not exist, apply this code
        cout << "\nAccount Number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    // client exist in the file
    clsBankClient client1 = clsBankClient::Find(AccountNumber); 
    client1.Print();

    cout << "\nUpdate Client Info:";
    cout << "\n---------------------------\n";

    ReadClientInfo(client1);

    clsBankClient::enSaveResults SaveResult = client1.Save();

    switch (SaveResult)
    {
        case clsBankClient::enSaveResults::svSucceeded : 
        {
            cout << "\nAccount Updated Successfully :-)\n";
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject : 
        {
            cout << "\nError Account was not saved because it's Empty\n";
            break;
        }
    }


}

void AddNewClient()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number: ";

    AccountNumber = clsInputValidate::ReadString();

    while(clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nThe Client Number is Already Exist, Please Enter another account number : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult = NewClient.Save();


    switch (SaveResult)
    {
        case clsBankClient::enSaveResults::svSucceeded :
        {
            cout << "\nClient Addedd Successfully -:)\n";
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject :
        {
            cout << "\nError, Account Was not Saved because it's Empty\n";
            break; 
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists :
        {
            cout << "\nError, Account Number is Already Exist.";
            break;
        }
    }


}

void DeleteClient()
{
    string AccountNumber = "";
    cout << "\nEnter Account Number to Delete: ";
    AccountNumber = clsInputValidate::ReadString();

    while(!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Not Found, Enter another One: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient client = clsBankClient::Find(AccountNumber);
    client.Print();

    cout << "\nAre You Sure Do You want to Delete This Client?[Y/N]: ";

    char ans = 'n';
    cin >> ans;

    if(tolower(ans) == 'y')
    {
        if(client.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";
            client.Print();
        }else
        {
            cout << "\nError, Client Was not Deleted\n";
        }
    }

}
  
void ShowClientsList()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClients List ( " << vClients.size() << " ) Client\n" ; 
    cout << "\n--------------------------------------------------------------------";
    cout << "-----------------------------------------------------------------\n" << endl;
     
    // Create List Header

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(15) << "Phone";
    cout << "| " << left << setw(25) << "Email";
    cout << "| " << left << setw(15) << "Pin Code";
    cout << "| " << left << setw(15) << "Balance";

    cout << "\n--------------------------------------------------------------------";
    cout << "-----------------------------------------------------------------\n" << endl;
     

    if(vClients.size() == 0)
    {
        cout << "\n\t\tthere is no clients available in the system!\n";
    }
    else
    {
        for(clsBankClient & c : vClients)
        {
            PrintClientRecordLine(c);
            cout << endl;
        }

    cout << "\n--------------------------------------------------------------------";
    cout << "-----------------------------------------------------------------\n" << endl;
     
    }

}


void ShowTotalBalances()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\tBalances List ( " << vClients.size() << " ) client\n";

    cout << "\n--------------------------------------------------------------------------";
    cout << "-------------------------------------------------------------------\n";

    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(20) << "Balance";

    cout << "\n--------------------------------------------------------------------------";
    cout << "-------------------------------------------------------------------\n";

    double TotalBalance = clsBankClient::GetTotalBalances();

    if(vClients.size() == 0)
    {
        cout << "\t\t\tThere is no Clients avaiable in the system\n";
    }else
    {
        for(clsBankClient & c : vClients)
        {
            PrintClientRecordBalanceLine(c); 
            cout << endl;
        }
    }
    cout << "\n--------------------------------------------------------------------------";
    cout << "-------------------------------------------------------------------\n";

    cout << "\t\t\t Total Balances = " << TotalBalance << endl;
    cout << "\t\t\t ( " << clsUtil::NumberToText(TotalBalance) << endl;

}



int main()
{
ShowTotalBalances();
    return 0;
}




