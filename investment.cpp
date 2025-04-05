#include "investment.h"

Investment::Investment() : principal(0.0), annualInterestRate(0.0), years(0), monthlyDeposit(0.0)   {}

Investment::Investment(double principal, double annualInterestRate, int years, double monthlyDeposit)
    : principal(principal), annualInterestRate(annualInterestRate), years(years), monthlyDeposit(monthlyDeposit)   {}


// Implentation of the setters
void Investment::setPrincipal(double principal)   {
    this->principal = principal;
}

void Investment::setAnnualInterestRate(double annualInterestRate)   {
    this->annualInterestRate = annualInterestRate;
}

void Investment::setYears(int years)   {
    this->years = years;
}

void Investment::setMonthlyDeposit(double monthlyDeposit)   {
    this->monthlyDeposit = monthlyDeposit;
}

// Implement the getters
double Investment::getPrincipal() const   {
    return principal;
}

double Investment::getAnnualInterestRate() const   {
    return annualInterestRate;
}

int Investment::getYears() const   {
    return years;
}

double Investment::getMonthlyDeposit() const   {
    return monthlyDeposit;
}