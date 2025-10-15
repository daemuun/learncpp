#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Tour {
    Tour(std::string country, int days, std::string type, double price)
        : country{country}, days{days}, type{type}, price{price} {}
    std::string country;
    int days;
    std::string type;
    double price;
};

std::vector<Tour> find_tours_by_country(std::vector<Tour> tours, std::string country) {
    std::vector<Tour> finded_tours{};

    for (const auto& tour : tours) {
        if (tour.country == country) {
            finded_tours.push_back(tour);
        }
    }

    return finded_tours;
}

void file_preparation(std::string file_path = "files/test2.txt") {
    std::ifstream in(file_path);
    if (in.is_open()) {
        in.seekg(0, std::ios::end);
        if (in.tellg() != 0) {
            in.close();
            return;
        }
        in.close();
    }

    std::vector<Tour> tours{
        Tour{"Turkey", 10, "relax", 60000},        Tour{"Egypt", 12, "relax", 75000},
        Tour{"Turkey", 7, "excursion", 45000},     Tour{"Italy", 9, "gastronomic", 180000},
        Tour{"Greece", 14, "relax", 80000},        Tour{"Thailand", 15, "relax", 90000},
        Tour{"Turkey", 14, "treatment", 120000},   Tour{"Spain", 7, "excursion", 110000},
        Tour{"Italy", 5, "shopping", 95000},       Tour{"France", 10, "excursion", 200000},
        Tour{"Egypt", 8, "excursion", 65000},      Tour{"Thailand", 10, "treatment", 150000},
        Tour{"Greece", 6, "gastronomic", 70000},   Tour{"Spain", 12, "relax", 130000},
        Tour{"France", 14, "gastronomic", 280000}, Tour{"Turkey", 5, "shopping", 40000},
        Tour{"Italy", 7, "excursion", 120000},     Tour{"Egypt", 10, "treatment", 110000},
    };

    std::ofstream out(file_path);
    if (out.is_open()) {
        for (const auto& tour : tours) {
            out << tour.country << " " << tour.days << " " << tour.type << " " << tour.price
                << std::endl;
        }
    }
    out.close();
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF8");
    file_preparation();
    std::vector<Tour> tours;
    std::ifstream in("files/test2.txt");
    if (in.is_open()) {
        std::string country;
        int days;
        std::string type;
        double price;
        while (in >> country >> days >> type >> price) {
            tours.push_back(Tour{country, days, type, price});
        }
    }
    in.close();
    std::cout << "Вводите названия стран, чтоб найти туры в эти страны" << std::endl
              << "Выйти из программы можно написав <Выйти> или <Close>" << std::endl
              << "PS Названия стран пишутся, начиная верхним регистром и на английском" << std::endl
              << std::endl;

    while (true) {
        std::string input;
        std::cout << ">> ";
        std::cin >> input;

        if (input == "выйти" || input == "close" || input == "Выйти" || input == "Close") {
            return 0;
        } else {
            auto finded_tours = find_tours_by_country(tours, input);

            if (finded_tours.size() == 0) {
                std::cout << "К сожадению, туры в страну " << input
                          << " отсутствуют или данная страна не существует" << std::endl;
                continue;
            }

            std::cout << "Горящие туры в " << input << " :" << std::endl;

            for (int i = 0; i < finded_tours.size(); i++) {
                std::cout << i + 1 << ". " << "дней: " << finded_tours[i].days
                          << ", тип отдыха: " << finded_tours[i].type
                          << ", цена: " << finded_tours[i].price << "Р" << std::endl
                          << std::endl;
            }
        }
    }

    return 0;
}
