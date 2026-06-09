#pragma once
#include <string>
#include <map>
#include <vector>

std::string cleanWord(const std::string& word);
std::map<std::string, int> countWordFrequency(const std::string& text);
std::map<std::string, int> filterRepeatedWords(const std::map<std::string, int>& frequencyMap);
