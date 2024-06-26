#include "Header.h"

void bankomatui() {
    Bankomat atm;
    atm.insertCard();

    bool continueTransaction = true;
    int operation;

    cout << "Добро пожаловать!" << endl;

    while (continueTransaction) {
        atm.performTransaction();
        cout << "Хотите выполнить еще одну операцию? 1 - Да, 0 - Нет: ";
        while (!(cin >> operation) || (operation != 1 && operation != 0)) {
            cout << "Неправильный ввод. Будьте внимательны." << endl << endl;
            cout << "Хотите выполнить еще одну операцию? 1 - Да, 0 - Нет: ";
            cin.clear(); 
            cin.ignore(100, '\n'); 
        }
        continueTransaction = operation == 1;
    }
}