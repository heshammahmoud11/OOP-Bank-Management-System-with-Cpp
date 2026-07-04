#pragma once 

#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

using namespace std; 



class clsUsers : public clsPerson
{
private :  
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};

    enMode _Mode;
    string _UserName; 
    string _Password;
    int _Permission;
    bool _Marked4Delete = false;



    static string _convertUserObjectToLine(clsUsers user, string seperator = "#//#")
    {
        string sword = "";

        sword += user.GetFirstName() + seperator;
        sword += user.GetLastName()  + seperator;
        sword += user.GetEmail()  + seperator;
        sword += user.GetPhone()  + seperator;
        sword += user.GetUserName()  + seperator;
        sword += user.GetPassword()  + seperator;
        sword += to_string(user.GetPermission()) ;

        return sword;
    }



    static clsUsers _ConvertLineToUserObject(string line, string seperator = "#//#")
    {

        vector<string> vUserData = clsString::Split(line, seperator);

        return clsUsers(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6])); 

    }

    static void _SaveUserDataToFile(vector<clsUsers> vUsers) 
    {
        fstream myFile;
        myFile.open("Users.txt", ios::out); // write all new data from zero


        if(myFile.is_open())
        {
            string line;
            for (clsUsers & c : vUsers ) 
            {
                // write only records that are not marked for delete
                if(c.MarkForDelete() == false)
                {
                    line = _convertUserObjectToLine(c);
                    myFile << line << endl;
                }

            }
            myFile.close();
        }
    }

    static vector<clsUsers> _LoadUsersDataFromFile()
    {
        vector<clsUsers> vUserData;

        fstream myFile;
        myFile.open("Users.txt", ios::in); // read & get the Data From file 

        if(myFile.is_open())
        {
            string line;

            while(getline(myFile, line))
            {
                clsUsers user = _ConvertLineToUserObject(line);
                vUserData.push_back(user);
            }
            myFile.close();
        }

        return vUserData;

    }

    void _AddUserLineToFile(string line)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::out | ios::app); // write without delte previous data

        if(myFile.is_open())
        {
            myFile << line << endl;
        }

        myFile.close();
    }

    static clsUsers _GetEmptyUserObject()
    {
        return clsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _Update()
    {
        vector<clsUsers> vUsers = _LoadUsersDataFromFile();

        for(clsUsers & c : vUsers)
        {
            if(c.GetUserName() == GetUserName())
            {
                c = *this;
                break;
            }
        }

        _SaveUserDataToFile(vUsers);
    }

    void _AddNew()
    {
        _AddUserLineToFile(_convertUserObjectToLine(*this));
    }


public :
    enum enPermission { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
                        pUPdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64};


    clsUsers(enMode Mode, string FirstName, string LastName, string Email, 
             string Phone, string UserName, string Password, int Permission) : clsPerson(FirstName, LastName, Email, Phone)
             {
                _Mode = Mode;
                _UserName = UserName;
                _Password = Password;
                _Permission = Permission;
             }
    
    bool isEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    // setters and getters

    bool MarkForDelete()
    {
        return _Marked4Delete;
    }
    
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }
    
    string GetPassword()
    {
        return _Password;
    }

    void SetPermission(int Permisssion)
    {
        _Permission = Permisssion;
    }

    int GetPermission()
    {
        return _Permission; 
    }

    // find the user by username

    static clsUsers Find(string UserName)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in); // read the file data

        if(myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsUsers User = _ConvertLineToUserObject(line);
                if(User.GetUserName() == UserName)
                {
                    myFile.close();
                    return User;
                }
            }
            myFile.close();
        }

        return _GetEmptyUserObject();
    }


    // find user by Username and password

    static clsUsers Find(string username, string password)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in); 

        if(myFile.is_open())
        {
            string line;

            while (getline(myFile, line)) 
            {
                clsUsers user = _ConvertLineToUserObject(line);
                if(user.GetUserName() == username && user.GetPassword() == password)
                {
                    myFile.close();
                    return user;
                }
            }

            myFile.close();
            
        }

        return _GetEmptyUserObject();
    }

    // Save function

    enum enSaveResults {svFaildEmptyObject = 0, svSucceded = 1, svFaildUserExist = 2};

    enSaveResults Save()
    {
        switch(_Mode)
        {
            case enMode::EmptyMode :
            {
                if(isEmpty())
                    return enSaveResults::svFaildEmptyObject;
            }
            case enMode::UpdateMode :
            {
                _Update();
                return enSaveResults::svSucceded;
                break;
            }
            case enMode::AddNewMode :
            {
                // this will add new record to file or database
                if(clsUsers::IsUserExist(_UserName))
                {
                    return enSaveResults::svFaildUserExist; 
                }else
                {
                    _AddNew();
                    // we need to change mode after addNew to Update
                    _Mode = enMode::UpdateMode;

                    return enSaveResults::svSucceded;
                }

                break;
            }

        }

        // if user not empty -> save
        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsUserExist(string UserName)
    {
        clsUsers user = clsUsers::Find(UserName);

        return (!user.isEmpty());
    }

    bool Delete()
    {
        vector<clsUsers> vUsers = _LoadUsersDataFromFile();

        for(clsUsers & c : vUsers)
        {
            if(c.GetUserName() == _UserName)
            {
                c._Marked4Delete = true;
                break;
            }
        }

        _SaveUserDataToFile(vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    static clsUsers GetAddNewUserObject(string username)
    {
        return clsUsers(enMode::AddNewMode, "", "", "", "", username, "", 0);
    }
    
    static vector<clsUsers> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }



    bool CheckAccessPermission(enPermission permission)
    {
        if(permission == enPermission::eAll)
        {
            return true;
        }
        if((permission & _Permission) == permission)
        {
            return true;
        }else
        {
            return false;
        }
    }
}; 

