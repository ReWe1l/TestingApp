#ifndef HEADER_H
#define HEADER_H

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Bankomat {
private:
    string cardNumber;
    double balance;
    ofstream transactionFile;

    bool isRoundAmount(double amount) {
        return static_cast<int>(amount) % 10 == 0;
    }

    bool loadCardInfo() {
        ifstream cardFile(cardNumber + ".txt");
        if (cardFile.is_open()) {
            cardFile >> balance;
            cardFile.close();
            return true;
        }
        return false;
    }

    void updateCardInfo() {
        ofstream cardFile(cardNumber + ".txt");
        if (cardFile.is_open()) {
            cardFile << balance;
            cardFile.close();
        }
        else {
            cerr << "������ ��� ���������� ����� �����." << endl;
        }
    }

public:
    Bankomat() : balance(0) {
        transactionFile.open("transactions.txt", ios::app);
    }

    ~Bankomat() {
        if (transactionFile.is_open()) {
            transactionFile.close();
        }
    }

    void insertCard() {
        cout << "������� ����� �����: ";
        cin >> cardNumber;
        if (!loadCardInfo()) {
            cerr << "����� �� �������. ���� ������� ������ � ����� " << cardNumber << " � �������� 0." << endl;
            balance = 0;
            updateCardInfo();
        }
        transactionFile << endl << "����� ���������: " << cardNumber << " ������: " << balance << endl;
    }

    void depositFunds() {
        double amount;
        cout << "������� ����� ��� ���������� (������� 10): ";
        cin >> amount;
        if (!isRoundAmount(amount)) {
            cout << "����� ������ ���� ������� 10." << endl;
            return;
        }
        balance += amount;
        updateCardInfo();
        transactionFile << "����������: " << amount << " ����� ������: " << balance << endl;
        cout << "����� ������: " << balance << endl << endl;
    }

    void withdrawFunds() {
        double amount;
        cout << "������� ����� ��� ������ (������� 10): ";
        cin >> amount;
        if (!isRoundAmount(amount)) {
            cout << "����� ������ ���� ������� 10." << endl;
            return;
        }
        if (amount > balance) {
            cout << "������������ ������� �� �����." << endl;
            return;
        }

        vector<int> notes = { 5000, 2000, 1000, 500, 100, 50, 10 };
        vector<int> toGive(notes.size(), 0);
        double originalAmount = amount;

        for (size_t i = 0; i < notes.size(); ++i) {
            toGive[i] = static_cast<int>(amount) / notes[i];
            amount -= toGive[i] * notes[i];
            if (toGive[i] > 0) {
                cout << "����� ��������� " << notes[i] << " - " << toGive[i] << endl;
            }
        }

        balance -= originalAmount;
        updateCardInfo();
        cout << "�������� �����. ����������, �������� ������." << endl << endl;
        transactionFile << "������ �������: " << originalAmount << " ����� ������: " << balance << endl;
        cout << "����� ������: " << balance << endl;
    }

    void performTransaction() {
        int choice;
        cout << "�������� ��������: 1 - ����������, 2 - ������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            depositFunds();
            break;
        case 2:
            withdrawFunds();
            break;
        default:
            cout << "�������� ����� ��������." << endl;
        }
    }
};

void bankomatui();

#endif
