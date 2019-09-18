#include "gtest/gtest.h"
#include "../src/singlenote.hpp"
#include "../src/vecnoteslist.hpp"
#include "../src/category.hpp"
#include "../src/veccategoryname.hpp"
#include "../src/relationshiptable.hpp"
#include "../src/converter.hpp"
#include "../src/dbcontroler.h"

class SingleTests : public ::testing::Test
{
protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }
};

TEST_F(SingleTests, isAbleToCreateInstanceOfNote)
{
    SingleNote singleNote("Title", "Note");
    ASSERT_EQ("Note", singleNote.getContent());
}

TEST_F(SingleTests, isAbleToChangeNote)
{
    SingleNote singleNote("Title", "Note");
    singleNote.setContent("NewNote");
    ASSERT_EQ("NewNote", singleNote.getContent());
}

TEST_F(SingleTests, isAbleToAddNoteToList)
{
    VecNotesList vecNoteList;
    ASSERT_TRUE(vecNoteList.addToList(std::make_pair(1, SingleNote("Title1", "Note1"))));
    ASSERT_TRUE(vecNoteList.addToList(std::make_pair(2, SingleNote("Title2", "Note2"))));
    ASSERT_TRUE(vecNoteList.addToList(std::make_pair(3, SingleNote("Title3", "Note3"))));
    ASSERT_EQ(3, vecNoteList.getVecSize());
}

TEST_F(SingleTests, notAbleToAddNoteWithSameId)
{
    VecNotesList vecNoteList;
    vecNoteList.addToList(std::make_pair(1, SingleNote("Title", "Note")));
    ASSERT_FALSE(vecNoteList.addToList(std::make_pair(1, SingleNote("", ""))));
}

TEST_F(SingleTests, isAbleToFindNoteById)
{
    VecNotesList vecNoteList;
    vecNoteList.addToList(std::make_pair(1, SingleNote("Title", "Note isAbleToFindNoteById")));
    ASSERT_EQ("Note isAbleToFindNoteById", vecNoteList.findById(1)->second.getContent());
    vecNoteList.addToList(std::make_pair(2, SingleNote("Title", "Note secound")));
    ASSERT_EQ("Note secound", vecNoteList.findById(2)->second.getContent());
}

TEST_F(SingleTests, isAbleToDeleteNoteById)
{
    VecNotesList vecNoteList;
    vecNoteList.addToList(std::make_pair(1, SingleNote("Title", "one")));
    vecNoteList.addToList(std::make_pair(2, SingleNote("Title", "two")));
    ASSERT_FALSE(vecNoteList.deleteNoteById(3));
    ASSERT_TRUE(vecNoteList.deleteNoteById(1));
    ASSERT_TRUE(vecNoteList.deleteNoteById(2));
}

TEST_F(SingleTests, isAbleToFindCategoryByName)
{
    VecCategoryName vecCategoryName;
    vecCategoryName.addCategory(std::make_pair(1, Category("FirstCategory")));
    vecCategoryName.addCategory(std::make_pair(2, Category("SecoundCategory")));
    ASSERT_EQ("SecoundCategory", vecCategoryName.findByName("SecoundCategory")->second.getName());
    ASSERT_EQ("FirstCategory", vecCategoryName.findByName("FirstCategory")->second.getName());
    ASSERT_EQ(2, vecCategoryName.findByName("SecoundCategory")->first);
    ASSERT_EQ(1, vecCategoryName.findByName("FirstCategory")->first);
}

TEST_F(SingleTests, isAbleToAddRelation)
{
    RelationshipTable relationshipTable;
    ASSERT_TRUE(relationshipTable.addRelation(1,1));
    ASSERT_TRUE(relationshipTable.addRelation(2,1));
    ASSERT_TRUE(relationshipTable.addRelation(1,2));
}

TEST_F(SingleTests, isAbleToConvertNoteToString)
{
    VecNotesList vecNoteList;
    vecNoteList.addToList(std::make_pair(1, SingleNote("Title", "Note")));
    Converter converter;
    ASSERT_EQ("{[1]};{[Title]};{[Note]};", converter.convertNoteToString(*(vecNoteList.findById(1))));

}

TEST_F(SingleTests, isAbleToConvertStringToNote)
{
    VecNotesList vecNoteList;
    Converter converter;
    vecNoteList.addToList(converter.convertStringToNote("{[1]};{[Title]};{[Note]}"));

    ASSERT_EQ(vecNoteList.findById(1)->first, 1);
    ASSERT_EQ(vecNoteList.findById(1)->first, 1);
    ASSERT_EQ(vecNoteList.findById(1)->second.getTitle(), "Title");
    ASSERT_EQ(vecNoteList.findById(1)->second.getContent() , "Note");

}

TEST_F(SingleTests, isAbleToCreateNoteFileIfNotPresent)
{
    remove( "../TagNotebook/src/noteslist.txt" );
    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    ASSERT_TRUE(dbControler.createNewNoteFile());
}

TEST_F(SingleTests, isAbleAddNoteToFile)
{
    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    ASSERT_TRUE(dbControler.addNoteToFile(1, SingleNote("Title", "Note")));
    ASSERT_EQ("{[1]};{[Title]};{[Note]};", dbControler.pullDataFromFileNotes()[0]);
}

TEST_F(SingleTests, isAbleToOpenFile)
{

    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    ASSERT_EQ("{[1]};{[Title]};{[Note]};", dbControler.pullDataFromFileNotes()[0]);
}

TEST_F(SingleTests, isAbleToConvertFileData)
{
    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    VecNotesList vecNoteList;
    Converter converter;
    std::vector<std::string> vecOfNotesFromDB;
    dbControler.addNoteToFile(2, SingleNote("Title", "Note2"));
    vecOfNotesFromDB = dbControler.pullDataFromFileNotes();

    ASSERT_EQ("{[1]};{[Title]};{[Note]};", vecOfNotesFromDB[0]);
    ASSERT_EQ("{[2]};{[Title]};{[Note2]};", vecOfNotesFromDB[1]);

    for(auto a : vecOfNotesFromDB)
        ASSERT_TRUE(vecNoteList.addToList(converter.convertStringToNote(a)));

}

TEST_F(SingleTests, isAbleToCreateCategoryFileIfNotPresent)
{
    remove( "../TagNotebook/src/categorieslist.txt" );
    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    ASSERT_TRUE(dbControler.createNewCategoryFile());
}

TEST_F(SingleTests, isAbleAddCategoryToFile)
{
    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    ASSERT_TRUE(dbControler.addCategoryToFile(1, Category("Category")));
}

TEST_F(SingleTests, isAbleToPullDataFromFileCategory)
{
    DBControler dbControler("../TagNotebook/src/noteslist.txt", "../TagNotebook/src/categorieslist.txt");
    std::vector<std::string> vec;
    vec.push_back(dbControler.pullDataFromFileCategory()[0]);
    ASSERT_EQ("{[1]};{[Category]};", vec[0]);
    dbControler.addCategoryToFile(2, Category("Category2"));
    vec.push_back(dbControler.pullDataFromFileCategory()[1]);
    ASSERT_EQ("{[2]};{[Category2]};", vec[1]);
}

TEST_F(SingleTests, isAbleToConvertStringToCategory)
{
    Converter converter;
    ASSERT_EQ(1, converter.convertStringToCategory("{[1]};{[Category]};").first);
    ASSERT_EQ("Category", converter.convertStringToCategory("{[1]};{[Category]};").second.getName());
}
