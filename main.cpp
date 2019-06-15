#include <iostream>
#include <string>

#include "Shop.h"

using namespace std;

enum currency {rub, eur, usd, jpy};

int main() {

    ShoppingCart cart;

    cart.addProduct(TeaChooser().chooseHotBlackTeaWithSugar());
    cart.addProduct(ChipsChooser().chooseSomeSaltSqareChips());
    cart.addProduct(SodaChooser().chooseCucumberPepsiWitoutGas());

    cout << cart;

    cout << "Products' price is " << cart.getPrice();
}
