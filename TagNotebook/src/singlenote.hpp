#pragma once
#include <string>

class SingleNote
{
    std::string title_;
    std::string content_;
public:
    SingleNote(std::string title, std::string content);
    std::string& getContent();
    void setContent(std::string content);
    std::string& getTitle();
    void printNote();
};
