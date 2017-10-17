#include "stdafx.h"
#include "WorkWithFile.h"
#include "Tree.h"
#include "Node.h"
#include <fstream>
#include <limits>


void createTreeFromFile(Tree& tree)
{
    std::ifstream file;
    file.open("binaryTree.txt");

    if (file.fail())
    {
        exit(1);
    }

    std::string key(" ");
    std::string item, name, bad;
    int idFromFile, itFirst, itLast;

    while (std::getline(file, item))
    {
        if (item != "")
        {
            itFirst = item.find(key);
            itLast = item.rfind(key);    // -1 if not found
            int length = itLast - (itFirst+1);
            idFromFile = std::stoi(item.substr(0, itFirst));
            name = item.substr(itFirst + 1, length);
            bad = item.substr(itLast + 1);

            tree.addNode(idFromFile, name, bad); //при добавлении в имя добавлялось badGuy
        }
    }
    file.close();    
}

std::fstream& goToLine(std::fstream& file, unsigned int line) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < line - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

std::vector<std::string> findByIdInTreeFromFile(std::fstream& inFile, int id_)
{
    
   
    std::vector<std::string> data = { "0", "0", "0" }; // name, bad, iterations
    int line = 1;
    //check if first line empty
    inFile.seekg(std::ios::beg);
    std::string stringFromLine;
    std::getline(inFile, stringFromLine);
    if (stringFromLine != "")
    {
        int iterations = 0;
        std::string key("_");
        std::string name, bad;
        int idFromFile, itId, itName, itBad, itLeft;
        int left = 0, right = 0;
        while (true)
        {
            goToLine(inFile, line);
            //read line
            inFile >> stringFromLine;
            //проверка на правильность строки, мб..
            //5_5_0_2_3
            itId = stringFromLine.find(key);
            itName = stringFromLine.find(key, itId+1);
            itBad = stringFromLine.find(key, itName+1);
            itLeft = stringFromLine.find(key, itBad+1);
            
            idFromFile = std::stoi(stringFromLine.substr(0, itId));
            name = stringFromLine.substr(itId + 1, itName-itId-1);;
            bad = stringFromLine.substr(itName + 1, itBad-itName-1);;
            left = std::stoi(stringFromLine.substr(itBad+1, itLeft-itBad-1));
            right = std::stoi(stringFromLine.substr(itLeft+1));

            /*
            itFirst = item.find(key);
            itLast = item.rfind(key);    // -1 if not found
            int length = itLast - (itFirst + 1);
            idFromFile = std::stoi(item.substr(0, itFirst));
            name = item.substr(itFirst + 1, length);
            bad = item.substr(itLast + 1);

            tree.addNode(idFromFile, name, bad); //при добавлении в имя добавлялось badGuy
            */
            //id, name, bad, left, right..
            iterations++;
            
            if (idFromFile == id_)
            {
                // fill data
                data[0] = name;
                data[1] = bad;
                data[2] = std::to_string(iterations);
                return data;
            }
            else if ((id_< idFromFile) && (left != 0))
            {
                line = left;
                //move pointer to left line 
            }
            else if ((id_ > idFromFile) && (right != 0))
            {
                line = right;
                //move pointer to right line 
            }
            else
            {
                return data;
            }
            
        }
    }
    else
    {
        return data;
    }
    
    inFile.close();

    return std::vector<std::string>();
}

void writeTreeToFile(Tree& tree)
{
    std::ofstream outFile;
    outFile.open("tree.txt");
    //if opened
    if (outFile.fail())
    {
        exit(1);
    }
    int filled = 1;
    unsigned int iterations = 0;
    std::vector<Node*> nodes;
    nodes.push_back(tree.returnRoot());
    while (iterations < nodes.size())
    {
        writeNodeToFile(nodes[iterations], filled, nodes, outFile);
        iterations++;
    }
    outFile.close();
}

void writeNodeToFile(Node* node, int& filled, std::vector<Node*>& nodes, std::ofstream& outFile)
{
    outFile << node->getId() << "_" << node->getName() << "_" << node->getBadGuy() << "_";

    if (node->getLeft() != nullptr)
    {
        filled++;
        outFile << filled << "_";
        nodes.push_back(node->getLeft());
    }
    else
    {
        outFile << "0" << "_";
    }

    if (node->getRight() != nullptr)
    {
        filled++;
        outFile << filled;
        nodes.push_back(node->getRight());
    }
    else
    {
        outFile << "0";
    }
    outFile << std::endl;
    /*if (node->getLeft() != nullptr)
    {
    writeNodeToFile(node->getLeft(), filled);
    }
    if (node->getRight() != nullptr)
    {
    writeNodeToFile(node->getRight(), filled);
    }*/
}