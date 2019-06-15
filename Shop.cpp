//
// Created by polina on 27.04.19.
//
#include <ostream>
#include <iostream>
#include "Shop.h"

Soda::Soda(brand sodaBrand, flavour sodaFlavour, bool isGas) {
    this->sodaBrand = sodaBrand;
    this->sodaFlavour = sodaFlavour;
    this->isGas = isGas;
};

string Soda::getName() {
    string name;
    isGas ? name += "Gased " : name += "Not gased ";
    name += flavourString[sodaFlavour] + ' ';
    name += brandString[sodaBrand] + ' ';
    return name;
}

unsigned int Soda::getPrice() {
    unsigned int price = 0;
    isGas ? price += 20 : price += 10;
    switch (sodaBrand) {
        case 0:
            price += 40;
            break;
        case 1:
            price += 20;
            break;
        case 2:
            price += 25;
            break;
    }
    return price;
}

Tea::Tea(bool hot, color teaColor, bool withIce, unsigned int sugarCount) {
    this->hot = hot;
    this->teaColor = teaColor;
    this->withIce = withIce;
    this->sugarCount = sugarCount;
}


string Tea::getName() {
    string name;
    hot ? name += "Hot " : name += "Cold ";
    name += colorString[teaColor] + ' ';
    name += "tea ";
    withIce ? name += "with ice " : name += "";
    name += "with " + to_string(sugarCount) + " cube of sugar";
    return name;
}

unsigned int Tea::getPrice() {
    unsigned int price = 0;
    switch (teaColor) {
        case 0:
            price += 10;
            break;
        case 1:
            price += 15;
            break;
        case 2:
            price += 25;
            break;
    }
    price += sugarCount * 4;
    return price;
}

Chips::Chips(flavour chipFlavour, form chipForm, unsigned int chipCount) {
    this->chipFlavour = chipFlavour;
    this->chipForm = chipForm;
    this->chipsCount = chipCount;
}

string Chips::getName() {
    string name;
    name += to_string(chipsCount);
    name += " ";
    name += formString[chipForm];
    name += " chips with ";
    name += flavourString[chipFlavour];
    name += " flavour";
    return name;
}

unsigned int Chips::getPrice() {
    return chipsCount * 30;
}


void ShoppingCart::addProduct(Product *p) {
    cart.push_back(p);
}

unsigned int ShoppingCart::getPrice() {
    unsigned int price = 0;
    for (int i = 0; i < cart.size(); i++) {
        price += cart.at(i)->getPrice();
    }
    return price;
}

std::ostream &operator<<(std::ostream &out, const ShoppingCart &s) {
    for (int i = 0; i < s.cart.size(); i++) {
        out << s.cart.at(i)->getName() << std::endl;
    }
    return out;
}

Tea *TeaChooser::chooseHotBlackTeaWithSugar() {
    Tea *t = new Tea(true, Tea::black, false, 3);
    return t;
}

Tea *TeaChooser::chooseColdBlactTeaWithSugarAndIce() {
    return new Tea(false, Tea::black, true, 3);
}

Tea *TeaChooser::chooseColdGreenTeaWithoutSugar() {
    return new Tea(false, Tea::green, false, 0);
}

Chips *ChipsChooser::chooseMuchHotRoundChips() {
    return new Chips(Chips::chili, Chips::round, 100);
}

Chips *ChipsChooser::chooseSomeSaltSqareChips() {
    return new Chips(Chips::salt, Chips::sqare, 20);
}

Soda *SodaChooser::chooseStandartFanta() {
    return new Soda(Soda::Fanta, Soda::orange, true);
}

Soda *SodaChooser::chooseCucumberPepsiWitoutGas() {
    return new Soda(Soda::Pepsi, Soda::cucumber, false);
}

Soda *SodaChooser::chooseTomatoCola() {
    return new Soda(Soda::Cola, Soda::tomato, true);
}