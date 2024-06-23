#include "Header.h"

void bankomatui() {
    Bankomat atm;
    atm.insertCard();

    bool continueTransaction = true;
    int operation;

    cout << "Добро пожаловать!" << endl;
    cout << "В рамках тестирования на Вашу карту были зачислены 1000 рублей." << endl << endl;

    while (continueTransaction) {
        atm.performTransaction();
        cout << "Хотите выполнить еще одну операцию? 1 - Да, 0 - Нет: ";
        cin >> operation;
        continueTransaction = operation == 1;
    }
}