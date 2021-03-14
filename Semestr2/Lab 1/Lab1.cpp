#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

void sort(double data[], int lenD) {
  int j = 0;
  int tmp = 0;
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
  double N = 1000;
  vector<double> v(N);

  mt19937 engine(time(0));
  uniform_real_distribution<double> gen(-1.0, 1.0);
  for(auto& el: v)
    el = gen(engine);

  chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
  sort(v, N);
  chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
  chrono::duration<double, nano> nano_diff = end - start;
  chrono::duration<double, micro> micro_diff = end - start;
  chrono::duration<double, milli> milli_diff = end - start;
  chrono::duration<double> sec_diff = end - start;
  cout << endl;
  cout << "Time: " << nano_diff.count() << " nano sec." << endl;
  cout << "Time: " << micro_diff.count() << " micro sec." << endl;
  cout << "Time: " << milli_diff.count() << " milli sec." << endl;
  cout << "Time: " << sec_diff.count() << " sec." << endl;
}