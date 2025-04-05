#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "investment.h"
#include "UserIOHandler.h"

#include <vector>

class MainMenu   {
    private:
        std::vector<Investment> investments;

    public:
        MainMenu();
        void run();
        void displayMenu() const;
        void createInvestment ();
        void displayInvestmentDetails(const Investment& investment) const;
};

#endif // MAIN_MENU_H