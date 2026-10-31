#include <iostream>

using namespace std;

// --- MODULE 1: LOAN & CREDIT ELIGIBILITY CHECKER ---
void processLoanChecker() {
    int applicantAge = 0;
    int monthlyIncome = 0;
    int scoreCredit = 0;
    int employmentType = 0;
    int selectedLoanType = 0;

    cout << "\n----------------------------------------------------------" << endl;
    cout << "          LOAN & CREDIT ELIGIBILITY CHECKER               " << endl;
    cout << "----------------------------------------------------------" << endl;
    
    cout << "Enter Age (Years): ";
    cin >> applicantAge;

    // Age validation
    if (applicantAge < 21 || applicantAge > 60) {
        cout << "\n[RESULT: REJECTED] Age requirement is between 21 and 60 years." << endl;
        return;
    }

    cout << "Select Employment Status (1: Permanent, 2: Contract, 3: Unemployed): ";
    cin >> employmentType;

    if (employmentType == 3) {
        cout << "\n[RESULT: REJECTED] Stable income source is required." << endl;
        return;
    }

    cout << "Enter Monthly Income (USD): ";
    cin >> monthlyIncome;

    if (monthlyIncome < 1000) {
        cout << "\n[RESULT: REJECTED] Minimum required monthly income is $1000." << endl;
        return;
    }

    cout << "Enter Credit Score (300 to 850): ";
    cin >> scoreCredit;

    if (scoreCredit < 300 || scoreCredit > 850) {
        cout << "\n[ERROR] Credit Score must be between 300 and 850." << endl;
        return;
    }

    cout << "\nAvailable Loan Categories:" << endl;
    cout << "1. Personal Loan\n2. Home / Auto Loan\n3. Premium Credit Card" << endl;
    cout << "Select Choice (1-3): ";
    cin >> selectedLoanType;

    cout << "\n------------------ EVALUATION REPORT ------------------" << endl;

    if (selectedLoanType == 1) {
        if (scoreCredit >= 750 && monthlyIncome >= 3000) {
            cout << "Approval Status : APPROVED (Category A)" << endl;
            cout << "Maximum Limit   : $30,000" << endl;
            cout << "Interest Rate   : 6.5%" << endl;
        } else if (scoreCredit >= 650 && monthlyIncome >= 1500) {
            cout << "Approval Status : APPROVED (Category B)" << endl;
            cout << "Maximum Limit   : $15,000" << endl;
            cout << "Interest Rate   : 9.0%" << endl;
        } else {
            cout << "Approval Status : REJECTED (Insufficient income or credit score)" << endl;
        }
    } 
    else if (selectedLoanType == 2) {
        if (scoreCredit >= 720 && monthlyIncome >= 4000 && employmentType == 1) {
            cout << "Approval Status : APPROVED (Tier 1 Preferred)" << endl;
            cout << "Maximum Limit   : $150,000" << endl;
            cout << "Interest Rate   : 4.5%" << endl;
        } else if (scoreCredit >= 680 && monthlyIncome >= 2500) {
            cout << "Approval Status : APPROVED (Standard Tier)" << endl;
            cout << "Maximum Limit   : $75,000" << endl;
            cout << "Interest Rate   : 7.0%" << endl;
        } else {
            cout << "Approval Status : REJECTED (Requires permanent job status & high credit)" << endl;
        }
    } 
    else if (selectedLoanType == 3) {
        if (scoreCredit >= 780 && monthlyIncome >= 5000) {
            cout << "Approval Status : APPROVED (Platinum Card)" << endl;
            cout << "Card Limit      : $20,000" << endl;
        } else if (scoreCredit >= 680 && monthlyIncome >= 2000) {
            cout << "Approval Status : APPROVED (Gold Card)" << endl;
            cout << "Card Limit      : $5,000" << endl;
        } else {
            cout << "Approval Status : REJECTED (Ineligible for credit card tier)" << endl;
        }
    } 
    else {
        cout << "Invalid Loan Type Selection." << endl;
    }
}

// --- MODULE 2: TAX & SALARY CALCULATOR ---
void processTaxCalculator() {
    double grossIncome = 0.0;
    double taxPercentage = 0.0;
    double calculatedTax = 0.0;
    double netPayout = 0.0;
    int insuranceOpt = 0;

    cout << "\n----------------------------------------------------------" << endl;
    cout << "          INCOME TAX & NET SALARY CALCULATOR              " << endl;
    cout << "----------------------------------------------------------" << endl;

    // Input validation loop
    do {
        cout << "Enter Monthly Gross Salary (USD): ";
        cin >> grossIncome;
        if (grossIncome <= 0) {
            cout << "[ERROR] Salary must be greater than 0. Please try again.\n";
        }
    } while (grossIncome <= 0);

    cout << "Opt for Health Insurance Deduction? ($150/mo) [1: Yes, 0: No]: ";
    cin >> insuranceOpt;

    // Progressive slab system
    if (grossIncome <= 1500) {
        taxPercentage = 0.0;
    } else if (grossIncome <= 3500) {
        taxPercentage = 0.10;
    } else if (grossIncome <= 7000) {
        taxPercentage = 0.18;
    } else {
        taxPercentage = 0.25;
    }

    calculatedTax = grossIncome * taxPercentage;
    netPayout = grossIncome - calculatedTax;

    if (insuranceOpt == 1) {
        netPayout -= 150.0;
    }

    cout << "\n------------------- PAYSLIP BREAKDOWN -------------------" << endl;
    cout << "Gross Income        : $" << grossIncome << endl;
    cout << "Applied Tax Rate    : " << (taxPercentage * 100) << "%" << endl;
    cout << "Tax Deducted        : $" << calculatedTax << endl;
    if (insuranceOpt == 1) {
        cout << "Health Insurance    : $150.00" << endl;
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "NET TAKE-HOME PAY   : $" << netPayout << endl;
}

// --- MODULE 3: INVESTMENT YIELD EVALUATOR ---
void processInvestmentEvaluator() {
    double initialPrincipal = 0.0;
    double yieldRate = 0.0;
    double maturityValue = 0.0;
    int durationYears = 0;
    int userRiskProfile = 0;

    cout << "\n----------------------------------------------------------" << endl;
    cout << "          INVESTMENT & YIELD EVALUATOR                    " << endl;
    cout << "----------------------------------------------------------" << endl;

    // Input validation loop for deposit
    do {
        cout << "Enter Principal Investment Amount (Min $500): ";
        cin >> initialPrincipal;
        if (initialPrincipal < 500) {
            cout << "[ERROR] Minimum investment amount required is $500.\n";
        }
    } while (initialPrincipal < 500);

    cout << "Select Investment Tenure (1, 3, or 5 Years): ";
    cin >> durationYears;

    if (durationYears != 1 && durationYears != 3 && durationYears != 5) {
        cout << "[ERROR] Invalid Tenure selected. Program supports 1, 3, or 5 years." << endl;
        return;
    }

    cout << "Select Risk Profile (1: Low Risk, 2: Moderate Risk, 3: High Growth): ";
    cin >> userRiskProfile;

    if (userRiskProfile == 1) {
        yieldRate = 0.045;
    } else if (userRiskProfile == 2) {
        yieldRate = 0.075;
    } else if (userRiskProfile == 3) {
        yieldRate = 0.110;
    } else {
        cout << "[ERROR] Invalid Risk Profile selected." << endl;
        return;
    }

    // Standard Compound Calculation without external libraries
    maturityValue = initialPrincipal;
    for (int year = 1; year <= durationYears; year++) {
        maturityValue = maturityValue * (1 + yieldRate);
    }

    double totalProfit = maturityValue - initialPrincipal;

    cout << "\n------------------ INVESTMENT SUMMARY ------------------" << endl;
    cout << "Principal Deposit   : $" << initialPrincipal << endl;
    cout << "Tenure Period       : " << durationYears << " Year(s)" << endl;
    cout << "Annualized Rate     : " << (yieldRate * 100) << "%" << endl;
    cout << "Total Estimated Gain: $" << totalProfit << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "MATURITY VALUE      : $" << maturityValue << endl;
}

// --- MAIN CONTROL LOOP ---
int main() {
    int userMenuChoice = 0;

    do {
        cout << "\n==========================================================" << endl;
        cout << "      SMART FINANCIAL EVALUATION & SIMULATOR SYSTEM       " << endl;
        cout << "==========================================================" << endl;
        cout << "1. Loan & Credit Card Eligibility Checker" << endl;
        cout << "2. Income Tax & Net Salary Calculator" << endl;
        cout << "3. Investment & Term Deposit Yield Evaluator" << endl;
        cout << "4. Exit System" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Enter Choice (1-4): ";
        cin >> userMenuChoice;

        switch (userMenuChoice) {
            case 1:
                processLoanChecker();
                break;
            case 2:
                processTaxCalculator();
                break;
            case 3:
                processInvestmentEvaluator();
                break;
            case 4:
                cout << "\nExiting Financial Simulator System. Thank you!" << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid option! Please select a valid option (1-4)." << endl;
        }

    } while (userMenuChoice != 4);

    return 0;
}
