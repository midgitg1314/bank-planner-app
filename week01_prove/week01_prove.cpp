// week01_prove.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    int idNum = 0;
    //char name[20] = "";
    std::string accountHolderName;
    float balance;
    int choice = -1;

    std::cout << "Enter the name: ";
    std::getline(std::cin, accountHolderName);

    std::cout << "Enter the balance: ";
    std::cin >> balance;

    while (choice != 0)
    {
        std::cout << "\nAccount Menu:\n";
        std::cout << "0. Quit Program\n";
        std::cout << "1. Display Account Information\n";
        std::cout << "2. Add a deposit to an account\n";
        std::cout << "3. Withdraw from an account\n";
        std::cout << "Your choice: "; //<< choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Account ID: " << idNum << " " << "Name: " << accountHolderName << "  " << "Balance: $" << balance << std::endl;
        }
        else if (choice == 2) {
            float ammountToDeposit;
            std::cout << "Amount to deposit: ";
            std::cin >> ammountToDeposit;
            balance += ammountToDeposit;
        }
        else if (choice == 3) {
            float withdraw;
            std::cout << "Amount to withdraw: ";
            std::cin >> withdraw;
            balance -= withdraw;
        }
        else {
            std::cout << "Invalid choice. Your Choice: " << choice << std::endl;
        }
    }
    return 0;
}
