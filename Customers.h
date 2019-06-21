//
// Created by Polina on 16.06.2019.
//

#ifndef SHOP_CUSTOMERS_H
#define SHOP_CUSTOMERS_H

#include <vector>
#include "Shop.h"

using namespace std;

enum currency {
    rub, eur, usd, jpy
};

class Money;

class MoneyPress;

class Money {
    unsigned int currency;
    unsigned int count;

    Money(unsigned int currency, unsigned int count);

    friend class MoneyPress;

public:
    unsigned int getCurrency();

    unsigned int getCount();

    void changeCount(int count);

    ~Money() = default;
};

class MoneyPress {
public:
    Money *printMoney(unsigned int currency, unsigned int count);
};

class Wallet {
    vector<Money> savingMoney;
public:
    void addMoney(Money money);

    bool rmMoney(Money money);
};

class Converter {
    struct rate {
        unsigned int from;
        unsigned int into;
        float ratio;

        rate(unsigned int from, unsigned int into, float ratio);
    };

    vector<rate> rateCollection;

public:
    Money *convert(Money &from, unsigned int into);

    void addRate(unsigned int from, unsigned int into, float ratio);
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
