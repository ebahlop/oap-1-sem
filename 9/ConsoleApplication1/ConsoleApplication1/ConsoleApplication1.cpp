#include <iostream>
#include <cmath>

using namespace std;

// Подынтегральная функция
double f(double x) {
    return log(x);
}

// Метод средних прямоугольников
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * h;  // Вычисляем середину отрезка
        sum += f(x_mid);                   // Суммируем значения функции
    }

    return sum * h;  // Умножаем сумму на шаг
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 1.0;    // Нижний предел
    double b = exp(1);   // Верхний предел
    int n = 100;       // Количество разбиений

    double result = rectangle_method(a, b, n);

    cout << "Интеграл ln(x)dx от " << a << " до " << b << endl;
    cout << "(n = " << n << "): " << result << endl;

    return 0;
}
