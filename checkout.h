#pragma once

#include <iostream>
#include <string>
#include <map>
#include "itemdatabase.h"

using namespace std;

// CHECKOUT Class
class Checkout
{
private:
    map<string, int> checkoutList;
    ItemDatabase ItemDB;
    float TotalPrice;

public:
    // constructor
    Checkout();

    // deconstructor;
    ~Checkout();

    // help
    void help();

    // print
    void print();

    // add
    void add(string &sku);

    // remove
    void rm(string sku);

    // cancel
    void cancel();

    // done
    void done();
};
