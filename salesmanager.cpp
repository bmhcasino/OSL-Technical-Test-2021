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

        // HELP Command
        if (cmd == "!help") // DONE
        {
            i->help();
        }

        // ADD Command
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

        // REMOVE Command
        else if (cmd == "!rm") // DONE
        {
            string sku;
            cin >> sku;
            i->removeItem(sku);
        }

        // PRICE Command
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


        // EXIT Command
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
            cout << "quit: Exit Sales Manager POS" << endl;
        }

        // Checkout Command
        else if (cmd == "itemdb"){
            itemdb();
        }

        // Quit Command
        else if (cmd == "quit")
        {
            cout << "** Exited Cashier POS **" << endl;
        }

        // Invalid Case
        else
        {
            cout << "Invalid Command! Try Again." << endl;
        }
    }
}