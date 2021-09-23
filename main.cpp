
// Assignment 1
/*
1. At program start, assume a stock of 25 nickels, 25 dimes, and 25
quarters. Print the contents of the stock.
2. Repeatedly prompt the user for a price in the form xx.xx, where
x denotes a digit
3. When a price is entered:
• Check that the price entered is a (non-negative) multiple of .
05 (i.e., it is payable in nickels). If not, then print an error
message and start over requesting either a new price.
• Print a menu for indicating the coin/bill deposited or to
cancel payment.
• Prompt for a selection from this menu.
• If the user enters an illegal selection, re-prompt for a correct
one.
• Following each deposit, print the remaining amount owed
(indicate the number of dollars and the number of cents). 
• When full payment has been deposited or a ‘c’ has been
entered, determine the coins to be dispensed in change or as
refund. This calculation will depend on the amount to be
dispensed and also on the number of coins left in the stock.
For example, the least number of coins needed to make up
$1.30 is 6 — 5 quarters and 1 nickel. But if there are only 3
quarters, 3 dimes, and 10 nickels left in the stock, then the
least number is 11 — 3 quarters, 3 dimes, and 5 nickels.
• Print the numbers of the coins to be dispensed and their
denominations. (Omit a denomination if no coins of that
denomination will be dispensed.) 
• In case exact payment is deposited, print a message such as
“No change.” 
• If the change cannot be made up with the coins remaining,
dispense the coins available without exceeding the changeamount and indicate the amount still due the user, which will
have to be collected from a store manager. For example, if the
stock contains one nickel, no dimes, and a quarter and if the
change amount is 15 cents, dispense just the nickel and
indicate the user should collect 10 cents from a store manager. 
• Print the contents of the stock following the transaction.
*/
 
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

#define NICKEL 5
#define DIME 10
#define QUARTER 25
#define ONE 100
#define FIVE 500

class Menu_display
{
    // Access specifier
    public: 
    // Data Members
    int nickels_balance = 0, dimes_balance = 0, quarters_balance = 0, ones_balance = 0, fives_balance = 0;

    int nickels_change = 0, dimes_change = 0, quarters_change = 0, ones_change = 0, fives_change = 0;
    
    // Member Functions()
    void update(int nickels_update, int dimes_update, int quarters_update, int ones_update, int fives_update)
    {
       nickels_balance = nickels_balance + nickels_update;
       dimes_balance = dimes_balance + dimes_update;
       quarters_balance = quarters_balance + quarters_update;
       ones_balance = ones_balance + ones_update;
       fives_balance = fives_balance + fives_update;
    }

    // getting total balance of the register
    double total_balance()
    {
      return (nickels_balance * NICKEL + dimes_balance * DIME + quarters_balance * QUARTER + ones_balance * ONE + fives_balance * FIVE);
    }
    // getting coin balance
    void display_balance()
    {
      cout << "Stock contains: " << endl;
      cout << setw(10) << nickels_balance << " nickels" << endl;
      cout << setw(10) << dimes_balance << " dimes" << endl;
      cout << setw(10) << quarters_balance << " quarters" << endl;
      cout << setw(10) << ones_balance << " ones" << endl;
      cout << setw(10) << fives_balance << " fives" << endl;

    }

    // Verification of fives
    bool verify_multiple_of_fives(double price)
    {
      
      if (price > 0)
      {
        int price_in_cents = (price * 100);
        //cout << "Price is : " << price << endl;
        //cout << "price in cent is : " << price_in_cents << endl;
        if (fmod(price,1.0) < 1)
        {
          //cout << price_in_cents << endl;
          if( price_in_cents % 5  == 0)
            return true;
          else
            {
              cout << "Illegal price: Must be a non-negative multiple of 5 cents." << endl << endl;
            }
            return false;
        }
        else
          return true;
      }
      else
        {
          cout << "**Illegal price: Must be a non-negative multiple of 5 cents." << endl << endl;
          return false;
        }
        
    }
    int get_before_decimals(double price)
    {
      int price_in_cents = (price * 100);
      return (price_in_cents / 100);
     
    }
    int get_cents(double price)
    {

      int price_in_cents = (price * 100);
      if (fmod(price,1.0) < 1)
      {
        return (price_in_cents % 100);
      }
      return (0);
    }

    // Deposit menu for the register
    int deposit(double price)
    {
      char deposit_coin;
      int deposit_in_cents = 0;
      int balance_in_cents = 0;
      int change_in_cents = 0;
      int price_in_cents;
      if (price > 0)
        price_in_cents = (price * 100);

      //cout << price_in_cents << endl;

      cout << "Menu for deposits: " << endl;
      
      cout << "   'n' - deposit a nickel" << endl;
      cout << "   'd' - deposit a dime" << endl;
      cout << "   'q' - deposit a quarter" << endl;
      cout << "   'o' - deposit a one dollar bill" << endl;
      cout << "   'f' - deposit a five dollar bill" << endl;
      cout << "   'c' - cancel the purchase" << endl;
      cout << " Payment due: " << int(price_in_cents / 100) << " dollars " << int(price_in_cents % 100) << " cents" << endl;


      // Case structure to update coin balance
      while (deposit_in_cents < price_in_cents)
      {

        cout << " Indicate your deposit : " ;
        cin >> deposit_coin;

        switch (deposit_coin)
        {
          case 'n':
            //cout << "A nickel is diposited" << endl;
            deposit_in_cents = deposit_in_cents + NICKEL;
            nickels_balance++;
            break;
          case 'd':
            //cout << "A dime is diposited" << endl;
            deposit_in_cents = deposit_in_cents + DIME ;
            dimes_balance++;
            break;
          case 'q':
            //cout << "A quarter coin is diposited" << endl;
            deposit_in_cents = deposit_in_cents + QUARTER;
            quarters_balance++;
            break;
          case 'o':
            //cout << "A one dollar note is diposited" << endl;
           deposit_in_cents = deposit_in_cents + ONE;
            ones_balance++;
            break;
          case 'f':
            //cout << "A five dollar note is diposited" << endl;
            deposit_in_cents = deposit_in_cents + FIVE;
            fives_balance++;
            break;
          case 'c':
            //cout << "Transaction is cancelled" << endl;
            change_in_cents = deposit_in_cents;
            return change_in_cents;
            break;
          default:
            cout << "Illegal selection : " << deposit_coin << endl;

        }
     
        balance_in_cents = price_in_cents - deposit_in_cents;
        if(balance_in_cents > 0)
        {
          cout << "Payment due: " << int(balance_in_cents/100) << " dollars " << int(balance_in_cents % 100) << " cents" << endl;
        }
        //cout << "Total Deposit is : " << int(deposit_in_cents/100) << " dollars and "  << int(deposit_in_cents % 100) << " cents." << endl;
      }

      cout << endl << "Total Deposit is : " << int(deposit_in_cents/100) << " dollars and "  << int(deposit_in_cents % 100) << " cents." << endl;

      change_in_cents = deposit_in_cents - price_in_cents;


      return change_in_cents;
    }

    // Change calculation and execution

    void check(int change_in_cents)
    {
      int deposit_amount_in_cents=0;

      if(change_in_cents == 0)
      {
          cout << "   No change." << endl;
      }
      else
      {
        cout << "Change due is : " << int(change_in_cents / 100) << " dollars and " << int(change_in_cents % 100) << " cents." << endl << endl;

        nickels_change = 0, dimes_change = 0, quarters_change = 0, ones_change = 0, fives_change = 0;
          
        while (change_in_cents >= FIVE && fives_balance >= 1)
        {
          change_in_cents = change_in_cents - FIVE;
          fives_balance = fives_balance - 1;
          fives_change++;
          deposit_amount_in_cents = deposit_amount_in_cents + FIVE;
        }
        //cout << "After Fives : " << change_in_cents << endl;
        while (change_in_cents >= ONE && ones_balance >= 1)
        {
          change_in_cents = change_in_cents - ONE;
          ones_balance = ones_balance - 1;
          ones_change++;
          deposit_amount_in_cents = deposit_amount_in_cents + ONE;
        }
        //cout << "After Ones : " << change_in_cents << endl;
        while (change_in_cents >= QUARTER && quarters_balance >= 1)
        {
          change_in_cents = change_in_cents - QUARTER;
          quarters_balance = quarters_balance - 1;
          quarters_change++;
          deposit_amount_in_cents = deposit_amount_in_cents + QUARTER;
        }
        //cout << "After Quarters : " << change_in_cents << endl;
        while (change_in_cents >= DIME && dimes_balance >= 1)
        {
          change_in_cents = change_in_cents - DIME;
          dimes_balance = dimes_balance - 1;
          dimes_change++;
          deposit_amount_in_cents = deposit_amount_in_cents + DIME;
        }
        //cout << "After Dimes : " << change_in_cents << endl;
        while (change_in_cents >= NICKEL && nickels_balance > 0)
        {
          
          change_in_cents = change_in_cents - NICKEL;
          nickels_balance = nickels_balance - 1;
          nickels_change++;
          deposit_amount_in_cents = deposit_amount_in_cents + NICKEL;
          //cout << " " << change_in_cents << endl;
          //cout << " " << NICKEL << endl;
        }
        //cout << "After Nickels : " << change_in_cents << endl;

        // Displaying Change below

        cout << "Please take the change below." <<endl;
        //cout  << " Change amount : " << int(change_in_cents / 100) << " dollars and " << int(change_in_cents % 100) << " cents." << endl;
        if (fives_change > 0)
          cout << "  " << fives_change << " fives" << endl;
        if (ones_change > 0)
          cout << "  " << ones_change << " ones" << endl;
        if (quarters_change > 0)
          cout << "  " << quarters_change << " quarters" << endl;
        if (dimes_change > 0)
          cout << "  " << dimes_change << " dimes" << endl;
        if (nickels_change > 0)
          cout << "  " << nickels_change << " nickels" << endl;
        

        if(change_in_cents > 0)
        {
            cout << "Machine is out of change. See store manager for remaining refund." << endl;
            cout << "Amount due is : " << int(change_in_cents / 100) << " dollars and " << int(change_in_cents % 100) << " cents." << endl;

        }

      }
        
    }
};
 
int main() {

  string ask_continue;

  cout << endl << "Welcome to the vending machine change maker program " << endl;
  cout << "Change maker initialized. " << endl;
 
    Menu_display register1;   //Declare Register 1
    register1.update(25,25,25,0,0); //Update Register 1 with initial stock
 
    register1.display_balance(); // Display Register 1 stock
    string user_input1 = "";
    bool number_true = 0;
    double price = 0;
    int j;

    do{

      ask_continue = "";

      do{

        do{
          cout << endl << "Enter the purchase price (xx.xx) : " ;
        cin >> user_input1;

        for(j= 0; j< (user_input1.length()) ; j++)
        {
          if(isdigit(user_input1[j]))
          {
            //cout << user_input1[j] << endl;
            number_true = 0;
          }
          else
            number_true = 1;
//cout << number_true << endl;
        }
        if(number_true == 1)
          cout << "Type number in xx.xx." << endl;


        }while(number_true);

        price = stod (user_input1);
        

      } while (register1.verify_multiple_of_fives(price) != 1);

      register1.check((register1.deposit(price)));
      cout << "================================" << endl;
      register1.display_balance();
      cout << "================================" << endl;

      cout << "Do you want to continue: " ;
      cin >> ask_continue;


    }while(ask_continue =="yes" || ask_continue == "YES" || ask_continue == "Yes" || ask_continue == "Y" || ask_continue == "y");

    cout << "Register 1 closed" << endl;

    return 0;
}