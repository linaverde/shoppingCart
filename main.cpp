#include <iostream>
#include <string>

#include "Cart.h"

using namespace std;


int main() {

    ShoppingCart cart;

    cart.addProduct(TeaChooser().chooseHotBlackTeaWithSugar());
    cart.addProduct(ChipsChooser().chooseSomeSaltSqareChips());
    cart.addProduct(SodaChooser().chooseCucumberPepsiWitoutGas());

    cout << cart;

    cout << "Products' price is " << cart.getPrice();
}
