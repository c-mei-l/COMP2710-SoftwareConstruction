/*
* Courtney Lee
* cml0082@auburn.edu
* project1_Lee_cml0082.cpp
*
* Program to accept user input and return information about loan payments
*
* I consulted "C++ Language Tutorial" by Juan Soulie about concatenating output syntax.
*
* I used the hints provided for this project to construct my source code.
*
* My sister, Brittany Lee, helped me understand the construction and terminology of loans
 
* compliation instruction: g++ project1_Lee_cml0082.cpp
*
*/

#include <iostream>

using namespace std;

int main() {
   
   //Instantiating variables
   double loanAmount = 0;
   double interestRateY; //yearly
   double interestRateM; //monthly
   double interestRateC; //calculations
   double monthlyPayment;
   int monthCount = 0;
   double balance = loanAmount;
   double interestAmt; //for a given month
   double principalPayment;
   double interestTotal = 0;
   
   //currency formatting
   //from the hints provided
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   
   //user input for loan amount
   //loan amount must be positive, or return error
   cout << "\nLoan Amount: ";
   cin >> loanAmount;
   
   if (loanAmount <= 0 ) {
       cout << "Invalid loan\n\n";
       return 0;
   }
   
   //user input for yearly interest rate
   //interest rate must be positive, or return error
   
   cout << "Interest Rate (% per year): ";
    cin >> interestRateY;
    

        
    
    if (interestRateY < 0) {
        cout << "Invalid interest rate\n\n";
        return 0;
    }

   
   
   
   //calculations on interest rate
   interestRateM = interestRateY / 12;
   interestRateC = interestRateM / 100;
   interestAmt = interestRateC * loanAmount;
   
   
   //user input for monthly payment amounnt
   //monthly payment must be more than what interest would be for a month
   cout << "Monthly Payments: ";
   cin >> monthlyPayment;
   
   if (monthlyPayment <= 0) {
       cout << "Invalid payment\n\n";
       return 0;
   }
   
   if (monthlyPayment <= interestAmt) {
       cout << "Insufficient payment\n\n";
       return 0;
   }
   
   
   cout << endl;
   
   //Amortization Table
   cout << "*****************************************************************\n"
        << "\tAmortization Table\n"
        << "*****************************************************************\n"
        << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPrincipal\n";
   
   //loop to fill in the table
   while (loanAmount > 0) {
       
       // when no payments have been made (month 0) - fill chart with N/As and beginning loan amount
       if (monthCount == 0) {
           cout << monthCount++ << "\t\t$" << loanAmount;
           
           //formatting
           if (loanAmount < 1000) cout << "\t";
           cout << "\t" << "N/A\t\t\tN/A\t\tN/A\t\t\tN/A\n";
           
           }
       else{
           //calculations
           interestAmt = interestRateC * loanAmount;
           balance = (interestAmt + loanAmount) - monthlyPayment;
           principalPayment = monthlyPayment - interestAmt;
           interestTotal += interestAmt;
           
           
           //final payment
           //when the remaining bakance is less than the monthly payment
           if (loanAmount + interestAmt < monthlyPayment) {
               monthlyPayment = loanAmount + interestAmt;
               balance = (interestAmt + loanAmount) - monthlyPayment;
               principalPayment = monthlyPayment - interestAmt;
               
           }
           
           loanAmount = balance;
           
           cout << monthCount ++ << "\t\t$" << balance;
           
           //formatting output
           //I consulted "C++ Language Tutorial" for the syntax for concatenating the output.
           if (loanAmount < 1000)  {
           cout << "\t";
           cout << "\t$" << monthlyPayment << "\t\t" << interestRateM << "\t$" << interestAmt << "\t\t" << principalPayment << "\n";
           }
           
           
           }
           
   
   while (loanAmount ==  0) {

   cout << "**********************************************************\n\n"
        << "It takes " << monthCount - 1 << " months to pay off the loan.\n"
        << "Total interest paid is: $" << interestTotal<< "\n\n";
   return 0;
   }
}
}




