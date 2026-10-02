
#include <iostream>

using namespace std;

int main() {
   
    int mainChoice = 0;

    cout << "==========================================================" << endl;
    cout << "      SMART FINANCIAL EVALUATION & SIMULATOR SYSTEM       " << endl;
    cout << "==========================================================" << endl;
    cout << "Select a module to proceed:" << endl;
    cout << "1. Loan & Credit Card Eligibility Checker" << endl;
    cout << "2. Income Tax & Net Salary Calculator" << endl;
    cout << "3. Investment & Term Deposit Yield Evaluator" << endl;
    cout << "4. Exit System" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> mainChoice;

    if (mainChoice == 1) {
        // MODULE 1: LOAN ELIGIBILITY
        int age, income, creditScore, empStatus, loanType;

        cout << "\n==========================================================" << endl;
        cout << "       MODULE 1: LOAN & CREDIT ELIGIBILITY CHECKER        " << endl;
        cout << "==========================================================" << endl;

        cout << "Enter Age: ";
        cin >> age;

        if (age < 21 || age > 60) {
            cout << "\n[RESULT] REJECTED: Age must be between 21 and 60 years." << endl;
          }

        else {
            cout << "Select Employment Status (1 for Permanent, 2 for Contract, 3 for Unemployed): ";
            cin >> empStatus;

          
            if (empStatus == 3) {
                cout << "\n[RESULT] REJECTED: Stable income/employment required." << endl;
                }
          
            else if (empStatus == 1 || empStatus == 2) {
                cout << "Enter Monthly Salary (USD): ";
                cin >> income;

             
                if (income < 1000) {
                    cout << "\n[RESULT] REJECTED: Minimum income threshold is $1000." << endl;
                }
               
                else {
                 
                    cout << "Enter Credit Score (300 to 850): ";
                    cin >> creditScore;

                    cout << "\nSelect Loan Type Desired:" << endl;
                    cout << "1. Personal Loan\n2. Home Auto Loan\n3. Premium Credit Card" << endl;
                    cout << "Choice: ";
                    cin >> loanType;

                    cout << "\n------------------ EVALUATION SUMMARY ------------------" << endl;

                    if (loanType == 1) {
                        if (creditScore >= 750 && income >= 3000) {
                            cout << "Status        : APPROVED (Category A)" << endl;
                            cout << "Max Limit     : $30000" << endl;
                            cout << "Interest Rate : 6.5%" << endl;
                         }
                        else if (creditScore >= 650 && income >= 1500) {
                            cout << "Status        : APPROVED (Category B)" << endl;
                            cout << "Max Limit     : $15000" << endl;
                            cout << "Interest Rate : 9.0%" << endl;
                        }
                         else {
                            cout << "Status        : REJECTED (Low credit score or insufficient income)" << endl;
                         }
                    }
                      else if (loanType == 2) {
                        
                         if (creditScore >= 720 && income >= 4000 && empStatus == 1) {
                            cout << "Status        : APPROVED (Tier 1 Preferred)" << endl;
                            cout << "Max Limit     : $150000" << endl;
                            cout << "Interest Rate : 4.5%" << endl;
                        }
                   
                         else if (creditScore >= 680 && income >= 2500) {
                            cout << "Status        : APPROVED (Standard Tier)" << endl;
                            cout << "Max Limit     : $75000" << endl;
                            cout << "Interest Rate : 7.0%" << endl;
                        }
                         else {
                            cout << "Status        : REJECTED (Requires permanent job status & high credit)" << endl;
                         }
                    }
                    else if (loanType == 3) {
                         if (creditScore >= 780 && income >= 5000) {
                            cout << "Status        : APPROVED (Platinum Rewards Card)" << endl;
                            cout << "Card Limit    : $20000" << endl;
                        }
                       
                         else if (creditScore >= 680 && income >= 2000) {
                            cout << "Status        : APPROVED (Gold Classic Card)" << endl;
                            cout << "Card Limit    : $5000" << endl;
                        }
                         else {
                          
                            cout << "Status        : REJECTED (Ineligible for credit card issuance)" << endl;
                        }
                    }
                 
                    else {
                     
                       cout << "Invalid Loan Type Selected." << endl;
                     }
                }
            }
          
            else {
                cout << "Invalid Employment Status entered." << endl;
            }
        }

    }
   
    else if (mainChoice == 2) {
       
        
        // MODULE 2: TAX & SALARY
      
        double grossSalary, taxRate = 0.0, taxAmount = 0.0, netSalary = 0.0;
        int healthInsurance;

        cout << "\n==========================================================" << endl;
        cout << "       MODULE 2: INCOME TAX & NET SALARY CALCULATOR       " << endl;
        cout << "==========================================================" << endl;

        cout << "Enter Monthly Gross Salary (USD): ";
        cin >> grossSalary;

        if (grossSalary <= 0) {
            cout << "Invalid salary entered." << endl;
        }
        else {
            cout << "Opt for Health Insurance Deduction? ($150/mo) [1 for Yes, 0 for No]: ";
            cin >> healthInsurance;

            if (grossSalary <= 1500) {
                taxRate = 0.0;
            }
            else if (grossSalary > 1500 && grossSalary <= 3500) {
                taxRate = 0.10;
            }
            else if (grossSalary > 3500 && grossSalary <= 7000) {
                taxRate = 0.18;
            }
            else {
                taxRate = 0.25;
            }

            taxAmount = grossSalary * taxRate;
            netSalary = grossSalary - taxAmount;

            if (healthInsurance == 1) {
                netSalary = netSalary - 150.0;
            }

            cout << "\n------------------ SALARY BREAKDOWN ------------------" << endl;
            cout << "Gross Monthly Salary : $" << grossSalary << endl;
            cout << "Applied Tax Rate     : " << (taxRate * 100) << "%" << endl;
            cout << "Total Tax Deducted   : $" << taxAmount << endl;
            if (healthInsurance == 1) {
                cout << "Health Insurance     : $150" << endl;
            }
            cout << "------------------------------------------------------" << endl;
            cout << "NET TAKE-HOME SALARY : $" << netSalary << endl;
        }

    }
    else if (mainChoice == 3) {
      
        // MODULE 3: INVESTMENT YIELD
        double depositAmount, annualReturn = 0.0, totalProfit = 0.0;
        int tenureYears, riskProfile;

        cout << "\n==========================================================" << endl;
        cout << "     MODULE 3: INVESTMENT & TERM DEPOSIT EVALUATOR       " << endl;
        cout << "==========================================================" << endl;

        cout << "Enter Principal Investment Amount (USD): ";
        cin >> depositAmount;

        if (depositAmount < 500) {
            cout << "Minimum investment required is $500." << endl;
        }
        else {
            cout << "Enter Investment Tenure in Years (1, 3, or 5): ";
            cin >> tenureYears;

            cout << "Select Risk Profile (1 for Low Risk, 2 for Moderate Risk, 3 for High Growth): ";
            cin >> riskProfile;

            if (riskProfile == 1) {
                annualReturn = 0.045;
            }
            else if (riskProfile == 2) {
                annualReturn = 0.075;
            }
            else if (riskProfile == 3) {
                annualReturn = 0.110;
            }
            else {
                cout << "Invalid Risk Profile selected." << endl;
                return 0;
            }

            if (tenureYears == 1) {
                totalProfit = depositAmount * annualReturn * 1;
            }
            else if (tenureYears == 3) {
                totalProfit = depositAmount * annualReturn * 3;
            }
            else if (tenureYears == 5) {
                totalProfit = depositAmount * annualReturn * 5;
            }
            else {
                cout << "Invalid Tenure duration." << endl;
                return 0;
            }

            cout << "\n------------------ INVESTMENT PROJECTION ------------------" << endl;
            cout << "Initial Deposit      : $" << depositAmount << endl;
            cout << "Tenure Duration      : " << tenureYears << " Year(s)" << endl;
            cout << "Annualized Rate      : " << (annualReturn * 100) << "%" << endl;
            cout << "Estimated Profit     : $" << totalProfit << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "TOTAL MATURITY VALUE : $" << (depositAmount + totalProfit) << endl;
         
         }

     }
    else if (mainChoice == 4) {
        cout << "\nThank you for using the Financial Simulator System. Goodbye!" << endl;
    }
    else {
        cout << "\nInvalid choice selected! Please restart and pick between 1 and 4." << endl;
     }

    return 0;
  }
