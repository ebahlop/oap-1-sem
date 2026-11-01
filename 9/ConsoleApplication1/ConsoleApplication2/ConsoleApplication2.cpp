#include <iostream>
#include <cmath>

using namespace std;

// Подынтегральная функция: f(x) = ln(x)
double f(double x) {
    return log(x);
}

// Метод трапеций
double trapezoidal_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0; // Учет концевых точек

    // Суммирование значений в промежуточных точках
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    return sum * h;
}

int main() {
    setlocale(LC_ALL, "RU");

    double a = 1.0;       // Нижний предел
    double b = exp(1.0);  // Верхний предел
    int n = 100;

    double result = trapezoidal_method(a, b, n);

    cout << "Интеграл ln(x)dx от " << a << " до " << b << endl;
    cout << "(n = " << n << "): " << result << endl;

    return 0;
}