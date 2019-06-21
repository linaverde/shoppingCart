#include <iostream>
#include <string>

#include "Shop.h"
#include "Customers.h"

using namespace std;



int main() {

    /*ShoppingCart cart;

    cart.addProduct(TeaChooser().chooseHotBlackTeaWithSugar());
    cart.addProduct(ChipsChooser().chooseSomeSaltSqareChips());
    cart.addProduct(SodaChooser().chooseCucumberPepsiWitoutGas());

    cout << cart;

    cout << "Products' price is " << cart.getPrice();

    MoneyPress press;

    Converter converter;
    converter.addRate(rub, eur, 0.015);
    converter.addRate(jpy, rub, 3.2);
    converter.addRate(usd, rub, 60);

    Wallet myWallet;
    myWallet.addMoney(*press.printMoney(rub, 100));
    myWallet.addMoney(*press.printMoney(usd, 20));

    Money *testMoney = press.printMoney(jpy, 100);
    Money *converted = converter.convert(*testMoney, rub);

    myWallet.addMoney(*converted);

    cout << "Ура я могу печатать деньги" << endl;*/

    TeaChooser teaChooser;
    SodaChooser sodaChooser;
    ChipsChooser chipsChooser;

    Shop *FirstShop = new Shop (rub);
    FirstShop->addProductInAssortment(sodaChooser.chooseStandartFanta());
    FirstShop->addProductInAssortment(teaChooser.chooseColdGreenTeaWithoutSugar());
    FirstShop->addProductInAssortment(chipsChooser.chooseSomeSaltSqareChips());

    Shop *SecondShop = new Shop (jpy);
    SecondShop->addProductInAssortment(sodaChooser.chooseCucumberPepsiWitoutGas());
    SecondShop->addProductInAssortment(sodaChooser.chooseCucumberPepsiWitoutGas());

    ShoppingCart cart;
    cart.addProduct(FirstShop->getProductFromAssort(5));
    cart.addProduct(FirstShop->getProductFromAssort(1));
    cart.addProduct(SecondShop->getProductFromAssort(0));

    cout << cart;

}
