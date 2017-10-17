#ifndef WORK_WITH_FILE
#define WORK_WITH_FILE
#include "Node.h"
#include "stdafx.h"
#include <vector>
#include "Tree.h"

void createTreeFromFile(Tree& tree);
std::fstream& goToLine(std::fstream& file, unsigned int line);
std::vector<std::string> findByIdInTreeFromFile(std::fstream& inFile, int id_);
void writeTreeToFile(Tree& tree);
void writeNodeToFile(Node* node, int& filled, std::vector<Node*>& nodes, std::ofstream& outFile);
//read tree from file
//create tree from file
// save tree to the file
#endif // WORK_WITH_FILE_H
