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

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;


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

    static vector<clsBankClient> _LoadClientDataFromFile()
    {
        vector<clsBankClient> vClients;

        fstream myFile;
        myFile.open("Client.txt", ios::in); // Read File Data

        if(myFile.is_open())
        {
            string line;

            while(getline(myFile, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                vClients.push_back(client);
            }

            myFile.close();
         }

         return vClients;
    }

    static void _SaveClientDataToFile(vector<clsBankClient> vClients)
    {
        fstream myFile;
        myFile.open("Client.txt", ios::out); // Write the updated data with overwrite Mode (Write everything from scratch)

        if(myFile.is_open())
        {
            string line;

            for(clsBankClient & c : vClients)
            {
                if(c._MarkedForDelete == false)
                {
                    line = _ConvertClientObjectToLine(c);
                    myFile << line << endl;
                }
            }

            myFile.close();
        }
    }


    void _AddDataLineToFile(string line)
    {
        fstream myFile;

        myFile.open("Client.txt", ios::out | ios::app) ; // write in the file, without delete previous data
        
        if(myFile.is_open())
        {
          myFile << line << endl;   
        }
        myFile.close();
    }
 
    void _Update()
    {
        vector<clsBankClient> _vClients = _LoadClientDataFromFile();

        for(clsBankClient & c : _vClients)
        {
            if(c.AccountNumber() == AccountNumber())
            {
                // updated informatin exist in -> *this (Memory)
                // file data (not updated) -> c (File)
                c = *this;
                break;
            }
        }

        _SaveClientDataToFile(_vClients);

    }



    void _AddNew()
    {

        _AddDataLineToFile(_ConvertClientObjectToLine(*this));

    }
public:
 
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

 // Get Account Number Directly
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

    //  void Print()
    // {
    //     cout << "\nClient Card:";
    //     cout << "\n___________________";
    //     cout << "\nFirstName   : " << GetFirstName();
    //     cout << "\nLastName    : " << GetLastName();
    //     cout << "\nFull Name   : " << FullName();
    //     cout << "\nEmail       : " << GetEmail();
    //     cout << "\nPhone       : " << GetPhone();
    //     cout << "\nAcc. Number : " << _AccountNumber;
    //     cout << "\nPassword    : " << _PinCode;
    //     cout << "\nBalance     : " << _AccountBalance;
    //     cout << "\n___________________\n";

    // }


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

        // if there is no Full client -> Return Empty Client Object
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


    enum enSaveResults {svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};


    enSaveResults Save()
    {
        // if clsBankClient == empty -> Not save

        switch (_Mode)
        {
            case  enMode::EmptyMode :
            {
                return enSaveResults::svFaildEmptyObject;
            }

            case enMode::UpdateMode : 
            {
                _Update();
                return enSaveResults::svSucceeded;
                // break;
            }
            case enMode::AddNewMode :
            {
                if(clsBankClient::IsClientExist(_AccountNumber))
                {
                    return enSaveResults::svFaildAccountNumberExists;
                }
                else
                {
                    _AddNew();

                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }
            }
                
        }
    
      // if clsBankClient = NotEmpty -> Save
      return enSaveResults::svFaildEmptyObject;

    }

    static clsBankClient GetAddNewClientObject(string accountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients = _LoadClientDataFromFile();

        for(clsBankClient & c : _vClients)
        {
            if(c.AccountNumber() == _AccountNumber)
            {
                c._MarkedForDelete = true;
                break;
            }
        }

         _SaveClientDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }



    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientDataFromFile();
    }


    static float GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        double balanceCnt = 0;

        for(clsBankClient & c : vClients)
        {
            balanceCnt += c.GetAccountBalance();
        }

        return balanceCnt;
    }
    
    // this function must be non-static (no one from outside can access without Object)
    void Deposit(double amount)
    {
        _AccountBalance += amount;
        Save(); 
    } 

    bool Withdraw(double amount)
    {
        if(amount > _AccountBalance)
            return false;
        else 
        {
           _AccountBalance -= amount;
            Save();
        }
        
        return true; 
    }


    bool Transfer(float amount, clsBankClient & DestinationClient)
    {
        // currently we stand on the sourceClient
        // comabe the amount with sourceclient
        if(amount > GetAccountBalance())
        {
            return false;
        }

        // make withdraw operation from source & put it in the destination
        Withdraw(amount);
        DestinationClient.Deposit(amount);

        return true;
    }



}; 



