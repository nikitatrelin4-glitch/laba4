#pragma once
#include "WordCounter.h"
#include <cassert>
#include <iostream>

inline void runTests() {
    std::string text1 = "cat dog cat bird dog cat";
    auto res1 = countWordFrequency(text1);
    assert(res1["cat"] == 3);
    assert(res1["dog"] == 2);
    assert(res1["bird"] == 1);

    auto filteredRes1 = filterRepeatedWords(res1);
    assert(filteredRes1.count("cat") == 1);
    assert(filteredRes1.count("dog") == 1);
    assert(filteredRes1.count("bird") == 0);

    std::string text2 = "Cat, dog! CAT... bird?";
    auto res2 = countWordFrequency(text2);
    assert(res2["cat"] == 2);
    assert(res2["dog"] == 1);

    std::cout << "[SUCCESS] Все тесты успешно пройдены!\n\n";
}
