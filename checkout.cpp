#include "checkout.h"

using namespace std;

Checkout::Checkout()
{
}

Checkout::~Checkout()
{
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
    {
        cout << "\t" << item.first << "\t" << item.second << endl;
    }
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
    {
        cout << "\tItem does not exist in the database";
    }
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



void Checkout::done()
{

    // Check Promos
    // Case 1: 3 atv for price of 2;
    // 3, 2, atv
    if(checkoutList.count("atv")){
        float count = (int) (checkoutList["atv"] / 3);
        TotalPrice += count * ItemDB.getPrice("atv") * 2.0;
        checkoutList["atv"] %= 3;
    } 

    //case 2: 
    // 4, 499.99 , ipd
    if(checkoutList.count("ipd") && checkoutList["ipd"] > 4){
        TotalPrice += checkoutList["ipd"] * 499.99;
        checkoutList["ipd"] = 0;
    } 

    //case 3:
    // mpd, vga
    if(checkoutList.count("mpd")){
        if (checkoutList["mpd"] >= checkoutList["vga"])
            checkoutList["vga"] = checkoutList["mpd"];
        
        TotalPrice -= checkoutList["vga"] * ItemDB.getPrice("vga");
    } 

    //normal purchases
    for (auto item : checkoutList)
    {
       TotalPrice += ItemDB.getPrice(item.first) * item.second;
    }

    cout << TotalPrice << endl;

}

void Checkout::cancel()
{
    cout << "\tCancelling Checkout Order ..." << endl;
}