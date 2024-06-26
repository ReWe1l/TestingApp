#include "Header.h"

void bankomatui() {
    Bankomat atm;
    atm.insertCard();

    bool continueTransaction = true;
    int operation;

    cout << "����� ����������!" << endl;

    while (continueTransaction) {
        atm.performTransaction();
        cout << "������ ��������� ��� ���� ��������? 1 - ��, 0 - ���: ";
        while (!(cin >> operation) || (operation != 1 && operation != 0)) {
            cout << "������������ ����. ������ �����������." << endl << endl;
            cout << "������ ��������� ��� ���� ��������? 1 - ��, 0 - ���: ";
            cin.clear(); 
            cin.ignore(100, '\n'); 
        }
        continueTransaction = operation == 1;
    }
}