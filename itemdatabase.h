#pragma once

#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class ItemDatabase
{
private:
    class Item
    {
    public:
        string sku;
        string name;
        float price;

        Item(string sku, string name, float price)
        {
            this->sku = sku;
            this->name = name;
            this->price = price;
        }

        void print()
        {
            cout <<"\t" << sku << "\t" << price << "\t" << name << endl;
        }
    };

    list<Item *> items;

public:
    ItemDatabase();
    ~ItemDatabase();

    float getPrice(string sku);
    bool itemExists(string &sku);

    void addItem(string sku, string name, float price);
    void removeItem(string sku);

    void changePrice(string sku, float price);

    void saveChanges();
    void readDBFile();

    void showcase();
    void help();
};