
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
using namespace std;

#define NICKEL 0.05
#define DIME 0.1
#define QUARTER 0.25
#define ONE 1.0
#define FIVE 5.0

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

    float total_balance()
    {
      return (nickels_balance * NICKEL + dimes_balance * DIME + quarters_balance * QUARTER + ones_balance * ONE + fives_balance * FIVE);
    }

    void display_balance()
    {
      cout << "Stock contains: " << endl;
      cout << setw(10) << nickels_balance << " nickels" << endl;
      cout << setw(10) << dimes_balance << " dimes" << endl;
      cout << setw(10) << quarters_balance << " quarters" << endl;
      cout << setw(10) << ones_balance << " ones" << endl;
      cout << setw(10) << fives_balance << " fives" << endl;

    }
    bool verify_multiple_of_fives(float price)
    {
      if (price > 0)
      {
        int price_in_cents = ceil(price * 100);
        cout << "Price is : " << price << endl;
        cout << "price in cent is : " << price_in_cents << endl;
        if (fmod(price,1.0) < 1)
        {
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
          cout << "Illegal price: Must be a non-negative multiple of 5 cents." << endl << endl;
        }
        return false;
    }
    int get_before_decimals(float price)
    {
      int price_in_cents = ceil(price * 100);
      return (price_in_cents / 100);
     
    }
    int get_cents(float price)
    {

      int price_in_cents = ceil(price * 100);
      if (fmod(price,1.0) < 1)
      {
        return (price_in_cents % 100);
      }
      return (0);
    }


    float deposit(float price)
    {
      char deposit_coin;
      float deposit = 0;
      float balance = 0;
      float change = 0;

      cout << "Menu for deposits: " << endl;
      
      cout << "   'n' - deposit a nickel" << endl;
      cout << "   'd' - deposit a dime" << endl;
      cout << "   'q' - deposit a quarter" << endl;
      cout << "   'o' - deposit a one dollar bill" << endl;
      cout << "   'f' - deposit a five dollar bill" << endl;
      cout << "   'c' - cancel the purchase" << endl;
      cout << "Payment due: " << get_before_decimals(price) << " dollars " << get_cents(price) << " cents" << endl;

      while (deposit < price)
      {

        cout << " Indicate your deposit : " ;
        cin >> deposit_coin;

        switch (deposit_coin)
        {
          case 'n':
            //cout << "A nickel is diposited" << endl;
            deposit = deposit + 0.05;
            break;
          case 'd':
            //cout << "A dime is diposited" << endl;
            deposit = deposit + 0.1;
            break;
          case 'q':
            //cout << "A quarter coin is diposited" << endl;
            deposit = deposit + 0.25;
            break;
          case 'o':
            //cout << "A one dollar note is diposited" << endl;
            deposit = deposit + 1.0;
            break;
          case 'f':
            //cout << "A five dollar note is diposited" << endl;
            deposit = deposit + 5.0;
            break;
          case 'c':
            //cout << "Transaction is cancelled" << endl;
            change = deposit;
            return change;
            break;
          default:
            cout << "Invalid" << endl;

        }
        balance = price - deposit;

        if(balance > 0)
        {
          cout << "Payment due: " << get_before_decimals(balance) << " dollars " << get_cents(balance) << " cents" << endl;
        }
      }

      change = deposit - price;


      return change;
    }

    

    bool check(float change)
    {
      if (change < total_balance())
      {
        while (change >= FIVE && fives_balance >= 1)
        {
          change = change - FIVE;
          fives_balance = fives_balance - 1;
        }
        while (change >= ONE && ones_balance >= 1)
        {
          change = change - ONE;
          ones_balance = ones_balance - 1;
        }
        while (change >= QUARTER && quarters_balance >= 1)
        {
          change = change - QUARTER;
          quarters_balance = quarters_balance - 1;
        }
        while (change >= DIME && dimes_balance >= 1)
        {
          change = change - DIME;
          dimes_balance = dimes_balance - 1;
        }
        while (change >= NICKEL && nickels_balance >= 1)
        {
          change = change - NICKEL;
          nickels_balance = nickels_balance - 1;
        }



        if(change > total_balance())
        {
            cout << "Machine is out of change. See store manager for remaining refund." << endl;
            cout << "Amount due is : " << get_before_decimals(change) << " dollars " << get_cents(change) << " cents" << endl;

        }

        return true;
      }
        
      else
      {

        cout << "Machine is out of change." << endl;

        return false;


      }
        
    }
};
 
int main() {

  cout << "Welcome to the vending machine change maker program " << endl;
  cout << "Change maker initialized. " << endl;
 
    // Declare register1
    Menu_display register1;
    register1.update(25,25,25,0,0);
    //cout << register1.total_balance() << endl;
    //cout << "Total value : " << register1.total_balance() << endl;
    register1.display_balance();
    
    float price = 0;

    do{
      cout << "Enter the purchase price (xx.xx) : " ;
      cin >> price;
    } while (register1.verify_multiple_of_fives(price) != 1);

    cout << register1.deposit(price) << endl;


     
    //&& register1.verify_multiple_of_fives(price)


    //cout << register1.verify_multiple_of_fives(1.04) << endl;
    
    //cout << register1.check(9.5) << endl;

    //register1.display_balance();
    //cout << "Total value : " << register1.total_balance() << endl;


 
    return 0;
}