#include "checkout.h"

using namespace std;

string itemDealsFile = "deals.txt";

Checkout::Checkout()
{
    readDealsFile();
}

Checkout::~Checkout()
{
    while (!deals.empty())
    {
        delete deals.back();
        deals.pop_back();
    }
}

void Checkout::help()
{
    cout << "\t!add <sku> : Add Item into Checkout" << endl;
    cout << "\t!rm <sku> : Remove Item into Checkout" << endl;
    cout << "\t!cancel : Cancel Checkout" << endl;
    cout << "\t!done : Finish Checkout" << endl;
}

void Checkout::print()
{
    cout << "\tSKU"
         << "\tQUANTITY" << endl;

    for (auto item : checkoutList)
        cout << "\t" << item.first << "\t" << item.second << endl;
    cout << endl;
}

void Checkout::add(string &sku)
{
    if (ItemDB.itemExists(sku))
    {
        if (checkoutList.count(sku))
            ++checkoutList[sku];
        else
            checkoutList.insert(pair<string, int>(sku, 1));

        cout << "\tAdded '" << sku << "' into list" << endl;
    }
    else
        cout << "\tItem does not exist in the database";
}

void Checkout::rm(string sku)
{
    if (checkoutList.count(sku))
    {
        if (--checkoutList[sku] == 0)
            checkoutList.erase(sku);
        cout << "\tRemoved '" << sku << "' from list" << endl;
    }
    else
        cout << "\t'" << sku << "' does not exist in the list" << endl;
}

void Checkout::cancel()
{
    cout << "\tCancelling Checkout Order ..." << endl;
}

void Checkout::done()
{
    // Deals
    for (auto deal : deals){
        deal->run(checkoutList, TotalPrice, ItemDB);
    }

    // Normal Purchases
    for (auto item : checkoutList)
       TotalPrice += ItemDB.getPrice(item.first) * item.second;

    cout << "\tTotal expected:" << TotalPrice << endl;

}

void Checkout::addDeal(){
    
    int i;
    cout << "\t1) X for Y Deal" << endl;
    cout << "\t2) Bulk Purchase Deal" << endl;
    cout << "\t3) Bundle Deal" << endl;
    cout << "\tEnter the index of Deal Type: ";
    cin >> i;

    if (i == 1){
        int x, y; string s;
        do {
            cout << endl;
            ItemDB.showcase();
            cout << "\tInput the item sku for the deal: ";
            cin >> s;
        } while (!ItemDB.itemExists(s));
        cout << "\tInput the amount of items needed for this deal: ";
        cin >> x;
        cout << "\tInput the amount of items needed to be paid from this deal: ";
        cin >> y;
        Deal* d = new xForYDeal(x, y, s);
        deals.push_back(d);
    } else if (i == 2){
        int x; float y; string s;
        do {
            cout << endl;
            ItemDB.showcase();
            cout << "\tInput the item sku for the deal: ";
            cin >> s;
        } while (!ItemDB.itemExists(s));
        cout << "\tInput the min. amount of items needed for this deal: ";
        cin >> x;
        cout << "\tInput the reduced price of each item: ";
        cin >> y;
        Deal* d = new bulkDeal(x, y, s);
        deals.push_back(d);
    } else if (i == 3){
        string s1, s2;
        do {
            cout << endl;
            ItemDB.showcase();
            cout << "\tInput the item sku for the deal: ";
            cin >> s1;
        } while (!ItemDB.itemExists(s1));
        do {
            cout << endl;
            ItemDB.showcase();
            cout << "\tInput the item sku that's bundled in this deal: ";
            cin >> s2;
        } while (!ItemDB.itemExists(s2));
        Deal* d = new bundleDeal(s1, s2);
        deals.push_back(d);
    }
}

void Checkout::rmDeal(int i)
{
    int count = 0;
    for (auto deal : deals){
        if (count++ == i){
            deals.remove(deal);
            delete deal;
            cout << "\tDeal Removed" << endl;
            return;
        }
    }
}

void Checkout::dealsHelp()
{
    cout << "\t!add : Add Deal" << endl;
    cout << "\t!rm <index> : Remove Deal" << endl;
    cout << "\t!save : Save Deal Changes" << endl;
    cout << "\t!exit : Exit SpecialDeals" << endl;
}

void Checkout::readDealsFile()
{
    ifstream readFile;
    readFile.open(itemDealsFile);

    if (!readFile.good())
    {
        cout << "Error: unable to open input file '" << itemDealsFile << "'" << endl;
        throw invalid_argument("Item Database File cannot be reached");
    }
    string input;
    while (!readFile.eof()){
        readFile >> input;
        if (input == "-"){
            int x, y; string s;
            readFile >> x >> y >> s;
            Deal* d = new xForYDeal(x, y, s);
            deals.push_back(d);
        }
        
        else if (input == "+"){
            int x; float y; string s;
            readFile >> x >> y >> s;
            Deal* d = new bulkDeal(x, y, s);
            deals.push_back(d);
        } 
        
        else if (input == "="){
            string s1, s2;
            readFile >> s1 >> s2;
            Deal* d = new bundleDeal(s1, s2);
            deals.push_back(d);
        }
    }
    readFile.close();
}

void Checkout::printDeals()
{
    int counter = 0;
    for (auto deal : deals){
        cout << "\t" << counter++ << ") ";
        deal->print();
    }
}

void Checkout::saveDealChanges()
{
    ofstream ofs(itemDealsFile, ofstream::trunc);

    string signs[3] = {"-", "+", "="};
    for (auto deal : deals){
        ofs << signs[deal->dealType] << endl;
        deal -> save(ofs);
    }

    ofs.close();
}