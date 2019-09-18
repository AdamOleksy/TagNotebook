#pragma once
#include <string>


class Category
{
    std::string categoryName_;
public:
    Category(std::string categoryName);
    std::string getName() const;
};

