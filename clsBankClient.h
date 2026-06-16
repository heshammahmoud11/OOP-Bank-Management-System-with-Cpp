#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;

    static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#")
    {
        vector<string> vClientData = clsString::Split(line, seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
             vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6])); 
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string line = "";
        line += Client.GetFirstName() + Seperator;
        line += Client.GetLastName() + Seperator;
        line += Client.GetEmail() + Seperator;
        line += Client.GetPhone() + Seperator;
        line += Client.AccountNumber() + Seperator;
        line += Client.GetPinCode() + Seperator;
        line += to_string(Client.GetAccountBalance());

        return line;

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }



public:
 
    clsBankClient();

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    // __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    // __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

     void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }





    static clsBankClient Find(string AccountNumber)
    {
        vector<clsBankClient> vClients;
        fstream myFile;

        myFile.open("Client.txt", ios::in); // Read Only from txt file
        
        if(myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsBankClient Client = _ConvertLineToClientObject(line);
                if(Client.AccountNumber() == AccountNumber)
                {
                    myFile.close();
                    return Client;
                }
                
                vClients.push_back(Client);
            }

            myFile.close();
        }

        // Return ? -> Return Empty Client Object
        return _GetEmptyClientObject();


    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector<clsBankClient> vClients;

        fstream myFile;
        myFile.open("Client.txt", ios::in);

        if(myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsBankClient Client = _ConvertLineToClientObject(line);
                if(Client.AccountNumber() == AccountNumber && Client.GetPinCode()== PinCode)
                {
                    myFile.close();
                    return Client;
                }
                vClients.push_back(Client); 
            }

            myFile.close();
        }

        return _GetEmptyClientObject(); 

    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }
}; 