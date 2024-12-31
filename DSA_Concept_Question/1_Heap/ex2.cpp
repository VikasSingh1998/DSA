//Implement the minHeap by inserting element one by one.
#include <bits/stdc++.h>
using namespace std;
class MinHeap
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
    //While inserting the node in the Heap, we insert the node in the last level-leftmost 
    //So we have to do the heapifyUp
    //We will inset the node at index i, then form that index we will find the correct position for the node at upppr level.
    void heapifyUp(int i)//i is the index at which new value is inserted.
    {
        //If i is pointing to the root, no need to heapify.
        if(i==0) return;
        int parentIndex = getParentIndex(i);
        if(heap[parentIndex] > heap[i])//If the parentIndex has higher value, we will swap the value.
        {
            swap(heap[parentIndex],heap[i]);
        }
        heapifyUp(parentIndex);
    }
    //Used when the root of the heap is disturbed. --> Read comment below.
    void heapifyDown(int i)//i is the index to root/from where we have to do the heapifyDown
    {
        int smallest = i;
        int leftChildIndex = getLeftChildIndex(i);
        int rightChildIndex = getRightChildIndex(i);
        
        if(leftChildIndex < heap.size() && heap[leftChildIndex]<heap[smallest])
        {
            smallest = leftChildIndex;
        }
        if(rightChildIndex < heap.size() && heap[rightChildIndex]<heap[smallest])
        {
            smallest = rightChildIndex;
        }
        //Now smallest point to the smallest value among 3 nodes.
        // If the smallest is not the current node, swap and continue heapifying down
        if(smallest != i)
        {
            //Now swap the largest and the root nodes.
            swap(heap[smallest],heap[i]);
            heapifyDown(smallest);
        }
    }

public:
    //Method to insert the Element into the MinHeap
    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size()-1);//do the heapifyUp on the node inserted.
    }
    
    //Method to pop the element from the heap.
    int pop()
    {
        if (heap.empty()) return -1; // Return -1 if the heap is empty
        int top = heap[0];          // Store the root element (max value for a max heap)
        int n = heap.size();
        swap(heap[0], heap[n - 1]); // Move the last element to the root
        heap.pop_back();            // Remove the last element
        heapifyDown(0);             // Restore the heap property by heapifying down from the root
        return top;                 // Return the original root value
    }
    
    //Funtion to get the max value of the MaxHeap without removing it.
    int top()
    {
        if (heap.empty()) return -1; // Return -1 if the heap is empty
        return heap[0];
    }
    
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
    // std::cout<<"Hello World";
    MinHeap h;
    h.insert(8);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.printHeap();//5 7 6 8
    h.insert(3);
    h.printHeap();//3 5 6 8 7
    cout<<h.pop()<<endl;//3
    h.printHeap();//5 7 6 8
    cout<<h.top()<<endl;//5
    h.printHeap();//5 7 6 8

    return 0;
}

