## 1. Introduction

### 1.1.1 Purpose
This document specifies the requirements for a command-line application developed in pure C++ that calculates compound interest with the option of including monthly deposits. It will display a year-by-year breakdown of the balance, including the interest earned each year.

### 1.1.2 Scope
This application will calculate and display the year-end balance for a given principal amount, annual compound interest rate, and investment period in years. It will also provide an optional feature to include a fixed monthly deposit and show the year-end balance with these additional contributions. The application will present two sets of calculations if a monthly deposit is provided: one without monthly deposits (straight compound interest) and one with monthly deposits. The application will operate within a terminal environment and show the year start, interest earned, and year end balance for each year.

### 1.1.3 Target Audience
Individuals who want to understand the growth of their investments over time, considering both compound interest and potential regular monthly contributions, all within a command-line interface.

### 1.1.4 Intended Use
Users will input their initial investment (principal), the annual compound interest rate, the investment period in years, and optionally a monthly deposit amount. The application will then display a year-by-year breakdown of the investment growth, showing the starting balance, interest earned, and ending balance for each year, both with and without the monthly deposit (if provided).

## 2. Functional Requirements

### 2.1 Input Handling

#### 2.1.1.1 Principal Amount Input
The application shall prompt the user to enter the initial principal investment amount.

#### 2.1.1.2 Annual Interest Rate Input
The application shall prompt the user to enter the annual compound interest rate as a percentage (e.g., 5 for 5%).

#### 2.1.1.3 Investment Period Input
The application shall prompt the user to enter the investment period in whole years.

#### 2.1.1.4 Optional Monthly Deposit Input
The application shall prompt the user if they want to enter a monthly deposit amount. If yes, it shall prompt for the monthly deposit amount. If no, this feature will be skipped.

### 2.2 Input Validation

#### 2.2.1.1 Data Type Validation
The application shall ensure that all numerical inputs (principal, interest rate, investment period, monthly deposit) are valid numerical values. Appropriate error messages shall be displayed for non-numeric input, and the user shall be prompted to re-enter the value.

#### 2.2.1.2 Range Validation
* Principal amount should be non-negative.
* Annual interest rate should be non-negative.
* Investment period should be a positive integer (at least 1).
* Monthly deposit (if entered) should be non-negative.

### 2.3 Calculation Logic

#### 2.3.1.1 Straight Compound Interest Calculation (Without Monthly Deposits)
For each year from 1 to the investment period:
* Calculate the interest earned for the year based on the year's starting balance and the annual interest rate.
* Calculate the year-end balance by adding the earned interest to the year's starting balance.

#### 2.3.1.2 Compound Interest Calculation with Monthly Deposits (If Provided)
For each year from 1 to the investment period:
* Initialize the year's starting balance.
* For each month of the year (1 to 12):
    * Add the monthly deposit to the current balance.
    * Calculate the monthly interest (annual rate divided by 12) and add it to the balance.
* The balance at the end of the 12th month is the year-end balance with monthly deposits.
* Calculate the total interest earned during the year.

### 2.4 Output Display

#### 2.4.1.1 Input Echo
The application shall display the entered input values (principal, interest rate, investment period, and monthly deposit if provided).

#### 2.4.1.2 Calculation Without Monthly Deposits
Display a header indicating "Compound Interest Calculation (No Monthly Deposits)".
For each year of the investment period, display:
* Year number.
* Year start balance.
* Interest earned during the year.
* Year end balance.

#### 2.4.1.3 Calculation With Monthly Deposits (If Provided)
Display a header indicating "Compound Interest Calculation (With Monthly Deposits of $[Monthly Deposit Amount])".
For each year of the investment period, display:
* Year number.
* Year start balance.
* Interest earned during the year.
* Year end balance.

#### 2.4.1.4 Formatting
All numerical output (balances, interest, deposit) should be formatted clearly, potentially including currency symbols and appropriate decimal places (e.g., two for currency).

## 3. Non-Functional Requirements

### 3.1 Usability

#### 3.1.1.1 Clear Prompts
The application shall provide clear and concise prompts for all input values.

#### 3.1.1.2 Organized Output
The year-by-year calculation results for both scenarios (with and without monthly deposits) shall be presented in a well-organized and easy-to-follow format.

### 3.2 Performance

#### 3.2.1.1 Calculation Speed
The calculations for both scenarios should be performed efficiently and results displayed quickly.

### 3.3 Reliability

#### 3.3.1.1 Accurate Calculations
The application shall implement the compound interest logic correctly for both scenarios.

#### 3.3.1.2 Robustness
The application should handle invalid input gracefully.

### 3.4 Maintainability

#### 3.4.1.1 Code Clarity
The C++ code should be well-structured and commented.

### 3.5 Portability

#### 3.5.1.1 Standard C++
The application should use standard C++ features.
