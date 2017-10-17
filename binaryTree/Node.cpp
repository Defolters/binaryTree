#include "stdafx.h"
#include "Node.h"

/* Some function
    
    It has some func

*/
Node::Node()
{
    id = 0;
    name = "";
    left = nullptr;
    right = nullptr;
}

/* Some function

It has some func

*/
Node::Node(int& id_, std::string& name_, std::string& badGuy_)
{
    id = id_;
    name = name_;
    badGuy = badGuy_;
    left = nullptr;
    right = nullptr;
}


Node::~Node()
{
}

void Node::setId(int& id_)
{
    id = id_;
}

void Node::setLeft(Node* left_)
{
    left = left_;
}

void Node::setRight(Node* right_)
{
    right = right_;
}

void Node::setName(std::string& name_)
{
    name = name_;
}

int Node::getId()
{
    return id;
}

Node* Node::getRight()
{
    return right;
}

Node* Node::getLeft()
{
    return left;
}

std::string Node::getName()
{
    return name;
}

std::string Node::getBadGuy()
{
    return badGuy;
}
