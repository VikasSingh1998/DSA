// Write the code to convert the array or vector into maxHeap or MinHeap
// ========================================================================
#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
private:
    vector<int> heap;
    
    //This will return the parent Index of the node localted at index i in the array.
    int getParentIndex(int i)
    {
        return (i-1)/2;
    }
    //this will return the left child index of the node localted at index i 
    int getLeftChildIndex(int i)
    {
        return 2*i+1;
    }
    //this will return the right child index of the node localted at index i 
    int getRightChildIndex(int i)
    {
        return 2*i+2;
    }
    
    //Used when the root of the heap is disturbed.
    void heapifyDown(int i)//i is the index to root/from where we have to do the heapifyDown
    {
        int largest = i;
        int leftChildIndex = getLeftChildIndex(i);
        int rightChildIndex = getRightChildIndex(i);
        
        if(leftChildIndex < heap.size() && heap[leftChildIndex]>heap[largest])
        {
            largest = leftChildIndex;
        }
        if(rightChildIndex < heap.size() && heap[rightChildIndex]>heap[largest])
        {
            largest = rightChildIndex;
        }
        //Now largest point to the largest value among 3 nodes.
        // If the largest is not the current node, swap and continue heapifying down
        if(largest != i)
        {
            //Now swap the largest and the root nodes.
            swap(heap[largest],heap[i]);
            heapifyDown(largest);
        }
    }

public:
    void buildHeap(vector<int> &v)
    {
        heap = v;
        int n=v.size();//total node in the MaxHeap
        //from the parent of the last node, do the heapifyDown till root
        for(int i=(n-1)/2;i>=0;i--)
        {
            heapifyDown(i);
        }
    }
    //Method to print the heap.
    void printHeap()
    {
        for(const auto e:heap)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    vector<int> v({10,8,12,16,14,11});
    MaxHeap h;
    h.buildHeap(v);
    h.printHeap();
    return 0;
}

