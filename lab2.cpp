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

// Структура для представления компрессорной станции (КС)
struct КомпрессорнаяСтанция {
    int id;                 // Уникальный идентификатор станции
    std::string название;
    int общееКолВоЦехов;
    int активныеЦеха;
    double эффективность;

    // Ввод данных о КС с проверками
    void ввод(int уникальныйId) {
        id = уникальныйId;
        std::cout << "Введите название станции: ";
        std::cin.ignore();
        std::getline(std::cin, название);

        std::cout << "Введите общее количество цехов: ";
        while (!(std::cin >> общееКолВоЦехов) || общееКолВоЦехов < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Целые значения вводятся без запятой." << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Количество не может быть отрицательным." << std::endl;
            }
            std::cout << "Введите общее количество цехов: ";
        }

        std::cout << "Введите количество активных цехов: ";
        while (!(std::cin >> активныеЦеха) || активныеЦеха > общееКолВоЦехов || активныеЦеха < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Целые значения вводятся без запятой." << std::endl;
            } else {
                std::cout << "Активные цеха не могут превышать общее количество или быть меньше 0." << std::endl;
            }
            std::cout << "Введите количество активных цехов: ";
        }

        std::cout << "Введите эффективность станции: ";
        while (!(std::cin >> эффективность) || эффективность < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Эффективность не может быть отрицательной." << std::endl;
            }
            std::cout << "Введите эффективность станции: ";
        }
    }

    // Вывод данных о КС
    void вывод() const {
        std::cout << "ID станции: " << id << std::endl;
        std::cout << "Название станции: " << название << std::endl;
        std::cout << "Общее количество цехов: " << общееКолВоЦехов << std::endl;
        std::cout << "Активные цеха: " << активныеЦеха << std::endl;
        std::cout << "Эффективность: " << эффективность << std::endl;
    }

    // Запуск цеха
    void запуститьЦех() {
        if (активныеЦеха < общееКолВоЦехов) {
            активныеЦеха++;
            std::cout << "Цех запущен. Активные цеха: " << активныеЦеха << std::endl;
        } else {
            std::cout << "Все цеха уже активны." << std::endl;
        }
    }

    // Остановка цеха
    void остановитьЦех() {
        if (активныеЦеха > 0) {
            активныеЦеха--;
            std::cout << "Цех остановлен. Активные цеха: " << активныеЦеха << std::endl;
        } else {
            std::cout << "Нет активных цехов для остановки." << std::endl;
        }
    }

    // Процент незадействованных цехов
    double процентНезадействованныхЦехов() const {
        if (общееКолВоЦехов == 0) return 0;
        return ((общееКолВоЦехов - активныеЦеха) / (double)общееКолВоЦехов) * 100;
    }
};
// Функция для логирования действий
void логировать(const std::string &действие) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (!logFile) {
        std::cerr << "Не удалось открыть файл для логирования!" << std::endl;
        return;
    }
    // Получаем текущее время
    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << dt << " - " << действие << std::endl;
}

// Функция для сохранения данных в файл
void сохранитьВФайл(Труба трубы[], int колТруб, КомпрессорнаяСтанция станции[], int колСтанций, const std::string &файл) {
    std::ofstream файлСохранения(файл);
    if (!файлСохранения.is_open()) {
        std::cerr << "Ошибка открытия файла для сохранения!" << std::endl;
        return;
    }

    файлСохранения << колТруб << std::endl;
    for (int i = 0; i < колТруб; i++) {
        файлСохранения << трубы[i].id << std::endl
                       << трубы[i].название << std::endl
                       << трубы[i].длина << std::endl
                       << трубы[i].диаметр << std::endl
                       << трубы[i].вРемонте << std::endl;
    }

    файлСохранения << колСтанций << std::endl;
    for (int i = 0; i < колСтанций; i++) {
        файлСохранения << станции[i].id << std::endl
                       << станции[i].название << std::endl
                       << станции[i].общееКолВоЦехов << std::endl
                       << станции[i].активныеЦеха << std::endl
                       << станции[i].эффективность << std::endl;
    }

    файлСохранения.close();
    std::cout << "Данные успешно сохранены." << std::endl;
    логировать("Данные сохранены в файл.");
}

// Функция для загрузки данных из файла
void загрузитьИзФайла(Труба трубы[], int &колТруб, КомпрессорнаяСтанция станции[], int &колСтанций, const std::string &файл) {
    std::ifstream файлЗагрузки(файл);
    if (!файлЗагрузки.is_open()) {
        std::cerr << "Ошибка открытия файла для загрузки!" << std::endl;
        return;
    }

    файлЗагрузки >> колТруб;
    файлЗагрузки.ignore();  // Для игнорирования символа новой строки
    for (int i = 0; i < колТруб; i++) {
        файлЗагрузки >> трубы[i].id;
        файлЗагрузки.ignore();
        std::getline(файлЗагрузки, трубы[i].название);
        файлЗагрузки >> трубы[i].длина >> трубы[i].диаметр >> трубы[i].вРемонте;
        файлЗагрузки.ignore();
    }

    файлЗагрузки >> колСтанций;
    файлЗагрузки.ignore();
    for (int i = 0; i < колСтанций; i++) {
        файлЗагрузки >> станции[i].id;
        файлЗагрузки.ignore();
        std::getline(файлЗагрузки, станции[i].название);
        файлЗагрузки >> станции[i].общееКолВоЦехов >> станции[i].активныеЦеха >> станции[i].эффективность;
        файлЗагрузки.ignore();
    }

    файлЗагрузки.close();
    std::cout << "Данные успешно загружены." << std::endl;
    логировать("Данные загружены из файла.");
}

// Функция для поиска труб по названию или статусу "в ремонте"
void поискТруб(Труба трубы[], int колТруб) {
    std::cout << "Поиск труб:\n";
    std::cout << "1. Поиск по названию\n";
    std::cout << "2. Поиск по статусу 'в ремонте'\n";
    int выбор;
    std::cin >> выбор;

    if (выбор == 1) {
        std::cin.ignore(); // Сброс буфера
        std::string название;
        std::cout << "Введите название трубы для поиска: ";
        std::getline(std::cin, название);

        for (int i = 0; i < колТруб; i++) {
            if (трубы[i].название == название) {
                трубы[i].вывод();
                return;
            }
        }
        std::cout << "Труба с таким названием не найдена.\n";
    } else if (выбор == 2) {
        bool статус;
        std::cout << "Введите статус (1 - в ремонте, 0 - не в ремонте): ";
        std::cin >> статус;

        for (int i = 0; i < колТруб; i++) {
            if (трубы[i].вРемонте == статус) {
                трубы[i].вывод();
            }
        }
    }
}

// Функция для поиска КС по названию или проценту незадействованных цехов
void поискКС(КомпрессорнаяСтанция станции[], int колСтанций) {
    std::cout << "Поиск КС:\n";
    std::cout << "1. Поиск по названию\n";
    std::cout << "2. Поиск по проценту незадействованных цехов\n";
    int выбор;
    std::cin >> выбор;

    if (выбор == 1) {
        std::cin.ignore(); // Сброс буфера
        std::string название;
        std::cout << "Введите название станции для поиска: ";
        std::getline(std::cin, название);

        for (int i = 0; i < колСтанций; i++) {
            if (станции[i].название == название) {
                станции[i].вывод();
                return;
            }
        }
        std::cout << "Компрессорная станция с таким названием не найдена.\n";
    } else if (выбор == 2) {
        double процент;
        std::cout << "Введите максимальный процент незадействованных цехов: ";
        std::cin >> процент;

        for (int i = 0; i < колСтанций; i++) {
            if (станции[i].процентНезадействованныхЦехов() <= процент) {
                станции[i].вывод();
            }
        }
    }
}


int main() {
    Труба трубы[MAX_ТРУБ];
    КомпрессорнаяСтанция станции[MAX_СТАНЦИЙ];
    int колТруб = 0, колСтанций = 0;
    int выбор;
    int id_трубы = 1, id_станции = 1;  // Начальные уникальные ID

    while (true) {
        std::cout << "1. Добавить трубу" << std::endl;
        std::cout << "2. Добавить компрессорную станцию" << std::endl;
        std::cout << "3. Просмотреть все объекты" << std::endl;
        std::cout << "4. Изменить статус ремонта трубы" << std::endl;
        std::cout << "5. Запустить/остановить цех" << std::endl;
        std::cout << "6. Поиск объектов" << std::endl;
        std::cout << "7. Сохранить" << std::endl;
        std::cout << "8. Загрузить" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> выбор;

        if (выбор == 0) {
            break;
        }

        std::string файл;
        switch (выбор) {
            case 1: {  // Добавить трубу
                трубы[колТруб].ввод(id_трубы++);
                колТруб++;
                break;
            }
            case 2: {  // Добавить компрессорную станцию
                станции[колСтанций].ввод(id_станции++);
                колСтанций++;
                break;
            }
            case 3: {  // Просмотреть все объекты
                for (int i = 0; i < колТруб; i++) {
                    трубы[i].вывод();
                    std::cout << "----------------------" << std::endl;
                }
                for (int i = 0; i < колСтанций; i++) {
                    станции[i].вывод();
                    std::cout << "----------------------" << std::endl;
                }
                break;
            }
            case 6: {  // Поиск объектов
                std::cout << "Выберите тип объекта для поиска:" << std::endl;
                std::cout << "1. Поиск труб" << std::endl;
                std::cout << "2. Поиск компрессорных станций" << std::endl;
                int поиск;
                std::cin >> поиск;
                if (поиск == 1) {
                    поискТруб(трубы, колТруб);
                } else if (поиск == 2) {
                    поискКС(станции, колСтанций);
                }
                break;
            }
            case 7: {  // Сохранить
                std::cout << "Введите имя файла для сохранения: ";
                std::cin >> файл;
                сохранитьВФайл(трубы, колТруб, станции, колСтанций, файл);
                break;
            }
            case 8: {  // Загрузить
                std::cout << "Введите имя файла для загрузки: ";
                std::cin >> файл;
                загрузитьИзФайла(трубы, колТруб, станции, колСтанций, файл);
                break;
            }
            default:
                std::cerr << "Неверная опция. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}