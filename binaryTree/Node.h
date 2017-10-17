#ifndef NODE
#define NODE
#include <string>
/** Class contain realisation of node and some important operations

*/
class Node
{
public:

    Node();
    Node(int& id_, std::string& name_, std::string& badGuy_);
    ~Node();
    // setters
    void setId(int& id_);
    void setLeft(Node* left_);
    void setRight(Node* right_);
    void setName(std::string& name_);
    //getters
    int getId();
    Node* getRight();
    Node* getLeft();
    std::string getName();
    std::string getBadGuy();

private:
    int id;
    std::string name;
    std::string badGuy;
    // some data
    Node* left;
    Node* right;
};
#endif
