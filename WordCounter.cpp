#include "WordCounter.h"
#include <sstream>
#include <algorithm>
#include <cctype>

std::string cleanWord(const std::string& word) {
    std::string cleaned = "";
    for (char ch : word) {
        if (!std::ispunct(static_cast<unsigned char>(ch))) {
            cleaned += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        }
    }
    return cleaned;
}

std::map<std::string, int> countWordFrequency(const std::string& text) {
    std::map<std::string, int> frequencyMap;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            frequencyMap[cleaned]++;
        }
    }
    return frequencyMap;
}

std::map<std::string, int> filterRepeatedWords(const std::map<std::string, int>& frequencyMap) {
    std::map<std::string, int> filteredMap;
    for (const auto& pair : frequencyMap) {
        if (pair.second > 1) {
            filteredMap.insert(pair);
        }
    }
    return filteredMap;
}
