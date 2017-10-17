// binaryTree.cpp : Defines the entry point for the console application.
//
/** Main 
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Node.h"
#include "WorkWithFile.h"


int main()
{
    bool treeInFile = true;

    std::fstream inFile;
    inFile.open("tree.txt");
    if (inFile.fail())
    {
        treeInFile = false;
        std::cout << "File wasn't opened..." << std::endl;
    }
    else
    {
        std::cout << "File opened..." << std::endl;
    }

    Tree tree;
    if (treeInFile == false)
    {
        createTreeFromFile(tree);
    }


    std::cout << "WELCOME TO THE INDIA AIRPORT\n"
        << "PLEASE, ENTER THE ID:" << std::endl;

    int id = 0;
    std::vector<std::string> terror = {"GOOD BOY", "TERRORIST"};
    std::vector<std::string> person;
    while (std::cin >> id)
    {
        if (treeInFile == false)
        {
            person = tree.findById(id);
        }
        else
        {
            person = findByIdInTreeFromFile(inFile, id);
        }
        if (person[0] != "0")
        {
            std::cout << "Person: " << person[0]
                << "\nStatus: " << terror[std::stoi(person[1])]
                << "\nIterations: " << person[2] 
                << "\n\nPLEASE, ENTER THE ID:" << std::endl;
        }
        else
        {
            std::cout << "THERE IS NO SUCH PERSON IN OUR DATABASE" 
                << "\nPLEASE, ENTER THE ID:" << std::endl;
        }
    }
    inFile.close();

    if (treeInFile == false)
    {
        std::cout << "\nWriting tree to the file..." << std::endl;
        writeTreeToFile(tree);
    }
    return 0;
}

