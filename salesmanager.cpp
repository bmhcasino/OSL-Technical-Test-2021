/* cashier.cpp
// Only for Cashiers
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

    while (cmd != "!exit")
    {
        cout << endl;
        i->showcase();
        cout << endl;
        cout << "\tEnter a command (!help for more info, !exit to cancel checkout): ";
        cin >> cmd;

        if (cmd == "!help")
            i->help();

        else if (cmd == "!add")
        {
            string sku, name;
            float price;
            cout << "\tEnter sku of new item: ";
            cin >> sku;
            cin.ignore();

            cout << "\tEnter name of new item: ";
            getline(cin,name);

            cout << "\tEnter price of new item: ";
            cin >> price;

            i->addItem(sku, name, price);
        }

        else if (cmd == "!rm")
        {
            string sku;
            cin >> sku;
            i->removeItem(sku);
        }

        else if (cmd == "!price")
        {
            string sku;
            float price;
            cin >> sku >> price;
            i->changePrice(sku, price);
        }

        else if (cmd == "!save")
            i->saveChanges();

        else if (cmd == "!exit")
            delete i;

        else
            cout << "\tInvalid Command! Try Again." << endl;
    }
}

void deals()
{
    Checkout* c = new Checkout();
    string cmd;

    cout << endl
         << "\t** SpecialDeals Management **" << endl;

    while (cmd != "!exit")
    {
        cout << endl;
        c->printDeals();
        cout << endl;
        cout << "\tEnter a command (!help for more info, !exit to cancel checkout): ";
        cin >> cmd;

        if (cmd == "!help") 
            c->dealsHelp();

        else if (cmd == "!add")
            c->addDeal();

        else if (cmd == "!rm") 
        {
            int i;
            cin >> i;
            c->rmDeal(i);
        }

        else if (cmd == "!save") 
            c->saveDealChanges();

        else if (cmd == "!exit")
            delete c;

        else
            cout << "\tInvalid Command! Try Again." << endl;
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

        if (cmd == "help")
        {
            cout << "** List of Commands **" << endl;
            cout << "itemdb: Manage ItemDatabase" << endl;
            cout << "deals: Manage SpecialDeals" << endl;
            cout << "quit: Exit Sales Manager POS" << endl;
        }

        else if (cmd == "itemdb")
            itemdb();

        else if (cmd == "deals")
            deals();

        else if (cmd == "quit")
            cout << "** Exited Sales Manager POS **" << endl;

        else
            cout << "Invalid Command! Try Again." << endl;
    }
}