
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
