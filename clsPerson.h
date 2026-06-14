#pragma once

#include<iostream> 
#include<string>
using namespace std;



class clsPerson
{
private : 
    string _firstName;
    string _lastName;
    string _email;
    string _phone;


public :
    clsPerson(string firstName, string lastName, string email, string phone)
    {
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    // setters and getters (set = put, get = get)
    
    void setFirstName(string fName)
    {
        _firstName = fName;

    }

    string getFirstName()
    {
        return _firstName;
    }

    void setLastName(string lName)
    {
        _lastName = lName;
    }

    string getLastName()
    {
        return _lastName;
    }

    void setEmail(string email)
    {
        _email = email;
    }

    string getEmail()
    {
        return _email;
    }

    void setPhone(string phone)
    {
        _phone = phone;
    }

    string getPhone()
    {
        return _phone;
    }


    string getFullName()
    {
        return _firstName + " " + _lastName;
    }

    void print()
    {
        cout << "INFO : \n";
        cout << "------------------------\n";
        cout << "First Name : " << _firstName << "\n";
        cout << "Last Name : " << _lastName << "\n";
        cout << "Full Name : " << getFullName() << "\n";
        cout << "Email : " << _email << "\n";
        cout << "Phoe : " << _phone << "\n";
    }
};