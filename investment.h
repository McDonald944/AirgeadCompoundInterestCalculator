#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment   {
    private:
        double principal;
        double annualInterestRate;
        int years;
        double monthlyDeposit;

    public:
        Investment();

        Investment(double principal, double annualInterestRate, int years, double monthlyDeposit);

        // Setters
        void setPrincipal(double principal);
        void setAnnualInterestRate(double annualInterestRate);
        void setYears(int years);
        void setMonthlyDeposit(double monthlyDeposit);

        // Getters
        double getPrincipal() const;
        double getAnnualInterestRate() const;
        int getYears() const;
        double getMonthlyDeposit() const;
};

#endif // INVESTMENT_H