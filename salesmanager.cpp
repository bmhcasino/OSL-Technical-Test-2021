/* cashier.cpp
// Only for Cashiers
//
//
*/
#include <iostream>
#include <string>
#include <map>
#include <exception>
#include "itemdatabase.h"
#include "checkout.h"
#include <bits/stdc++.h>

using namespace std;

void itemdb()
{
    ItemDatabase* i = new ItemDatabase();
    string cmd;

    cout << endl
         << "\t** ItemDatabase Management **" << endl;

    while (true)
    {
        cout << endl;
        i->showcase();
        cout << "\tEnter a command (!help for more info, !exit to cancel checkout): ";
        cin >> cmd;

        if (cmd == "!help") // DONE
        {
            i->help();
        }

        else if (cmd == "!add")
        {
            string sku, name;
            float price;
            cout << "Enter sku of new item: ";
            cin >> sku;
            cin.ignore();

            cout << "Enter name of new item: ";
            getline(cin,name);

            cout << "Enter price of new item: ";
            cin >> price;

            i->addItem(sku, name, price);
        }

        else if (cmd == "!rm") // DONE
        {
            string sku;
            cin >> sku;
            i->removeItem(sku);
        }

        else if (cmd == "!price") // DONE
        {
            string sku;
            float price;
            cin >> sku >> price;
            i->changePrice(sku, price);
        }

        else if (cmd == "!save") // DONE
        {
            i->saveChanges();
        }

        else if (cmd == "!exit") // EXIT
        {
            delete i;
            break;
        }

        // INVALID Case
        else
        {
            cout << "\tInvalid Command! Try Again." << endl;
        }
    }
}

void deals(){
    Checkout* c = new Checkout();
    string cmd;

    cout << endl
         << "\t** SpecialDeals Management **" << endl;

    while (true)
    {
        cout << endl;
        c->printDeals();
        cout << "\tEnter a command (!help for more info, !exit to cancel checkout): ";
        cin >> cmd;

        if (cmd == "!help") 
        {
            c->dealsHelp();
        }

        else if (cmd == "!add")
        {
            c->addDeal();
        }

        else if (cmd == "!rm") 
        {
            int i;
            cin >> i;
            c->rmDeal(i);
        }

        else if (cmd == "!save") 
        {
            c->saveDealChanges();
        }

        else if (cmd == "!exit") // EXIT
        {
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
    cout << "** Checkout System: Sales Manager POS **" << endl;

    while (cmd != "quit")
    {
        cout << endl;
        cout << "Enter a command (help for more info, quit to stop): ";
        cin >> cmd;

        // Help Command
        if (cmd == "help")
        {
            cout << "** List of Commands **" << endl;
            cout << "itemdb: Manage ItemDatabase" << endl;
            cout << "deals: Manage ItemDatabase" << endl;
            cout << "quit: Exit Sales Manager POS" << endl;
        }

        // Checkout Command
        else if (cmd == "itemdb"){
            itemdb();
        }

        // Deals Command
        else if (cmd == "deals"){
            deals();
        }

        // Quit Command
        else if (cmd == "quit")
        {
            cout << "** Exited Sales Manager POS **" << endl;
        }

        // Invalid Case
        else
        {
            cout << "Invalid Command! Try Again." << endl;
        }
    }
}