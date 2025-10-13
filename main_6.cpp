#include <fstream>
#include <iostream>
#include <string>

int main() {
    int count;
    std::cout << "Enter numbers count: ";
    std::cin >> count;

    std::ofstream out;
    out.open("files/test1.txt");
    if (out.is_open()) {
        for (int i = 0; i < count; i++) {
            double temp;
            std::cout << "Enter " << i + 1 << " number: ";
            std::cin >> temp;
            out << temp << std::endl;
        }
    }
    out.close();

    double result{};

    std::string line;
    std::ifstream in("files/test1.txt");
    if (in.is_open()) {
        while (std::getline(in, line)) {
            result += std::stod(line);
        }
    }
    std::cout << "Numbers sum: " << result;
    return 0;
}
