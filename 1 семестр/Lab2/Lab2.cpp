#include <iostream>
#include <stdlib.h>
#include <iomanip>

double random(double min, double max);
void umnoz(double** A, double** B , double** C, int N);
void vivod(double** A, int N);

int main (){

    int n = 1;
    std::cout << "Введите число N, для определения размерности массивов\n";
    std::cin >> n;
    const int N = n;

    //Выделение памяти для массивов А,В,С
    double **A = new double*[N];
    double **B = new double*[N];
    double **C = new double*[N];
    for(int i = 0; i < N; i++){
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];   
    }

    //Заполнение массивов А и В
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = random(0.0, 10.0);
            B[i][j] = random(0.0, 10.0);
        }
    } 

    //Вызов функции перемножения массивов А и В
    umnoz(A, B, C, N);

    //Вывод массивов А,В,С
    std::cout << '\n' << "Массив А\n";
    vivod(A, N);
    std::cout << '\n' << "Массив B\n";
    vivod(B, N);
    std::cout << '\n' << "Массив C\n";
    vivod(C, N);

    //Очистка памяти
    for(int i = 0; i < N; i++){
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;   
    delete[] B;      
    delete[] C;
    
    return 0;
}

double random(double min, double max){
    return (double)(rand())/RAND_MAX*(max - min) + min;
} 

void umnoz(double** A, double** B , double** C, int N) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            C[i][j]=0;
            for(int k = 0; k < N; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void vivod(double** A, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::fixed << std::setprecision(4) << A[i][j] << " ";
        }
        std::cout << '\n';
    }
}
