#pragma once

#include <iostream>
#include <string>
#include <map>
#include "itemdatabase.h"

using namespace std;

class Checkout
{
private:
    map<string, int> checkoutList;
    ItemDatabase ItemDB;

    float TotalPrice;

    class Deal{
        private:  
        public:
            int dealType;
            virtual void run(map<string, int> &checkoutList, float &TotalPrice, ItemDatabase& ItemDB) = 0;
            virtual void print() = 0;
            virtual void save(ofstream& ofs) = 0;
    };

    class xForYDeal: public Deal{
        private:
            int x, y; string s;
        public:
            xForYDeal(int x, int y, string s){
                dealType = 0;
                this->x = x;
                this->y = y;
                this->s = s;
            }

            void run(map<string, int> &checkoutList, float &TotalPrice, ItemDatabase& ItemDB){
                if(checkoutList.count(s)){
                    float count = (int) (checkoutList[s] / x);
                    TotalPrice += count * ItemDB.getPrice(s) * y;
                    checkoutList[s] %= x;
                } 
            }

            void print(){
                cout << "Buy " << x << " " << s << "(s) for the price of " << y << endl;
            }

            void save(ofstream& ofs){
                ofs << x << endl;
                ofs << y << endl;
                ofs << s << endl;
            }
    };

    class bulkDeal: public Deal{
        private:
            int x; float y; string s;
        public:
            bulkDeal(int x, float y, string s){
                dealType = 1;
                this->x = x;
                this->y = y;
                this->s = s;
            }

            void run(map<string, int> &checkoutList, float &TotalPrice, ItemDatabase& ItemDB){
                if(checkoutList.count(s) && checkoutList[s] > x){
                    TotalPrice += checkoutList[s] * y;
                    checkoutList[s] = 0;
                } 
            }

            void print(){
                cout << "Pay " << y << " for each " << s << " if more than " << x << " is purchased" << endl;
            }

            void save(ofstream& ofs){
                ofs << x << endl;
                ofs << y << endl;
                ofs << s << endl;
            }
    };

    class bundleDeal: public Deal{
        private:
            string s1; string s2;
        public:
            bundleDeal(string s1, string s2){
                dealType = 2;
                this->s1 = s1;
                this->s2 = s2;
            }

            void run(map<string, int> &checkoutList, float &TotalPrice, ItemDatabase& ItemDB){
                if(checkoutList.count(s1)){
                    if (checkoutList[s1] >= checkoutList[s2])
                        checkoutList[s2] = checkoutList[s1];
                    
                    TotalPrice -= checkoutList[s2] * ItemDB.getPrice(s2);
                } 
            }
            
            void print(){
                cout << "Get a free " << s2 << " for every " << s1 << " purchased" << endl;
            }

            void save(ofstream& ofs){
                ofs << s1 << endl;
                ofs << s2 << endl;
            }

    };

    list<Deal*> deals;
    
public:
    Checkout();
    ~Checkout();

    void help();
    void print();

    void add(string &sku);
    void rm(string sku);

    void cancel();
    void done();

// --------------------------------

    void addDeal();
    void rmDeal(int i);

    void dealsHelp();
    void printDeals();

    void readDealsFile();
    void saveDealChanges();
};
