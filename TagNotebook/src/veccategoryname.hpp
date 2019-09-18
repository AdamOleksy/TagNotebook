#pragma once
#include "category.hpp"
#include <vector>


class VecCategoryName
{
    std::vector<std::pair<int, Category>> vecCategoryName_;
public:
    VecCategoryName();
    bool addCategory(std::pair<int, Category> pairIdCategory);
    std::vector<std::pair<int, Category>>::iterator findByName(std::string categoryName);
    std::vector<std::pair<int, Category>>::iterator findById(int id);
};


