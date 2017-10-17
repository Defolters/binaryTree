#include "stdafx.h"
#include "Tree.h"
#include "Node.h"


Tree::Tree()
{
    length = 0;
    root = nullptr;
}


Tree::~Tree()
{
}

std::vector<std::string> Tree::findById(int id_)
{
    std::vector<std::string> data = { "0", "0", "0" }; // name, bad, iterations
    if (root != nullptr)
    {
        Node* temp = root;
        int iterations = 0;
        while (1)
        {
            iterations++;
            if (temp->getId() == id_)
            {
                data[0] = temp->getName();
                data[1] = temp->getBadGuy();
                data[2] = std::to_string(iterations);
                break;
            }
            else if ((temp->getId() > id_) && (temp->getLeft() != nullptr))
            {
                temp = temp->getLeft();
            }
            else if ((temp->getId() < id_) && (temp->getRight() != nullptr))
            {
                temp = temp->getRight();
            }
            else
            {
                return data;
            }
        }
        return data;
    }
    else
    {
        return data;
    }
}

int Tree::addNode(int id_, std::string name_, std::string badGuy_)
{
    Node* node = new Node(id_, name_, badGuy_);
    if (root == nullptr)
    {
        root = node;
        length++;
    }
    else
    {
        Node* temp = root;
        while (1)
        {
            if (temp->getId() == id_)
            {
                // assert
                return 1;
            }
            else if (temp->getId() > id_)
            {
                if (temp->getLeft() != nullptr)
                {
                    temp = temp->getLeft();
                }
                else
                {
                    temp->setLeft(node);
                    length++;
                    return 0;
                }
            }
            else if (temp->getId() < id_)
            {
                if (temp->getRight() != nullptr)
                {
                    temp = temp->getRight();
                }
                else
                {
                    temp->setRight(node);
                    length++;
                    return 0;
                }
            }

        }
        // ищем нужное место, и сравниваем значения
        //если меньше - идем влево
        // проверяем nullptr
        //if null left = node
        //else continue
        //если больше - идем вправо
        // если равно, кидаем exception
    }
    return 0;
}

int Tree::deleteNode(int id_)
{
    length--;
    return 0;
}

Node * Tree::returnRoot()
{
    return root;
}
