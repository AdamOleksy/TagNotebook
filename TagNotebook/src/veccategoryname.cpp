#include "veccategoryname.hpp"
#include <algorithm>

VecCategoryName::VecCategoryName()
{

}

std::vector<std::pair<int, Category>>::iterator VecCategoryName::findByName(std::string categoryName)
{
    return std::find_if(std::begin(vecCategoryName_), std::end(vecCategoryName_),
                        [&categoryName](const std::pair<int, Category>& element)
                            {
                                return element.second.getName() == categoryName;
                            }
            );
}

std::vector<std::pair<int, Category>>::iterator VecCategoryName::findById(int id)
{
    return std::find_if(std::begin(vecCategoryName_), std::end(vecCategoryName_),
                        [&id](const std::pair<int, Category>& element)
                            {
                                return element.first == id;
                            }
            );
}

bool VecCategoryName::addCategory(std::pair<int, Category> pairIdCategory)
{
    if(std::end(vecCategoryName_) == findById(pairIdCategory.first)
            && std::end(vecCategoryName_) == findByName(pairIdCategory.second.getName()))
    {
        vecCategoryName_.push_back(pairIdCategory);
        return true;
    }
    else
    {
        return false;
    }
}

