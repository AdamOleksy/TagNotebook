#include "category.hpp"

Category::Category(std::string categoryName) :
    categoryName_(categoryName)
{

}

std::string Category::getName() const
{
    return categoryName_;
}
