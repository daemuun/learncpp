#include <iostream>
#include <limits> 

int** create_matrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void write_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}

void delete_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void print_matrix(int** matrix, int rows, int cols) {
    std::cout << "matrix" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int find_max_row(int** matrix, int rows, int cols) {
    int max_value = matrix[0][0];
    int max_row = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
                max_row = i;
            }
        }
    }
    return max_row;
}

int** remove_row(int** matrix, int& rows, int cols, int row_to_remove) {
    int** new_matrix = new int*[rows - 1];
    int new_row = 0;

    for (int i = 0; i < rows; i++) {
        if (i != row_to_remove) {
            new_matrix[new_row] = new int[cols];
            for (int j = 0; j < cols; j++) {
                new_matrix[new_row][j] = matrix[i][j];
            }
            new_row++;
        }
    }

    delete_matrix(matrix, rows);
    rows--;

    return new_matrix;
}

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

    int** matrix = create_matrix(ROWS, COLS);
    write_matrix(matrix, ROWS, COLS);

    std::cout << "\nИсходная матрица:" << std::endl;
    print_matrix(matrix, ROWS, COLS);

    int row_to_remove = find_max_row(matrix, ROWS, COLS);
    std::cout << "\nУдаляем строку " << row_to_remove << " с максимальным элементом" << std::endl;

    matrix = remove_row(matrix, ROWS, COLS, row_to_remove);

    std::cout << "\nМатрица после удаления строки:" << std::endl;
    print_matrix(matrix, ROWS, COLS);

    delete_matrix(matrix, ROWS);
    return 0;
}
