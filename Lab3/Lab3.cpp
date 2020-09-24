#include <iostream>
#include <stdlib.h>
#include <string>

struct Banknote {
    std::string name;
    int denomination;
    int exchange_rates;
};

int main() {
    int n = 1;
    std::cout << "Введите количество Банкнот, которые вы хотите добавить\n";
    std::cin >> n;
    Banknote banknotes[n];
    int a[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Введите название банкноты №" << 1 + i << '\n';
        std::cin >> banknotes[i].name;
        std::cout << "Введите номинал для " << banknotes[i].name << '\n';
        std::cin >> banknotes[i].denomination;
        std::cout << "Введите курс к рублю для " << banknotes[i].name << '\n';
        std::cin >> banknotes[i].exchange_rates;
        a[i] = banknotes[i].denomination * banknotes[i].exchange_rates;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Банкнота: " << banknotes[i].name << " с номиналом: " << banknotes[i].denomination 
            << " и курсом к рублю: " << banknotes[i].exchange_rates << '\n';
    }
    
}

void summa(int a, int n) {
    int sum;
    for (int i = 0; i < n; i++) {
    
    }
}