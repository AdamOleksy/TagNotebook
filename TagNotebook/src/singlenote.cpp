#include "singlenote.hpp"
#include <iostream>

SingleNote::SingleNote(std::string title, std::string content):
    title_(title), content_(content)
{}

std::string& SingleNote::getContent()
{
    return content_;
}

void SingleNote::setContent(std::string content)
{
    content_.clear();
    content_ = content;
}

std::string& SingleNote::getTitle()
{
    return title_;
}

void SingleNote::printNote()
{
    std::cout << title_ << ":\n" << content_ << std::endl;
}
