# OOP-Bank-Management-System-with-Cpp

# Bank Management System

A console-based banking application built in C++ using Object-Oriented Programming. The system manages clients, users, permissions, and financial transactions with data persisted to file storage.

## Features

- **Client Management** — add, view, update, delete, and search clients (full CRUD)
- **User Management** — manage system users with role-based access control
- **Permissions System** — bitmask-based access control (each user can be granted specific permissions: view clients, add, delete, manage transactions, manage users, etc.)
- **Transactions** — deposit, withdraw, and transfer funds between accounts, with balance validation
- **Reports** — total balance across all clients, and a full transfer log history
- **Authentication** — secure login with attempt validation and login activity logging

## Class Structure

clsPerson (base class)
│
├── clsBankClient
│      ├── Deposit()
│      ├── Withdraw()
│      ├── Transfer()
│      ├── Save() / Delete() / Find()
│      └── stTransferLogRecord (nested struct)
│
└── clsUsers
├── Save() / Delete() / Find()
├── CheckAccessPermission()
└── stUserRecord (nested struct)
clsScreen (base class for all UI screens)
│
├── clsLoginScreen
├── clsMainMenuScreen
├── clsManageUserScreen
├── clsTransactionMenuScreen
│      ├── clsDepositScreen
│      ├── clsWithdrawScreen
│      ├── clsTransferScreen
│      ├── clsTotalBalanceScreen
│      └── clsTransferLogScreen
└── clsRegisterLoginScreen
Shared Utility Classes (no inheritance, used everywhere)
│
├── clsString          → Split(), text processing
├── clsDate            → date/time formatting
└── clsInputValidate   → input validation and reading

## Project Structure

- `clsPerson` — base class shared by clients and users
- `clsBankClient` — handles client data, balances, and transactions
- `clsUsers` — handles system users and permissions
- `clsScreen` (and subclasses) — handles all UI screens (login, menus, transactions, etc.)
- `clsString`, `clsDate`, `clsInputValidate` — shared utility classes
- Data is stored in flat text files (`Client.txt`, `Users.txt`, `TransferLog.txt`, `LoginRegister.txt`)

## Tech Stack

- **Language:** C++ (C++17)
- **Compiler:** g++
- **Storage:** File-based persistence (no external database)

## OOP Concepts Applied

- Inheritance (`clsBankClient` and `clsUsers` inherit from `clsPerson`)
- Encapsulation (all data is private, accessed through getters/setters)
- Factory pattern (private constructors with static `Find()` / `GetEmptyObject()` methods)
- Enums for state management instead of magic numbers
- Bitmasking for a flexible permission system

## How to Run

```bash
g++ -std=c++17 -Wall -o BankSystem main.cpp
./BankSystem
```