/********
 Author: Sheridan Murphy
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <locale>


using namespace std;
class Money
{
private:
    double total, cost; //added cost
    int hundreds, tens, fives, ones, quarters, dimes, nickels, pennies, dollars, cents; //addrd pennies and dollars 
    float inputAmount;//added this 
    
public:
    string toString();
    string toCurrency(double amount);
    string processChange();
    string processFloat();
    string processCheck();
    string processChangeFloat();
    string processChangeChange();
};
#endif
