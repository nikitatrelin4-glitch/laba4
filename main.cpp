#include <iostream>
#include "WordCounter.h"
#include "tests.h"

int main() {
    runTests();

    std::cout << "=== Лабораторная работа №4. Подсчёт слов ===\n";
    std::cout << "Введите текст для анализа (для окончания ввода нажмите Enter в пустой строке):\n";

    std::string rawText;
    std::string line;
    
    while (std::getline(std::cin, line) && !line.empty()) {
        rawText += line + " ";
    }

    if (rawText.empty()) {
        std::cout << "Текст не был введен.\n";
        return 0;
    }

    auto allWords = countWordFrequency(rawText);
    
    std::cout << "\n--- Полный список слов (слово -> количество): ---\n";
    for (const auto& pair : allWords) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }

    auto repeatedWords = filterRepeatedWords(allWords);

    std::cout << "\n--- Вариативная часть (встречаются больше одного раза): ---\n";
    if (repeatedWords.empty()) {
        std::cout << "[Нет слов, которые встретились больше одного раза]\n";
    } else {
        for (const auto& pair : repeatedWords) {
            std::cout << pair.first << " -> " << pair.second << "\n";
        }
    }

    return 0;
}
