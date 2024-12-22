#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <ctime>

const int MAX_ТРУБ = 100;  // Максимальное количество труб
const int MAX_СТАНЦИЙ = 100;  // Максимальное количество станций

// Структура для представления трубы
struct Труба {
    int id;                 // Уникальный идентификатор трубы
    std::string название;
    double длина;
    double диаметр;
    bool вРемонте;

    // Ввод данных о трубе с проверками
    void ввод(int уникальныйId) {
        id = уникальныйId;
        std::cout << "Введите название трубы: ";
        std::cin.ignore();
        std::getline(std::cin, название);

        std::cout << "Введите длину трубы: ";
        while (!(std::cin >> длина) || длина < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Длина не может быть отрицательной." << std::endl;
            }
            std::cout << "Введите длину трубы: ";
        }

        std::cout << "Введите диаметр трубы: ";
        while (!(std::cin >> диаметр) || диаметр < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Диаметр не может быть отрицательным." << std::endl;
            }
            std::cout << "Введите диаметр трубы: ";
        }

        std::cout << "Находится ли труба в ремонте? (1 - да, 0 - нет): ";
        std::cin >> вРемонте;
    }

    // Вывод данных о трубе
    void вывод() const {
        std::cout << "ID трубы: " << id << std::endl;
        std::cout << "Название трубы: " << название << std::endl;
        std::cout << "Длина: " << длина << " км" << std::endl;
        std::cout << "Диаметр: " << диаметр << " м" << std::endl;
        std::cout << "В ремонте: " << (вРемонте ? "Да" : "Нет") << std::endl;
    }

    // Редактирование признака "в ремонте"
    void изменитьСтатусРемонта() {
        std::cout << "Введите новый статус ремонта (1 - да, 0 - нет): ";
        std::cin >> вРемонте;
    }
};
