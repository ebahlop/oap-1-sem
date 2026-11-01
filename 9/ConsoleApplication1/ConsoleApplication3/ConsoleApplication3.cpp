#include <iostream>
#include <cmath>

using namespace std;

// Подынтегральная функция
double f(double x) {
    return log(x);
}

// Метод парабол (Симпсона)
double simpson_method(double a, double b, int n) {
    if (n % 2 != 0) n++; // Делаем n четным, если передано нечетное

    double h = (b - a) / n;
    double sum = f(a) + f(b); // Учет концевых точек

    // Суммирование значений с коэффициентами 4 и 2
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 1) { // Нечетные точки (4)
            sum += 4 * f(x);
        }
        else { // Четные точки (2)
            sum += 2 * f(x);
        }
    }

    return sum * h / 3;
}

int main() {
    setlocale(LC_ALL, "RU");

    double a = 1.0;       // Нижний предел
    double b = exp(1.0);  // Верхний предел (число e ≈ 2.71828)
    int n = 100;         // Количество разбиений (должно быть четным)

    double result = simpson_method(a, b, n);

    cout << "Интеграл ln(x)dx от " << a << " до " << b << endl;
    cout << "Метод парабол (n = " << n << "): " << result << endl;

    return 0;
}