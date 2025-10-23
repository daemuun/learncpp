#include <iostream>
#include <limits>

int input_int(const std::string& message) {
    int value{};
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();  // сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищаем буфер
            std::cout << "Ошибка! Пожалуйста, введите целое число." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищаем буфер
            if (value <= 0) {
                std::cout << "Ошибка! Число должно быть положительным." << std::endl;
            } else {
                return value;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF8");

    int ROWS = input_int("Введите количество строк: ");
    int COLS = input_int("Введите количество столбцов: ");

    std::cout << std::endl;
    std::cout << std::endl;

    int length = ROWS * COLS;
    int* arr = new int[length];
    for (int i = 0; i < length; i++) {
        std::cout << "Введите элемент номер " << i << ": ";
        std::cin >> arr[i];
    }
    std::cout << std::endl;

    // динамически создаем двумерный массив
    int** matrix = new int*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = new int[COLS];
    }

    // преобразуем одномерный массив в матрицу
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = arr[i * COLS + j];
        }
    }

    for (int i = 0; i < length; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "matrix" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int min_value = matrix[0][0];
    int min_value_row = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
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
    for (int i = 0; i < ROWS; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
