#include <iostream> 
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const int N = 3;
    double x1 = 0, x2 = 0, x3 = 0;
    double matrix[N][N + 1] = {
        {-2, 1, 1, 0},
        {2, -1, 4, 15},
        {3, -1, 1, 8}
    };
    // приведение матрицы к ступенчатому виду
    for (int i = 0; i < N; i++) {

        if (abs(matrix[i][i]) < 1e-9) {
            for (int k = i + 1; k < N; k++) {
                if (abs(matrix[k][i]) > 1e-9) {
                    // Меняем строки местами
                    for (int j = 0; j <= N; j++) {
                        swap(matrix[i][j], matrix[k][j]);
                    }
                    break;
                }
            }
        }

        double diagElement = matrix[i][i]; // Элемент на диагонали текущей строки
        for (int j = i; j <= N; j++) {
            // Нормализуем строку, деля её на диагональный элемент
            matrix[i][j] /= diagElement;
        }

        // Устранение текущей переменной из нижних строк
        for (int k = i + 1; k < N; k++) { // Перебираем строки ниже текущей
            double factor = matrix[k][i]; // для обнуления текущей переменной в нижних строках)
            for (int j = i; j <= N; j++) { // Вычитаем строку из нижних строк, чтобы обнулить текущую переменную
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    
    x3 = matrix[2][3] / matrix[2][2];
    x2 = (matrix[1][3] - matrix[1][2] * x3) / matrix[1][1];
    x1 = (matrix[0][3] - matrix[0][2] * x3 - matrix[0][1] * x2) / matrix[0][0];
    cout << "Решения: " << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    return 0;
}
