#include <iostream>
#include <random>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF8");

    int n, m;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;

    std::cout << std::endl;
    std::cout << std::endl;

    int length = n * m;
    int* arr = new int[length];
    for (int i = 0; i < length; i++) {
        std::cout << "Введите элемент номер " << i << ": ";
        std::cin >> arr[i];
    }
    std::cout << std::endl;

    // динамически создаем двумерный массив
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    // преобразуем одномерный массив в матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = arr[i * m + j];
        }
    }

    for (int i = 0; i < length; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "matrix" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int min_value = matrix[0][0];
    int min_value_row = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
                min_value_row = i;
            }
        }
    }

    std::cout << "Минимальное значение на строке с индексом " << min_value_row << " = " << min_value
              << std::endl;

    // высвобождаем память
    delete[] arr;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
