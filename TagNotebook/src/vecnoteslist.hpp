#pragma once
#include <vector>
#include <iterator>
#include <iostream>
#include "singlenote.hpp"

class VecNotesList
{
    std::vector<std::pair<int, SingleNote>> vecNoteList_;
public:
    VecNotesList();
    bool addToList(std::pair<int, SingleNote> pairIdNote);
    std::vector<std::pair<int, SingleNote>>::iterator findById(int id);
    auto getList();
    bool deleteNoteById(int id);
    void printAllNotes();
    int getVecSize();

};

