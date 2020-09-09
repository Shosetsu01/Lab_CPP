#include <iostream>

int main (){
    int n = 1;
    std::cout << "Введите целое число N\n";
    std::cin >> n;
    const int N = n;
    int mass[N][N] = {0};
    int sumgl = 0;
    int sumpb = 0;
    // заполнение массива и вывод массива + нахождение сумм диагоналей
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mass[i][j] = rand() % 11;
            if (i = j) {
                sumgl += mass[i][j];
            }
            else if (i + j == N - 1) {
                sumpb += mass[i][j];
            }
            std::cout << mass[i][j] << " ";
        }
        std::cout << '\n';
    }
    
    std::cout << '\n';
    
    // выполнение условия после сравнения диагоналей
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            if (sumgl > sumpb) {
                mass[i][j] *= 2; 
                std::cout << mass[i][j] << " ";
            }
            else {
                mass[i][j] %= 6;
                std::cout << mass[i][j] << " ";
            }
         }
        std::cout << '\n';
    }
    
    return 0;
}