#pragma once
#include "singlenote.hpp"
#include "category.hpp"

class Converter
{
public:
    Converter();
    std::string convertNoteToString(std::pair<int, SingleNote> pair);
    std::string convertCategoryToString(std::pair<int, Category> pair);
    std::pair<int, SingleNote> convertStringToNote(std::string str);
    std::pair<int, Category> convertStringToCategory(std::string str);
};

