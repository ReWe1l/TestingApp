#include "Header.h"

void bankomatui() {
    Bankomat atm;
    atm.insertCard();

    bool continueTransaction = true;
    int operation;

    while (continueTransaction) {
        atm.performTransaction();
        cout << "������ ��������� ��� ���� ��������? 1 - ��, 0 - ���: ";
        cin >> operation;
        continueTransaction = operation == 1;
    }
}