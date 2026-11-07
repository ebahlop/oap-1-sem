#include <iostream>
#include <cmath>
#include <iomanip>

double sinh_iterative(double x, double epsilon) {

    double term = x;
    double sum = term;
    int n = 1;
    while (fabs(term) >= epsilon) {
        term *= x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "ru");
    double x, eps;
    std::cout << "Введите x: ";
    std::cin >> x;
    std::cout << "Введите epsilon: ";
    std::cin >> eps;

    std::cout << std::setprecision(10) << "sinh(" << x << ") = " << sinh_iterative(x, eps) << std::endl << std::fixed;
    return 0;
}