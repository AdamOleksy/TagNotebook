#include "vecnoteslist.hpp"
#include <algorithm>

VecNotesList::VecNotesList()
{}

bool VecNotesList::addToList(std::pair<int, SingleNote> pairIdNote)
{

    if(std::end(vecNoteList_) == findById(pairIdNote.first))
    {
        vecNoteList_.push_back(pairIdNote);
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<std::pair<int, SingleNote>>::iterator VecNotesList::findById(int id)
{
    return std::find_if(std::begin(vecNoteList_), std::end(vecNoteList_),
                        [&id](const std::pair<int, SingleNote>& element)
                            {
                                return element.first == id;
                            }
            );
}

auto VecNotesList::getList()
{
    return &vecNoteList_;
}

bool VecNotesList::deleteNoteById(int id)
{
    auto iterator = findById(id);
    if(iterator == std::end(vecNoteList_))
    {
        return false;
    }
    else
    {
        vecNoteList_.erase(iterator);
        return true;
    }
}

void VecNotesList::printAllNotes()
{
    for(auto& a : vecNoteList_)
    {
        std::cout << "Number " <<a.first << "\n";
        a.second.printNote();
    }
}

int VecNotesList::getVecSize()
{
    return vecNoteList_.size();
}
