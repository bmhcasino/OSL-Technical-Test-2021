/* cashier.cpp
// Only for Cashiers
//
//
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

        // HELP Command
        if (cmd == "!help") // DONE
        {
            c->help();
        }

        // ADD Command
        else if (cmd == "!add") // DONE
        {
            string sku;
            cin >> sku;
            c->add(sku);
        }

        // REMOVE Command
        else if (cmd == "!rm") // DONE
        {
            string sku;
            cin >> sku;
            c->rm(sku);
        }

        // CANCEL Command
        else if (cmd == "!cancel") // DONE
        {
            c->cancel();
            delete c;
            break;
        }

        // DONE Command
        else if (cmd == "!done")
        {
            c->done();
            delete c;
            break;
        }

        // INVALID Case
        else
        {
            cout << "\tInvalid Command! Try Again." << endl;
        }
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

        // Help Command
        if (cmd == "help")
        {
            cout << "** List of Commands **" << endl;
            cout << "checkout: Start a New Checkout" << endl;
            cout << "quit: Exit Cashier POS" << endl;
        }

        // Checkout Command
        else if (cmd == "checkout")
    {
    checkoutSystem();
        }

        // Quit Command
        else if (cmd == "quit")
            cout << "** Exited Cashier POS **" << endl;

        // Invalid Case
        else
            cout << "Invalid Command! Try Again." << endl;
    }
}