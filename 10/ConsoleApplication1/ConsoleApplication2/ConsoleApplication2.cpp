#include <iostream>

// Функция для вычисления натурального логарифма (аппроксимация)
double customLog(double x) {
    if (x <= 0) return 0;

    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double term_squared = term * term;
    double current_term = term;

    // Ряд Тейлора для ln(x)
    for (int i = 0; i < 100; ++i) {
        result += current_term / (2 * i + 1);
        current_term *= term_squared;
        if (current_term < 1e-10) break; // Критерий остановки
    }

    return 2 * result;
}

// Функция для вычисления экспоненты (аппроксимация)
double customExp(double x) {
    double result = 1.0;
    double term = 1.0;

    // Ряд Тейлора для e^x
    for (int i = 1; i < 100; ++i) {
        term *= x / i;
        result += term;
        if (term < 1e-10) break; // Критерий остановки
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    const int n = 4;
    double x[n] = { 0, 1, 2, 3 };
    double y[n] = { 0.5, 1.5, 2.5, 3.5 };

    // Логарифмируем y используя нашу функцию
    double lnY[n];
    for (int i = 0; i < n; ++i) {
        lnY[i] = customLog(y[i]);
    }

    double sumX = 0, sumLnY = 0, sumXLnY = 0, sumX2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumLnY += lnY[i];
        sumXLnY += x[i] * lnY[i];
        sumX2 += x[i] * x[i];
    }

    // Находим коэффициенты для ln(y) = ln(a) + bx
    double b = (n * sumXLnY - sumX * sumLnY) / (n * sumX2 - sumX * sumX);
    double lnA = (sumLnY - b * sumX) / n;
    double a = customExp(lnA);

    std::cout << "Экспоненциальная аппроксимация: y = " << a << "e^(" << b << "x)" << std::endl;
    return 0;
}



