/********
 Author: Sheridan Murphy
 Program: Money class - program assignment #1
 Due Date: Feb. 3, 2020
 Purpose: Program
 ********/
#include "money.h"


 // convert current currency values to a string
string Money::toString() {
    stringstream ss;

    ss << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies";

    return ss.str();
    // return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;
    ss.imbue(locale(""));

    ss << showbase << put_money(amount * 100);

    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    //Declare Variables
    stringstream ss;
    //Input change format
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies;

    //Calculations
    total = static_cast<double>(hundreds) * 100 + static_cast<double>(tens) * 10 
        + static_cast<double>(fives) * 5 
        + static_cast<double>(ones) * 1
        + static_cast<double>(quarters) * 0.25 + static_cast<double>(dimes) * 0.10 
        + static_cast<double>(nickels) * 0.05 + static_cast<double>(pennies) * 0.01;

    //Output
    ss << toString() << " = " << toCurrency(total);

    return ss.str();
    //return "";
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    
    //Declare Variables
    stringstream ss;

    //input float format
    cin >> inputAmount;

    //calculations
    hundreds = inputAmount / 100;
    int temp = static_cast<int>(inputAmount) % 100;
    tens = temp/ 10;
    temp = temp % 10;
    fives = temp / 5;
    temp = temp % 5;
    ones = temp / 1;
    temp = temp % 1;
    temp = static_cast<int>(inputAmount * 100) % 100;
    float temp2 = temp;
    quarters = temp2/25 ;
    temp2 = static_cast<int>(temp2) % 25;
    dimes = temp2 / 10;
    temp2 = static_cast<int>(temp2) % 10;
    nickels = temp2 / 5;
    temp2 = static_cast<int>(temp2) % 5;
    pennies = temp2 / 1;
    temp2 = static_cast<int>(temp2) % 1;
            
    //Output
    cout << toCurrency(inputAmount) << " = " << hundreds << " hundreds " <<  tens << " tens " << fives << " fives "<< ones << " ones " <<
        quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies";
       
    return "";
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    //Declare Variables
     string onesPlaces[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
     string tensPlaces[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
     string countByTens[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

     string names = "";
     stringstream ss;
     //input 
     cin >> total;

     //calculations
     dollars = (total / 100) * 100;
     //dollars = total;
     cents = total * 100;
     cents = cents % 100;

     //Changing from the dollar format into word format
     if (dollars < 10) {
         names = onesPlaces[dollars];
     }
     else if (dollars < 20) {
            names = tensPlaces[dollars - 10];
     }
     else if (dollars < 100) {
         names = countByTens[dollars / 10];
         if ((dollars % 10) != 0)
             names += " " + onesPlaces[dollars % 10];
     }
     else {
         names = onesPlaces[dollars / 100] + " hundreds";
     }
     ss << "Check for " << toCurrency(total) << " = " << names << " dollars and " << cents << " cents\n"; //the dollars and cents need to be read 
     return ss.str();
    }
       
// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    stringstream ss;

    //input float format
    cin >> inputAmount >> cost;

    //calculations
    double result = inputAmount - cost;
    hundreds = result / 100;
    int temp = static_cast<int>(result) % 100;
    tens = temp / 10;
    temp = temp % 10;
    fives = temp / 5;
    temp = temp % 5;
    ones = temp / 1;
    temp = temp % 1;
    temp = static_cast<int>(result * 100) % 100;
    float temp2 = temp;
    quarters = temp2 / 25;
    temp2 = static_cast<int>(temp2) % 25;
    dimes = temp2 / 10;
    temp2 = static_cast<int>(temp2) % 10;
    nickels = temp2 / 5;
    temp2 = static_cast<int>(temp2) % 5;
    pennies = temp2 / 1;
    temp2 = static_cast<int>(temp2) % 1;
    
    //Output
    ss << "Change back on " << toCurrency(inputAmount) << " for purchace of " << toCurrency(cost) << " is " << toCurrency(result) << " which is " << toString();
    return ss.str();
//return "";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    
    stringstream ss;
    //Input from Change Format
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies >> cost;

    //Calculations from Change Format
    total = static_cast<double>(hundreds) * 100 + static_cast<double>(tens) * 10 + static_cast<double>(fives) * 5 + static_cast<double>(ones)
        + static_cast<double>(quarters) * 0.25 + static_cast<double>(dimes) * 0.10 + static_cast<double>(nickels) * 0.05 + static_cast<double>(pennies) * 0.01;
    double result = total - cost; 
    
    //Float format
    hundreds = result / 100;
    int temp = static_cast<int>(result) % 100;
    tens = temp / 10;
    temp = temp % 10;
    fives = temp / 5;
    temp = temp % 5;
    ones = temp / 1;
    temp = temp % 1;
    temp = static_cast<int>(result * 100) % 100;
    float temp2 = temp;
    quarters = temp2 / 25;
    temp2 = static_cast<int>(temp2) % 25;
    dimes = temp2 / 10;
    temp2 = static_cast<int>(temp2) % 10;
    nickels = temp2 / 5;
    temp2 = static_cast<int>(temp2) % 5;
    pennies = temp2 / 1;
    temp2 = static_cast<int>(temp2) % 1;
    //Output
    ss << "Change back on " << toCurrency(total) << " for purchace of " << toCurrency(cost) << " is " 
        << toCurrency(result) << " which is " << toString();
    return ss.str();
    
}