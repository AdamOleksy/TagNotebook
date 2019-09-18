#include "converter.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

Converter::Converter()
{

}

std::string Converter::convertNoteToString(std::pair<int, SingleNote> pair)
{
    std::stringstream str;
    str << "{[" << pair.first << "]};{["
        << pair.second.getTitle() << "]};{["
        << pair.second.getContent() << "]};";
    std::string dbEntry = str.str();
    return dbEntry;
}

std::pair<int, SingleNote> Converter::convertStringToNote(std::string str)
{
    size_t posBegin, posEnd;
    posBegin = str.find_first_of("{[") + 2;
    posEnd = str.find_first_of("]};");
    int number = std::atoi(str.substr(posBegin, (posEnd-posBegin)).c_str());

    posBegin = str.find_first_of("{[",posEnd) + 2;
    posEnd = str.find_first_of("]};",posBegin);
    std::string title(str.substr(posBegin, (posEnd-posBegin)));

    posBegin = str.find_first_of("{[",posEnd) + 2;
    posEnd = str.find_first_of("]};",posBegin);
    std::string note(str.substr(posBegin, (posEnd-posBegin)));

    return std::make_pair(number, SingleNote(title, note));
}

std::string Converter::convertCategoryToString(std::pair<int, Category> pair)
{
    std::stringstream str;
    str << "{[" << pair.first << "]};{["
        << pair.second.getName() << "]};";
    std::string dbEntry = str.str();
    return dbEntry;
}

std::pair<int, Category> Converter::convertStringToCategory(std::string str)
{
    size_t posBegin, posEnd;
    posBegin = str.find_first_of("{[") + 2;
    posEnd = str.find_first_of("]};");
    int number = std::atoi(str.substr(posBegin, (posEnd-posBegin)).c_str());

    posBegin = str.find_first_of("{[",posEnd) + 2;
    posEnd = str.find_first_of("]};",posBegin);
    std::string title(str.substr(posBegin, (posEnd-posBegin)));

    return std::make_pair(number, Category(title));
}
