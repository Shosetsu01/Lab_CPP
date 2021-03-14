#include <iostream>
#include <cmath>

using namespace std;

// Класс треугольников 

class Triangle
{
private:
    double a_length;
    double b_length;
    double c_length;

public:
    Triangle() {}
    Triangle(double a, double b, double c);
    ~Triangle();

    double Perimeter()
    {
        return a_length + b_length + c_length;
    }

    double Area()
    {
        // Плозадь треугольника по формуле Герона
        return sqrt((Perimeter() / 2) * ((Perimeter() / 2) - a_length) * ((Perimeter() / 2) - b_length) * ((Perimeter() / 2) - c_length));
    }

    void Info()
    {
        cout.precision(3);
        cout << "TYPE : Triangle" << endl;
        cout << "Length:" << endl;
        cout << fixed << "A: " << a_length << endl;
        cout << fixed << "B: " << b_length << endl;
        cout << fixed << "C: " << c_length << endl;

        cout << endl
             << "Perimeter: " << Perimeter() << endl
             << "Area: " << Area() << endl
             << endl;
    }
};

Triangle::Triangle(double a, double b, double c)
{
    this->a_length = a;
    this->b_length = b;
    this->c_length = c;
}

Triangle::~Triangle()
{
}


// Класс квадратов 

class Square
{
private:
    double a_length;

public:
    Square() {}
    Square(double a);
    ~Square();

    double Perimeter()
    {
        return a_length * 4;
    }

    double Area()
    {
        return a_length * a_length;
    }

    void Info()
    {
        cout.precision(3);
        cout << "TYPE : Square" << endl;
        cout << "Length:" << endl;
        cout << fixed << "A: " << a_length << endl;

        cout << endl
             << "Perimeter: " << Perimeter() << endl
             << "Area: " << Area() << endl
             << endl;
    }
};

Square::Square(double a)
{
   this->a_length = a;
}

Square::~Square()
{
}


int main()
{
    const int N = 2;

    Triangle triangles[N];
    Square sqares[N];

    for (int i = 0; i < N; i++)
    {
        triangles[i] = Triangle((1 + (double)rand() / RAND_MAX) * 10, (1 + (double)rand() / RAND_MAX) * 10, (1 + (double)rand() / RAND_MAX) * 10);
        sqares[i] = Square((1 + (double)rand() / RAND_MAX) * 10);

        triangles[i].Info();
        sqares[i].Info();
    }
}