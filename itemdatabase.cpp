#include "itemdatabase.h"

using namespace std;

string itemDBfile = "itemDB.txt";

void removeSpecialCharacter(string &s)
{
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z') 
        {   
            s.erase(i, 1); 
            i--;
        }
    }
}

ItemDatabase::ItemDatabase()
{
    this->readDBFile();
}

ItemDatabase::~ItemDatabase()
{
    while (!items.empty())
    {
        delete items.back();
        items.pop_back();
    }
}

float ItemDatabase::getPrice(string sku)
{
    for (auto item : items)
        if (item->sku == sku)
            return item->price;
    return -1;
}

bool ItemDatabase::itemExists(string &sku)
{
    for (auto item : items)
        if (item->sku == sku)
            return true;
    return false;
}

void ItemDatabase::addItem(string sku, string name, float price)
{
    if (!itemExists(sku))
    {
        Item *item = new Item(sku, name, price);
        items.push_back(item);
    }
}

void ItemDatabase::removeItem(string sku)
{
    for (auto item : items){
        if (item->sku == sku)
        {
            items.remove(item);
            delete item;
            cout << "\tItem Removed" << endl;
            return;
        }
    }
    cout << "\tItem Doesn't exist" << endl;
}

void ItemDatabase::changePrice(string sku, float price)
{
    for (auto item : items)
        if (item->sku == sku){
            item->price = price; break;
        }
}

void ItemDatabase::saveChanges()
{
   ofstream ofs(itemDBfile, ofstream::trunc);
   for (auto item : items){
       ofs << item->sku << endl;
       ofs << item->name << endl;
       ofs << item->price << endl;
   }
   ofs.close();
}

void ItemDatabase::readDBFile()
{
    ifstream readFile;
    readFile.open(itemDBfile);

    if (!readFile.good())
    {
        cout << "Error: unable to open input file '" << itemDBfile << "'" << endl;
        throw invalid_argument("Item Database File cannot be reached");
    }
    int counter = 0;
    float price;
    string sku, name, line;
    while (getline(readFile, line))
    {
        if (counter == 0)
        {
            removeSpecialCharacter(line);
            sku = line;
            ++counter;
        }
        else if (counter == 1)
        {
            name = line;
            ++counter;
        }
        else if (counter == 2)
        {
            price = stof(line);
            addItem(sku, name, price);
            counter = 0;
        }
    }
    readFile.close();
}

void ItemDatabase::showcase()
{
    for (auto item : items)
        item->print();
}

void ItemDatabase::help(){
    cout << "\t!add: Add Item into Database" << endl;
    cout << "\t!rm <sku>: Remove Item into Checkout" << endl;
    cout << "\t!price <sku> <price>: Change Price of Item" << endl;
    cout << "\t!save: Save Changes in Database" << endl;
    cout << "\t!exit: Finish Checkout" << endl;
}