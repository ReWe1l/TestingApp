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
        cout << "Введите номер карты: ";
        cin >> cardNumber;
        transactionFile << "Карта вставлена: " << cardNumber << endl;
    }

    void depositFunds() {
        double amount;
        cout << "Введите сумму для пополнения (кратную 10): ";
        cin >> amount;
        if (!isRoundAmount(amount)) {
            cout << "Сумма должна быть кратной 10." << endl;
            return;
        }
        balance += amount;
        transactionFile << "Пополнение: " << amount << endl;
        cout << "Новый баланс: " << balance << endl;
    }

    void withdrawFunds() {
        double amount;
        cout << "Введите сумму для снятия (кратную 10): ";
        cin >> amount;
        if (!isRoundAmount(amount)) {
            cout << "Сумма должна быть кратной 10." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Недостаточно средств на счете." << endl;
            return;
        }

        // Жадный алгоритм для выдачи средств
        vector<int> notes = { 5000, 2000, 1000, 500, 100, 50, 10 };
        vector<int> toGive(notes.size(), 0);
        double originalAmount = amount;

        for (size_t i = 0; i < notes.size(); ++i) {
            toGive[i] = static_cast<int>(amount) / notes[i];
            amount -= toGive[i] * notes[i];
            if (toGive[i] > 0) {
                cout << "Купюр номиналом " << notes[i] << ": " << toGive[i] << endl;
            }
        }

        balance -= originalAmount;
        cout << "Средства сняты. Пожалуйста, заберите деньги." << endl;
        transactionFile << "Снятие средств: " << originalAmount << endl;
        cout << "Новый баланс: " << balance << endl;
    }

    void performTransaction() {
        int choice;
        cout << "Выберите операцию: 1 - Пополнение, 2 - Снятие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            depositFunds();
            break;
        case 2:
            withdrawFunds();
            break;
        default:
            cout << "Неверный выбор операции." << endl;
        }
    }
};

void bankomatui();

#endif
