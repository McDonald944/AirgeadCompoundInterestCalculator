#include "UserIOHandler.h"
#include <iostream>

int UserIOHandler::getNonZeroInt(const std::string &prompt)   {
    int value;
    bool validInput = false;

    while (!validInput)   {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good() && value >= 0)   {
            validInput = true;
        }
        else   {
            std::cout << "Invalid input. Please enter a number greater than 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}

int UserIOHandler::getPosOneInt(const std::string &prompt)   {
    int value;
    bool validInput = false;

    while (!validInput)   {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good() && value >= 1)   {
            validInput = true;
        }
        else   {
            std::cout << "Invalid input. Please enter a number greater than 1.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}

double UserIOHandler::getNonZeroDouble(const std::string &prompt)   {
    double value;
    bool validInput = false;

    while (!validInput)   {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good() && value >= 0)   {
            validInput = true;
        }
        else   {
            std::cout << "Invalid input. Please enter a number greater than 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}
