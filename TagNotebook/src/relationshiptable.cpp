#include "relationshiptable.hpp"
#include <algorithm>

RelationshipTable::RelationshipTable()
{

}

bool RelationshipTable::addRelation(int idCategory, int idNote)
{
    if(findById(idCategory) == std::end(relationshipTable_))
    {
        relationshipTable_.push_back(std::make_pair(idCategory, std::vector<int>(1,idNote)));
        return true;
    }
    else
    {
        findById(idCategory)->second.push_back(idNote);
        return true;
    }
    return false;
}

std::vector<std::pair<int, std::vector<int>>>::iterator RelationshipTable::findById(int id)
{
    return std::find_if(std::begin(relationshipTable_), std::end(relationshipTable_),
                        [&id](const std::pair<int, std::vector<int>>& element)
                            {
                                return element.first == id;
                            }
            );
}
