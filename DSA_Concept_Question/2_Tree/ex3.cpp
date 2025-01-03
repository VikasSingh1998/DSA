//Same code with struct ==> with struct no difference is there.
=================================================================

#include <bits/stdc++.h>
using namespace std;

//We need to create the object of the class Node.
//new Node(10); ==> create a node with data=10 and left and right will point to nullptr;
struct Node
{
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
    
    //Function to insert the Node into the Tree.
    void insertNode(int val)
    {
        //First we have to create the Node with the given value and left and right as nullptr
        //t is the pointer to the newly create node.
        Node* t = new Node(val);
        
        //In the very beginning root will be nullptr when no node is present in the tree.
        //So root will start pointing to this newly created node.
        if(root == nullptr)
        {
            root = t;
        }
        else //when we have atleast one node in the tree.
        {
            //push the root into the queue
            queue<Node*> q;
            q.push(root);
            
            while(!q.empty())
            {
                Node* currNode = q.front();
                q.pop();
                
                if(currNode->left ==nullptr)
                {
                    currNode->left = t;
                    return;
                }
                else
                {
                    q.push(currNode->left);
                }
                if(currNode->right == nullptr)
                {
                    currNode-> right = t;
                    return;
                }
                else
                {
                    q.push(currNode->right);
                }
            }
        }
    }
    void displayLevelOrder()
    {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* currNode = q.front();
                q.pop();
                cout<<currNode->data<<" ";
                
                if(currNode->left != nullptr)
                {
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr)
                {
                    q.push(currNode-> right);
                }
            }
        }
        cout<<endl;
    }
    
};

int main()
{
    //When we will create the Tree object "new Tree()" ==> one Node* root will be created set as nullptr;
    Tree t;
    
    //Once root is created then inseert the node in the binary tree.
    t.insertNode(2);
    t.insertNode(12);
    t.insertNode(21);
    t.insertNode(25);
    t.insertNode(46);
    t.insertNode(67);
    
    t.displayLevelOrder();

    return 0;
}
