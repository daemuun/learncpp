#include <math.h>

#include <iostream>
#include <numbers>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF8");

    int a, b;
    double h;

    std::cout << "Введите нижнюю границу интервала: ";
    std::cin >> a;

    std::cout << "Введите верхнюю границу интервала: ";
    std::cin >> b;

    std::cout << "Введите шаг: ";
    std::cin >> h;
    
    if (b < a) {
        std::cout << "Верхняя граница интервала не может быть меньше нижней";
        return -1;
    }

    if (h <= 0) {
        std::cout << "Шаг не может быть отрицательным или равен 0";
        return -1;
    }

    double sum_pos_num{};
    for (double x = a; x <= b; x += h) {
        double f = 5 * (1 - std::exp(-0.5 * x)) * cos(2 * std::numbers::pi * x);

        if (f > 0) {
            sum_pos_num += f;
        }
        std::cout << "f(" << x << ") = " << f << std::endl;
    }

    std::cout << "Сумма положительных элементов: " << sum_pos_num;
    return 0;
}
