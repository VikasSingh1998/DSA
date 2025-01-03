#include <bits/stdc++.h>
using namespace std;

//We need to create the object of the class Node.
//new Node(10); ==> create a node with data=10 and left and right will point to nullptr;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    
    //We have to create the constructor to initialize the value.
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
private:
    Node* root;
    
public:
    //constructor will be called when the instance of the Tree will be create
    //root will set as nullptr initially.
    Tree()
    {
        root = nullptr;
    }
    void setRoot(int val)
    {
        root.data = val;
    }
    
    void insertNode(int val)
    {
        //First we have to create the Node with the given value and left and right as nullptr
        //t is the pointer to the newly create node.
        Node* t = new Node(val);
        
        //In the very beginning root will be node when no node is present in the tree.
        //So root will start pointing to this newly created node.
        if(root == nullptr)
        {
            root = t;
        }
        else
        {
            queue<Node*> q;
            //push the root into the queue
            if(root!=nullptr) q.push();
        }
    }
    
};

int main()
{
    std::cout<<"Hello World";
    //When we will create the Tree object "new Tree()" ==> one Node* root will be created set as nullptr;
    Tree t = new Tree();
    
    //function to set the root of the tree.
    t.setRoot(10);
    
    //Once root is created then inseert the node in the binary tree.
    t.insertNode(2);

    return 0;
}
