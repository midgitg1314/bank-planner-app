// w02task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "account.h"
#include <list>

int main()
{
    //Account my_account;


    //my_account.input_info();
    std::list<Account> accounts;

    int choice;
    int search_id;

    do {
        std::cout << "\nBank Menu : \n"
            << "0. Quit Program\n"
            << "1. Create a New Account\n"
            << "2. Display Account Information\n"
            << "3. Add a depsoit to an account\n"
            << "4. Withdraw form an account\n"
            <<"5. Seach for an account by ID\n"
            << "Your choice: ";
    
           
         std::cin >> choice;
         std::cin.ignore();

         switch (choice) {
         case 1: {
             Account new_account;
             new_account.input_info();
             accounts.push_back(new_account);
             std::cout << "New account created" << std::endl;
             break;
         }
         case 2: {

             std::cout << "All Accounts Information: \n";
             for (const auto& account : accounts) {
                 account.display_info();
                 std::cout << std::endl;
             }
             break;
         }
         case 3: {
             std::cout << "Enter the ID of the account to deposit to: ";
             std::cin >> search_id;

             auto result = Account::find_account(accounts, search_id);

             if (result != accounts.end()) {
                std::cout << "Account found: ";
                result->display_info();
                std::cout << std::endl;

                float deposit_amount;
                std::cout << "Amount to deposit: ";
                std::cin >> deposit_amount;

                result->deposit(deposit_amount);

                std::cout << "Deposit successful\n";
             }
             else {
                 std::cout << "Account not found.\n";
             }
             //accounts.back().deposit(deposit_amount);
             break;
         }
         case 4: {
             std::cout << "Enter the ID of the account to withdraw from: ";
             std::cin >> search_id;

             auto result = Account::find_account(accounts, search_id);

             if (result != accounts.end()) {
                 std::cout << "Account found: ";
                 result->display_info();
                 std::cout << std::endl;

                 float withdraw_amount;
                 std::cout << "Amount to withdraw: ";
                 std::cin >> withdraw_amount;

                 result->withdraw(withdraw_amount);

                 std::cout << "withdrawal successful\n";
             }
             else {
                 std::cout << "Account not found.\n";
             }
             //accounts.back().deposit(deposit_amount);
             break;
         }
         case 5: {
             std::cout << "Enter the ID of the account that you would like to search: ";
             std::cin >> search_id;

             auto result = Account::find_account(accounts, search_id);

             if (result != accounts.end()) {
                 std::cout << "Account found: \n";
                 result->display_info();
                 std::cout << std::endl;

             }
             else {
                 std::cout << "Account not found.\n";
             }
         }
               break;
         default:
             std::cout << "Invlaid choice. Please choose 0-4." << std::endl;
             break;
         }
    } while (choice != 0);

    for (const auto& acc : accounts) {
        std::cout << acc << std::endl;
    }


    //std::cout << my_account << std::endl;

    return 0;
}

