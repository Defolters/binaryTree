#ifndef TREE
#define TREE
#include "Node.h"
#include "stdafx.h"
#include <vector>

class Tree
{
public:
    Tree();
    ~Tree();
    std::vector<std::string> findById(int id_);
    int addNode(int id_, std::string name_, std::string badGuy_); // some data
    int deleteNode(int id_);
    Node* returnRoot();

private:
    int length;
    Node* root;

};
#endif
