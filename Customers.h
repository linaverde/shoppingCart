//
// Created by Polina on 16.06.2019.
//

#ifndef SHOP_CUSTOMERS_H
#define SHOP_CUSTOMERS_H

#include <vector>
#include "Shop.h"

using namespace std;

class Money {
    unsigned int currency;
    unsigned int count;
};

class Wallet {
    vector<unsigned int> savingMoney;
public:
    void addMoney(Money money);

    bool rmMoney(Money money);
};

class Сonverter {
public:
    Money convert(Money from, Money into);
};

class Customer {
    ShoppingCart *cart;
public:

    virtual bool isSatisfied() = 0;

    virtual bool canBuyAll() = 0;

};

class Human : Customer {
    Wallet *wallet;
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
    bool isSatisfied() override;

    bool canBuyAll() override;
};

#endif //SHOP_CUSTOMERS_H
