#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

void sort(vector<double>& data, int lenD) {
  int j = 0;
  double tmp = 0;
  for(int i=0; i<lenD; i++){
    j = i;
    for(int k = i; k<lenD; k++){
      if(data[j]>data[k]){
        j = k;
      }
    }
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
}

int main(){
  ofstream fout("D:\\Repository_Maryin_Kc-30\\RMaryin_30\\Semestr2\\Lab 1\\speed_test.txt", ios::app);
  fout << endl;
  fout << "N = " << 128000;
  fout << endl;
  fout.close();

  for (int g = 1; g < 21; g++) {

  double N = 128000;
  vector<double> v(N);
  setlocale(LC_CTYPE, "rus");
  ofstream fout("D:\\Repository_Maryin_Kc-30\\RMaryin_30\\Semestr2\\Lab 1\\speed_test.txt", ios::app);

  mt19937 engine(time(0));
  uniform_real_distribution<double> gen(-1.0, 1.0);
  for(auto& el: v)
    el = gen(engine);

  chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

  // cout << "Изначальный вектор:" << endl;
  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << ' ';
  //   }
  // cout << endl;

  sort(v, N);
  
  // cout << "Отсортированный вектор:" << endl;
  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << ' ';
  // }

  chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
  chrono::duration<double, nano> nano_diff = end - start;
  chrono::duration<double, micro> micro_diff = end - start;
  chrono::duration<double, milli> milli_diff = end - start;
  chrono::duration<double> sec_diff = end - start;
  
 
  if (!fout)
    {
        cerr << "Ошибка открытия файла!" << endl;
        exit(1);
    }

  fout << endl;
  fout << "Попытка №" << g;
  fout << endl;
  fout << "Time: " << nano_diff.count() << " nano sec." << endl;
  fout << "Time: " << micro_diff.count() << " micro sec." << endl;
  fout << "Time: " << milli_diff.count() << " milli sec." << endl;
  fout << "Time: " << sec_diff.count() << " sec." << endl;
  fout.close();
  
  }

  return 0;

  
}