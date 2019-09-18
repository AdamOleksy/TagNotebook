#include "dbcontroler.h"

DBControler::DBControler(std::string notesFileName, std::string categoryFileName) :
    notesFileName_(notesFileName), categoryFileName_(categoryFileName)
{

}

std::vector<std::string> DBControler::pullDataFromFileNotes()
{
    std::vector<std::string> vec;
    std::string line;
    std::fstream file;

    file.open(notesFileName_, std::ios::in);
    if(!file.is_open())
    {
        createNewNoteFile();
        file.open(notesFileName_, std::ios::in);
    }

        while (!file.eof())
        {
            line.clear();
            getline(file, line);
            vec.push_back(line);
        }
    vec.pop_back();
    file.close();
    vec.shrink_to_fit();
    return vec;

}

bool DBControler::addNoteToFile(int number, SingleNote sn)
{
    Converter converter;
    std::ofstream file;
    file.open (notesFileName_, std::ios::app);
    file << converter.convertNoteToString(std::make_pair(number,sn)) << std::endl;
    file.close();
}

bool DBControler::createNewNoteFile()
{
    std::ofstream myfile;
    myfile.open (notesFileName_);
    myfile.close();
}

bool DBControler::createNewCategoryFile()
{
    std::ofstream myfile;
    myfile.open (categoryFileName_);
    myfile.close();
}

bool DBControler::addCategoryToFile(int number, Category cat)
{
    Converter converter;
    std::ofstream file;
    file.open (categoryFileName_, std::ios::app);
    file << converter.convertCategoryToString(std::make_pair(number,cat)) << std::endl;
    return true;
}

std::vector<std::string> DBControler::pullDataFromFileCategory()
{
    std::vector<std::string> vec;
    std::string line;
    std::fstream file;

    file.open(categoryFileName_ , std::ios::in);
    if(!file.is_open())
    {
        createNewNoteFile();
        file.open(categoryFileName_ , std::ios::in);
    }

    while (!file.eof())
    {
        line.clear();
        getline(file, line);
        vec.push_back(line);
    }

    vec.pop_back();
    file.close();
    vec.shrink_to_fit();
    return vec;
}
