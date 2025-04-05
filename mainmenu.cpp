#include "mainmenu.h"
#include "UserIOHandler.h"
#include "investment.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

MainMenu::MainMenu()   {}

void MainMenu::run()   {
    int choice;
    UserIOHandler inputHandler;

    do   {
        displayMenu();
        choice = inputHandler.getNonZeroInt("Enter your choice: >");

        switch (choice)   {
            case 1:
                createInvestment();
                break;
            
            case 2:
                std::cout << "No Option 2 Implemented Yet.\n";
                break;

            case 0:
                std::cout << "Exiting the program...\n";
                break;

            default:
                std::cout << "Invalid Input please try again.\n";
        }
        std::cout << std::endl;
    }
    while (choice != 0);
}

void MainMenu::displayMenu() const   {
    std::cout << "\n---------- Main Menu -----------" << std::endl;
    std::cout << "1. Create a new Investment -----" << std::endl;
    std::cout << "2. View an Investment ---------" << std::endl;
    std::cout << "0. Exit the program ----------" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void MainMenu::createInvestment()   {
    UserIOHandler inputHandler;

    double principal;
    double annualInterestRate;
    int years;
    double monthlyDeposit;

    principal = inputHandler.getNonZeroDouble("Please enter the initial principal for the investment: >");
    annualInterestRate = inputHandler.getNonZeroDouble("Please enter the annual interest rate for the investment: >");
    years = inputHandler.getPosOneInt("Please enter the numer of years for the investment: >");
    monthlyDeposit = inputHandler.getNonZeroDouble("Please enter the amount you would like to deposit monthly to the principle over the investment term: >");

    Investment newInvestment(principal, annualInterestRate, years, monthlyDeposit);

    std::cout << "\n---------- New Investment Created: ----------\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Principal: $" << newInvestment.getPrincipal() << std::endl;
    std::cout << "Interest Rate: " << newInvestment.getAnnualInterestRate() << "%" << std::endl;
    std::cout << "Years: " << newInvestment.getYears() << std::endl;
    std::cout << "Monthly Deposit: $" << newInvestment.getMonthlyDeposit() << std::endl;
    std::cout << std::defaultfloat;

    investments.push_back(newInvestment);

    displayInvestmentDetails(newInvestment);
}

void MainMenu::displayInvestmentDetails(const Investment& investment)   const   {
    double principal = investment.getPrincipal();
    double annualInterestRate = investment.getAnnualInterestRate();
    int years = investment.getYears();
    double monthlyDeposit = investment.getMonthlyDeposit();
    double monthlyInterestRate = annualInterestRate / 12.0;

    std::cout << "\n--------- Investment Growth (Yearly) ----------\n";
    std::cout << std::setw(10) << "Year"
            << std::setw(15) << "Start Balance"
            << std::setw(15) << "Interest Gained"
            << std::setw(15) << "End Balance" << std::endl;
    std::cout << std::setfill('-') << std::setw(55) << "" << std::setfill(' ') << std::endl;

    double currentBalance = principal;
    for (int year = 0; year <= years; ++year)   {
        double interest = currentBalance * (annualInterestRate / 100);
        double endBalance = currentBalance + interest;
        std::cout << std::setw(10) << year
                << std::setw(15) << std::fixed << std::setprecision(2) << currentBalance
                << std::setw(15) << std::fixed << std::setprecision(2) << interest
                << std::setw(15) << std::fixed << std::setprecision(2) << endBalance << std::endl;
        currentBalance = endBalance;
    }
    std::cout << std::endl;

    if (monthlyDeposit > 0) {
        std::cout << "----- Investment Growth (Yearly with Monthly Deposits) -----\n";
        std::cout << std::setw(10) << "Year"
                  << std::setw(15) << "Start Balance"
                  << std::setw(15) << "Annual Deposit"
                  << std::setw(15) << "Interest Gained"
                  << std::setw(15) << "End Balance" << std::endl;
        std::cout << std::setfill('-') << std::setw(70) << "" << std::setfill(' ') << std::endl;

        double currentBalanceWithDeposit = principal;
        for (int year = 1; year <= years; ++year) {
            double yearlyDeposits = monthlyDeposit * 12;
            double interest = 0;
            double beginningBalance = currentBalanceWithDeposit;

            for (int month = 0; month < 12; ++month) {
                interest += currentBalanceWithDeposit * (monthlyInterestRate / 100);
                currentBalanceWithDeposit += monthlyDeposit;
            }

            double endBalance = beginningBalance + yearlyDeposits + interest;

            std::cout << std::setw(10) << year
                      << std::setw(15) << std::fixed << std::setprecision(2) << beginningBalance
                      << std::setw(15) << std::fixed << std::setprecision(2) << yearlyDeposits
                      << std::setw(15) << std::fixed << std::setprecision(2) << interest
                      << std::setw(15) << std::fixed << std::setprecision(2) << endBalance << std::endl;

            // For the next year, the starting balance is the end balance of the previous year
            currentBalanceWithDeposit = endBalance;
        }
        std::cout << std::endl;

        std::cout << "\n-------- Investment Growth Comparison -------\n";
        std::cout << std::setw(10) << "Year"
                  << std::setw(25) << "Without Monthly Deposit"
                  << std::setw(25) << "With Monthly Deposit" << std::endl;
        std::cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << std::endl;

        double balanceWithoutDeposit = principal;
        double balanceWithDeposit = principal;

        for (int year = 1; year <= years; ++year) {
            // Calculate without monthly deposit
            double interestWithout = balanceWithoutDeposit * (annualInterestRate / 100);
            balanceWithoutDeposit += interestWithout;

            // Calculate with monthly deposit
            double interestWith = 0;
            for (int month = 0; month < 12; ++month) {
                interestWith += balanceWithDeposit * (monthlyInterestRate / 100);
                balanceWithDeposit += monthlyDeposit;
            }
            balanceWithDeposit += interestWith;

            std::cout << std::setw(10) << year
                      << std::setw(25) << std::fixed << std::setprecision(2) << balanceWithoutDeposit
                      << std::setw(25) << std::fixed << std::setprecision(2) << balanceWithDeposit << std::endl;
        }
        std::cout << std::endl;
    }
}