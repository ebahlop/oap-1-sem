#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int age;
    cout << "Введите возраст: ";
    try
    {
        if (!(cin >> age)) {
            throw 1;
        }

        if (age < 18)
            throw 2;
        cout << "Доступ разрешен. Ваш возраст: " << age << endl;
    }
    catch (int e) {
        switch (e) {
        case 1: cout << "Ошибка: введено не число" << endl; break;
        case 2: cout << "Произошла ошибка: Недопустимый возраст!" << endl; break;
        }
        
    }
    catch (...) {
        cout << "error";
    }
    return 0;
}