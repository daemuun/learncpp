#include <iostream>

int **create_matrix(int rows, int cols) {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void write_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}

void delete_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void print_matrix(int **matrix, int rows, int cols) {
    std::cout << "matrix" << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int find_max_col(int **matrix, int rows, int cols) {
    int max_value = matrix[0][0];
    int max_col = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
                max_col = j;
            }
        }
    }

    return max_col;
}

int **remove_col(int **matrix, int rows, int &cols, int col_to_remove) {
    int **new_matrix = new int *[rows];

    for (int i = 0; i < rows; i++) {
        new_matrix[i] = new int[cols - 1];
        int new_col = 0;
        for (int j = 0; j < cols; j++) {
            if (j != col_to_remove) {
                new_matrix[i][new_col] = matrix[i][j];
                new_col++;
            }
        }
    }

    delete_matrix(matrix, rows);
    cols--;

    return new_matrix;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF8");
    int ROWS;
    int COLS;

    std::cout << "Введите количество строк: ";
    std::cin >> ROWS;
    std::cout << "Введите количество столбцов: ";
    std::cin >> COLS;

    int **matrix = create_matrix(ROWS, COLS);
    write_matrix(matrix, ROWS, COLS);
    print_matrix(matrix, ROWS, COLS);

    int col_to_remove = find_max_col(matrix, ROWS, COLS);
    matrix = remove_col(matrix, ROWS, COLS, col_to_remove);

    print_matrix(matrix, ROWS, COLS);
    delete_matrix(matrix, ROWS);
    return 0;
}
