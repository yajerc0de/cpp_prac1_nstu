// Задание: программа получает на вход ассоциативный контейнер (std::set)
// и выводит минимальное и максимальное число из него.
#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main() {
    std::set<int> numbers;

    std::cout << "Введите числа по одному в строке.\n";
    std::cout << "Пустая строка или 'end' завершает ввод.\n";

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty() || line == "end") {
            break;
        }
        std::istringstream iss(line);
        int value;
        if (iss >> value) {
            numbers.insert(value);
        } else {
            std::cerr << "Некорректный ввод, пропущено: " << line << '\n';
        }
    }

    if (numbers.empty()) {
        std::cerr << "Контейнер пуст: минимум и максимум не определены.\n";
        return 1;
    }

    // std::set хранит элементы в отсортированном порядке (красно-чёрное дерево),
    // поэтому минимум — это первый элемент, максимум — последний.
    // Оба значения получаются за O(1), без обхода всего контейнера.
    int minValue = *numbers.begin();
    int maxValue = *numbers.rbegin();

    std::cout << "Минимум: " << minValue << '\n';
    std::cout << "Максимум: " << maxValue << '\n';

    return 0;
}
