# Airgead Compound Interest Calculator (C++)

[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen)](https://github.com/mcdonald944/airgeadcompoundinterestcalculator/actions)
[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)

## Project Summary and Problem Solved

This project addresses the need for a simple, terminal-based tool to understand how investments grow over time through compound interest. It allows users to input their initial investment, annual interest rate, and investment period. Crucially, it also provides an optional feature to include fixed monthly deposits, offering a more realistic projection of investment growth. The application presents two sets of calculations (with and without monthly deposits, if provided) in a clear, year-by-year format, empowering individuals to visualize the potential impact of regular contributions on their long-term savings.

## What I Did Particularly Well

* **Clear Input Validation:** I implemented robust input validation to ensure users provide valid numerical data for all required fields (principal, interest rate, investment period, and monthly deposit). This included checks for data types and reasonable ranges, providing informative error messages and prompting for re-entry.
* **Organized Output:** The year-by-year breakdown for both calculation scenarios (with and without monthly deposits) is presented in a well-structured and easy-to-follow table format within the terminal. This makes it simple for users to track their investment growth.
* **Accurate Calculation Logic:** The core compound interest calculations, especially the handling of monthly deposits and the separate tracking of interest earned, were implemented carefully to ensure accuracy. The logic correctly applies monthly interest to the increasing balance after each deposit.

## Areas for Code Enhancement

* **More Sophisticated Input Handling:** While basic validation is in place, I could enhance input handling by:
    * Using a dedicated library for command-line argument parsing (e.g., `getopt` or a third-party library). This would allow for more flexible input methods and options.
    * Implementing more specific error handling for edge cases.
* **Abstraction and Modularity:** The calculation logic could be further abstracted into separate functions or classes. This would improve code organization, readability, and testability. For example, a dedicated `InvestmentCalculator` class could encapsulate the different calculation methods.
    * **Efficiency:** While the current calculations are efficient for typical investment periods, for extremely long durations, optimizing the loop structures or exploring mathematical formulas for direct calculation could be considered (though the current approach prioritizes clarity).
* **Internationalization/Localization:** For broader usability, the application could be adapted to handle different currency formats and number conventions.
* **Testing Framework:** Implementing a proper unit testing framework (e.g., Google Test) would significantly improve code reliability by allowing for automated testing of individual components and calculation logic.
    * **Security:** In this specific application, security vulnerabilities are minimal as it's a local command-line tool with no external data interaction. However, the principles of secure coding (like careful input validation to prevent unexpected behavior) were applied. If the application were to handle external data or user accounts in the future, security would become a much higher priority.

## Most Challenging Code and How It Was Overcome

The most challenging part was accurately implementing the **compound interest calculation with monthly deposits**. This required careful consideration of:

* **Timing of Deposits and Interest:** Ensuring that the monthly deposit was added *before* the monthly interest was calculated for that period.
* **Tracking Yearly Interest:** Correctly accumulating the total interest earned within each year, even with the compounding happening monthly.

I overcame this by:

* **Breaking down the problem:** Instead of trying to calculate the entire investment period at once, I focused on calculating the balance and interest for each month within a year, and then iterating through the years.
* **Manual Tracing:** I manually worked through several example scenarios with different principal amounts, interest rates, and monthly deposits to verify the calculation logic at each step.
* **Referencing Financial Formulas:** I double-checked the formulas for compound interest and how monthly contributions are typically factored in.

**Tools and Resources Added to My Support Network:**

* **C++ Documentation (cppreference.com):** A constant and invaluable resource for understanding language features and standard library components.
* **Online Forums (Stack Overflow, Reddit):** Useful for researching specific issues and seeing how others have approached similar problems.
* **Potential Addition: Google Test Documentation:** As I plan to implement unit testing, I'll be adding the Google Test documentation to my resources.

## Transferable Skills

This project has developed several skills that will be highly transferable to other projects and coursework:

* **Problem Decomposition:** Breaking down a larger problem (calculating investment growth) into smaller, manageable steps (input, validation, yearly calculation, monthly calculation).
* **Algorithmic Thinking:** Designing the step-by-step logic for the compound interest calculations.
* **Input Validation and Error Handling:** Writing code that anticipates and gracefully handles invalid user input.
* **Iterative Development:** Building the application step-by-step, testing along the way.
* **Clear Output Formatting:** Presenting information in a user-friendly and understandable manner.
* **Understanding of Financial Concepts:** Gaining a practical understanding of compound interest and its implications.
* **Basic C++ Programming Skills:** Solidifying my understanding of fundamental C++ concepts like variables, data types, loops, conditional statements, and basic input/output.

## Maintainability, Readability, and Adaptability

I aimed to make this program maintainable, readable, and adaptable through the following practices:

* **Meaningful Variable Names:** Using descriptive names for variables (e.g., `principalAmount`, `annualInterestRate`, `monthlyDeposit`).
* **Clear Comments:** Adding comments to explain the purpose of different code sections and complex logic.
* **Logical Code Structure:** Organizing the code into logical blocks (input, validation, calculations, output).
* **Function Usage:** While there's room for more abstraction, I used functions to separate key tasks like input prompting and the main calculation loops.
* **Adherence to Basic C++ Conventions:** Following standard C++ syntax and formatting conventions to improve readability.
* **Modular Design (Future Improvement):** While not fully implemented, the structure allows for easier modularization in the future. For example, the calculation logic could be moved into separate functions or classes without significantly altering the input/output sections.

---

Feel free to use and adapt this README for your GitHub repository! Remember to replace `your-github-username` and `your-repo-name` in the build status badge link with your actual information. You can also add more badges (e.g., for code style) as you develop further. Good luck! 
