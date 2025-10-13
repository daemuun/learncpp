#include <iostream>
#include <random>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF8");

    // подготавливаем условия для генерации рандомных значений
    std::random_device rd{};
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1000, 1000);

    int n{};
    std::cout << "Введите длину массива a[n]: ";
    std::cin >> n;

    // высвобождаем память для массива с размером n
    double *a = new double[n];

    // заполняем массив ранддомными значениями
    for (int i = 0; i < n; i++) {
        a[i] = dist(gen);
    }

    bool is_alternating = true;
    for (int i = 0; i < n - 1; i++) {
        if (!(a[i] < 0 && a[i + 1] > 0 || a[i] > 0 && a[i + 1] < 0)) {
            is_alternating = false;
            break;
        }
    }

    double result;
    if (is_alternating) {
        result = 0;
        std::cout << "Массив чередуется. Считаем сумму:" << std::endl;
    } else {
        result = 1;
        std::cout << "Массив не чередуется. Считаем произведение отрицательных:" << std::endl;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
        if (is_alternating) {
            result += a[i];
        } else if (a[i] < 0) {
            result *= a[i];
        }
    }

    std::cout << "результат: " << result;

    // освобождаем память массива
    delete[] a;
    return 0;
}
