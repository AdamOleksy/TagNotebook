#pragma once
#include <vector>

class RelationshipTable
{
    std::vector<std::pair<int, std::vector<int>>> relationshipTable_;
public:
    RelationshipTable();
    bool addRelation(int idCategory, int idNote);
    std::vector<std::pair<int, std::vector<int>>>::iterator findById(int id);
};
