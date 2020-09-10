#include <iostream>
 
int main()
{
   int n = 1;
   int sum_glav = 0;
   int sum_pob = 0;
   std::cout << "Введите размерность матрицы (N)\n";
   std::cin >> n;
   std::cout << '\n';
   const int N = n;
   int mass[N][N];
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         mass[i][j] = rand() % 11;
         if (i == j) {
            sum_glav += mass[i][j];
         }
         if (i + j == N - 1) {
            sum_pob += mass[i][j];
         }
         std::cout << mass[i][j] << " ";
      }
      std::cout << '\n';
   }
   std::cout << '\n';
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (sum_glav > sum_pob) {
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