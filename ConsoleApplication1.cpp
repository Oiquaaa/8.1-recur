#include <iostream>
#include <string>

std::string replaceOGOorAGA(const std::string& str) {
    if (str.size() < 3) {
        // Якщо рядок містить менше трьох символів, то повертаємо його без змін
        return str;
    }
    // Перевіряємо, чи містить поточний рядок трійку символів "OGO" або "AGA"
    if (str[0] == 'O' && str[1] == 'G' && str[2] == 'O' ||
        str[0] == 'A' && str[1] == 'G' && str[2] == 'A') {
        // Якщо містить, то замінюємо її на "" та продовжуємо рекурсію з наступної трійки символів
        return "**" + replaceOGOorAGA(str.substr(3));
    }
    else {
        // Якщо не містить, то додаємо перший символ до результату та продовжуємо рекурсію з наступних двох символів
        return str[0] + replaceOGOorAGA(str.substr(1));
    }
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;
    std::cout << "Result: " << replaceOGOorAGA(str) << std::endl;
    return 0;
}
