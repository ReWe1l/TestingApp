#include "Header.h"

void bankomatui() {
    Bankomat atm;
    atm.insertCard();

    bool continueTransaction = true;
    int operation;

    cout << "����� ����������!" << endl;
    cout << "� ������ ������������ �� ���� ����� ���� ��������� 1000 ������." << endl << endl;

    while (continueTransaction) {
        atm.performTransaction();
        cout << "������ ��������� ��� ���� ��������? 1 - ��, 0 - ���: ";
        cin >> operation;
        continueTransaction = operation == 1;
    }
}