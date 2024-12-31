//Implement tree using array  or vectors 
#include <bits/stdc++.h>
using namespace std;
class BinaryTree
{
private:
    vector<int> tree;

public:
    //Create the constructor to create the tree with n nodes.
    //BinaryTree t(10); ==> create the BinaryTree with 10 nodes
    BinaryTree(int n)
    {
        tree.resize(n,-1);//All the value will be initialized with -1
    }
    //Function to set the root of the tree
    void setRoot(int value)
    {
        tree[0] = value;
    }
    //Function to set the left child of the index i with the given value.
    void setLeftChildOfIndex(int i,int value)
    {
        int leftChildIndex = (2*i)+1;
        //check if the leftChildIndex is in the range of the vector
        if(leftChildIndex <= tree.size()-1)
        {
            tree[leftChildIndex] = value;
        }
        else
        {
            cerr<<"index out for bound for left child"<<endl;
        }
    }
    //Function to set the Right child of the index i with the given value.
    void setRightChildOfIndex(int i,int value)
    {
        int rightChildIndex = (2*i)+2;
        //check if the rightChildIndex is in the range of the vector
        if(rightChildIndex <= tree.size()-1)
        {
            tree[rightChildIndex] = value;
        }
        else
        {
            cerr<<"index out for bound for right child"<<endl;
        }
    }
    
    //Function to displayTree
    void displayTree()
    {
        for(auto e:tree)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    
};

int main()
{
    BinaryTree t(7);//Create the BinaryTree with 7 nodes with all the value initialized as -1
    t.setRoot(25);
    t.setLeftChildOfIndex(0,15);// 0 index left child will be 15.
    t.setRightChildOfIndex(0,20);//0 index Right child will be 20
    t.setLeftChildOfIndex(1,45);
    t.setRightChildOfIndex(1,40);
    t.setRightChildOfIndex(2,55);
    t.displayTree();//25 15 20 45 40 -1 55
    
    return 0;
}
/*
Implementing a tree using an array or vector is often used for binary trees due to their structured nature.
Representation
================
For a binary tree:
The root node is stored at index 0.
For a node at index i:
The left child is at index 2 * i + 1.
The right child is at index 2 * i + 2.
If an element has no child, its position in the array remains empty (e.g., -1 or a placeholder).
*/
