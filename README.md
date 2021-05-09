Author: CASINO, Benedict Matthew Hilario
Programming Language used: C++

There are 2 POS in this checkout system:

1.  Cashier
    COMPILE:
    g++ -g cashier.cpp checkout.cpp itemdatabase.cpp -o cashier

    RUN:
    ./cashier

2.  Sales Manager
    COMPILE:
    g++ -g salesmanager.cpp checkout.cpp itemdatabase.cpp -o sales

    RUN:
    ./sales

Sales Manager is expected to only adjust itemdatabase off working hours.
i.e. ./sales should not modify itemdatabase while ./cashier is undergoing checkout
