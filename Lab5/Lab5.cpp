#include <iostream>
#include <cmath>
#include <math.h>
#include <ctime>

using namespace std;

double Perimeter_Triangle(double* arr_side);
double Area_Triangle(double* arr_side);
double Perimeter_Square(double* arr_side);
double Area_Square(double* arr_side);

// Класс Фигур

class Figure
{
private:
    int n_length;
    double* arr_length;
    double (*perimeter)(double*);
    double (*area)(double*);
    int figure_type;
public:

    Figure(int n_length, double* arr_length, double (*perimeter)(double*), double (*area)(double*), int figure_type)
    {
        this->n_length = n_length;
        this->arr_length= arr_length;
        this->perimeter = perimeter;
        this->area = area;  
        this->figure_type = figure_type;
    }

    ~Figure() {
        delete[] arr_length;
    }

    int getfigure_type(){
        return figure_type;
    }
    double func_area(){
        return area(arr_length);
    }

    double func_perimeter(){
        return perimeter(arr_length);
    }

};

// Класс треугольников 

class Triangle: public Figure
{
private:
    double* array_size;
public:
    Triangle(double* arr_lenght):
    Figure(3, arr_lenght, Perimeter_Triangle, Area_Triangle, 0),
    array_size(arr_lenght)
    {}

    ~Triangle()
    {
    }

    void Info()
    {
        cout.precision(3);
        cout << "TYPE : Triangle" << endl;
        cout << "Length:" << endl;
        cout << fixed << "A: " << array_size[0] << endl;
        cout << fixed << "B: " << array_size[1] << endl;
        cout << fixed << "C: " << array_size[2] << endl;
        cout
             << "Perimeter: " << func_perimeter() << endl
             << "Area: " << func_area() << endl
             << endl;
    }
};

// Класс квадратов 

class Square: public Figure
{
private:
    double* array_size;
public:
    Square(double* arr_lenght):
    Figure(1, arr_lenght, Perimeter_Square, Area_Square, 1),
    array_size(arr_lenght)
    {}

    ~Square()
    {
    }

    void Info()
    {
        cout.precision(3);
        cout << "TYPE : Square" << endl;
        cout << "Length:" << endl;
        cout << fixed << "A: " << array_size[0] << endl;
        cout 
             << "Perimeter: " << func_perimeter() << endl
             << "Area: " << func_area() << endl
             << endl;
    }
};

// Класс Тетрадь

class Notebook{
    private:
        Figure** my_figure;
        int N = 0;
    public:
        Notebook(int N){
            double* array_size;
            int rand_num;
            const double max_length = 10;
            this->N = N;
            my_figure = new Figure* [N];
            for (int i = 0; i < this->N; i++){
                rand_num = rand() % 2;
                if (rand_num == 1){
                    array_size = new double ((double)(rand())/RAND_MAX*(max_length) + 0.1);
                    my_figure[i] = new Square(array_size);
                }
                else {
                    array_size = new double[3];
                    array_size[0]=(double)(rand())/RAND_MAX*(max_length) + 0.1;
                    array_size[1]=array_size[0];
                    array_size[2]=array_size[1];
                    my_figure[i] = new Triangle(array_size);
                }
            }
        }

        void out_info (){
            double summ_perimeter = 0;
            double summ_area = 0;
            for (int i = 0; i < N; i++){
                if (my_figure[i]->getfigure_type() == 1 ) {
                    ((Square*) my_figure[i])->Info();
                    summ_perimeter += ((Square*) my_figure[i])->func_perimeter();
                    summ_area += ((Square*) my_figure[i])->func_area();
                }
                else {
                    ((Triangle*) my_figure[i])->Info();
                    summ_perimeter += ((Triangle*) my_figure[i])->func_perimeter();
                    summ_area += ((Triangle*) my_figure[i])->func_area();
                }
            }
            cout << "Сумма площадей = " << summ_area << endl;
            cout << "Сумма периметров = " << summ_perimeter << endl;
        }

        ~Notebook(){
            for (int i = 0; i < N; i++){
                delete my_figure[i];
            } 
            delete[] my_figure;
        }
};

int main()
{
   int N = 0;
    srand(time( 0 ));
    cout << "Введите число фигур: ";
    cin >> N;
    Notebook my_notebook(N);
    my_notebook.out_info();
    return 0;
}

// Функции расчета площади и периметра 

double Perimeter_Triangle(double* arr_side)
{
    double perimeter;
    for (int i = 0; i < 3; i++){
        perimeter += arr_side[i];
    }
    return perimeter;
}

double Area_Triangle(double* arr_side)
{
    double pol_perimetra = 0;
    pol_perimetra = (arr_side[0] + arr_side[1] + arr_side[2]) / 2;
    return (sqrt( pol_perimetra * (pol_perimetra - arr_side[0]) * (pol_perimetra - arr_side[1]) * (pol_perimetra - arr_side[2])));
}

double Perimeter_Square(double* arr_side)
{
    return arr_side[0] * 4;
}

double Area_Square(double* arr_side)
{
    return arr_side[0] * 4;
}