//
// Created by Polina on 16.06.2019.
//

#ifndef SHOP_CUSTOMERS_H
#define SHOP_CUSTOMERS_H

#include <vector>
#include "Shop.h"
#include "Money.h"

using namespace std;


class Customer {
    ShoppingCart *cart;
public:

    virtual bool isSatisfied() = 0;

    virtual bool canBuyAll() = 0;

};

class Human : Customer {
    Wallet *wallet;
    ShoppingCart cart;
public:
    bool isSatisfied() override;

    bool canBuyAll() override;
};

class Child : Human {
public:
    bool isSatisfied() override;

};

class Man : Human {
public:
    bool isSatisfied() override;

};

class Woman : Human {
public:
    bool isSatisfied() override;

};

class Family : Customer {
    vector<Human> members;
public:
    void addMember(Human *member);

    bool isSatisfied() override;

    bool canBuyAll() override;
};

#endif //SHOP_CUSTOMERS_H
