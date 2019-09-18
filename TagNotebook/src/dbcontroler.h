#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "singlenote.hpp"
#include "converter.hpp"
#include "category.hpp"

class DBControler
{
    std::string notesFileName_;
    std::string categoryFileName_;
public:
    DBControler(std::string notesFileName, std::string categoryFileName);

    bool createNewNoteFile();
    bool createNewCategoryFile();
    std::vector<std::string> pullDataFromFileNotes();
    std::vector<std::string> pullDataFromFileCategory();
    bool addNoteToFile(int number, SingleNote sn);
    bool addCategoryToFile(int number, Category cat);

};
