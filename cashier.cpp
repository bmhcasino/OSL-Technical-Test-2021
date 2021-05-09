/* cashier.cpp
// Only for Cashiers
*/
#include <iostream>
#include <string>
#include <map>
#include <exception>
#include "checkout.h"

using namespace std;

void checkoutSystem()
{
    Checkout *c = new Checkout();
    string cmd;

    cout << endl
         << "\t** Starting New Checkout **" << endl;

    while (true)
    {
        cout << endl;
        c->print();
        cout << "\tEnter a command (!help for more info, !cancel to cancel checkout): ";
        cin >> cmd;

        if (cmd == "!help")
            c->help();

        else if (cmd == "!add") 
        {
            string sku;
            cin >> sku;
            c->add(sku);
        }

        else if (cmd == "!rm")
        {
            string sku;
            cin >> sku;
            c->rm(sku);
        }

        else if (cmd == "!cancel") 
        {
            c->cancel();
            delete c;
            break;
        }

        else if (cmd == "!done")
        {
            c->done();
            delete c;
            break;
        }

        else
            cout << "\tInvalid Command! Try Again." << endl;
    }
}

int main()
{
    string cmd;
    cout << "** Checkout System: Cashier POS **" << endl;

    while (cmd != "quit")
    {
        cout << endl;
        cout << "Enter a command (help for more info, quit to stop): ";
        cin >> cmd;

        if (cmd == "help")
        {
            cout << "** List of Commands **" << endl;
            cout << "checkout: Start a New Checkout" << endl;
            cout << "quit: Exit Cashier POS" << endl;
        }

        else if (cmd == "checkout")
            checkoutSystem();

        else if (cmd == "quit")
            cout << "** Exited Cashier POS **" << endl;

        else
            cout << "Invalid Command! Try Again." << endl;
    }
}