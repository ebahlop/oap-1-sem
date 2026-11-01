#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double a = 1.33 * pow(10, -3), k = 6, x[4] = { 0.2, 1, -3, -6.1 };
    double d, b;
    for (int i = 0; i < 4; i++)
    {
        if (x[i] <= 0 || x[i] == 1)
        {
            cout << "Нет решения" << endl;
        }
        else
        {
            d = exp(-1 * x[i]) + (x[i] - 1) / log(x[i]);
            if (d >= k * sqrt(a))
            {
                b = 6 * d * x[i];
            }
            else
            {
                b = sin(a / x[i]);
            }
            cout << b << endl;
        }
    }
    return 0;
}