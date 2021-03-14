#include <chrono>
#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10;
 
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    cout << a - b;
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