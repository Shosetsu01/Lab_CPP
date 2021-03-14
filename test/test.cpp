#include <iostream>

using namespace std;


void func () {
    cout << "вывод в консоль";
}

void f2 ( void (*as) () ) {
 as();
}

int main () {
void (*f) () = func;
f2(f);
}