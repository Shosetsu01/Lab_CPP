#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Banknote {
    string name;
    int denomination;
    int exchangeRates;
};

void sumArray(int *arr, int n);
void sumArray(Banknote *banknotes, int n);

int main() {
    int n = 1;
    cout << "Введите количество Банкнот, которые вы хотите добавить\n";
    cin >> n;
    Banknote *banknotes = new Banknote[n];
    int *int_arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Введите название банкноты №" << 1 + i << endl;
        cin >> banknotes[i].name;
        cout << "Введите номинал для " << banknotes[i].name << endl;
        cin >> banknotes[i].denomination;
        cout << "Введите курс к рублю для " << banknotes[i].name << endl;
        cin >> banknotes[i].exchangeRates;
    }

    for (int i = 0; i < n; i++) {
        cout << "Банкнота: " << banknotes[i].name << " с номиналом: " << banknotes[i].denomination 
            << " и курсом к рублю: " << banknotes[i].exchangeRates << endl;
    }

    sumArray(banknotes, n);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
       int_arr[i] = rand() % 100;
       cout << "Массив int " << int_arr[i] << "\t";  
    }

    cout << endl;
    sumArray(int_arr, n);
    
    delete[] banknotes;
    delete[] int_arr;
}

void sumArray(Banknote *banknotes, int n){
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += banknotes[i].exchangeRates * banknotes[i].denomination;
    }
    cout << endl << "Сумма банкнот в рублях = " << sum << endl;
}

void sumArray(int *arr, int n) {
        double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << endl << "Сумма массива int = " << sum << endl;
}