Author: CASINO, Benedict Matthew Hilario
Programming Language used: C++

There are 2 POS in this checkout system:

1. Cashier
   COMPILE:
   g++ -g cashier.cpp checkout.cpp itemdatabase.cpp -o cashier

RUN:
./cashier

2. Sales Manager
   COMPILE:
   g++ -g salesmanager.cpp checkout.cpp itemdatabase.cpp -o sales

Sales Manager is expected to only adjust itemdatabase off working hours.
i.e. ./sales and ./cashier should not input commands at the same time

RUN:
./sales
