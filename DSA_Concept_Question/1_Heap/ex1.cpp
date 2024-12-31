//MaxHeap Implementation by inserting element one by one.
//=========================================================
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
    //While inserting the node in the Heap, we insert the node in the last level-leftmost 
    //So we have to do the heapifyUp
    //We will inset the node at index i, then form that index we will find the correct position for the node at upppr level.
    void heapifyUp(int i)//i is the index at which new value is inserted.
    {
        //If i is pointing to the root, no need to heapify.
        if(i==0) return;
        int parentIndex = getParentIndex(i);
        if(heap[parentIndex]<heap[i])//If the parentIndex has lower value, we will swap the value.
        {
            swap(heap[parentIndex],heap[i]);
        }
        heapifyUp(parentIndex);
    }
    //Used when the root of the heap is disturbed. --> Read comment below.
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
        //Now larget point to the larget among 3 nodes.
        // If the largest is not the current node, swap and continue heapifying down
        if(largest != i)
        {
            //Now swap the largest and the root nodes.
            swap(heap[largest],heap[i]);
            heapifyDown(largest);
        }
    }

public:
    //Method to insert the Element into the MaxHeap
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
    MaxHeap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(8);
    h.printHeap();//8 3 2 1 
    h.insert(5);
    h.printHeap();//8 5 2 1 3 
    cout<<h.pop()<<endl;//8 
    h.printHeap();//5 2 1 3 
    cout<<h.top()<<endl;//5
    h.printHeap();//5 2 1 3 

    return 0;
}
/*
Heapify Down is used when the root of the heap is disturbed, such as during the following scenarios:

1. Deleting the Root Element (Heap Deletion)
When: In a heap, the root (maximum in a max-heap or minimum in a min-heap) is often removed during the delete operation.
Why: After removing the root, the last element of the heap is moved to the root position, potentially violating the heap property.
How: To restore the heap property, heapifyDown is called from the root to move the new root element down to its correct position.
2. During Heap Construction
When: In the process of building a heap from an unordered array using the "bottom-up" approach.
Why: Starting from the last non-leaf node and moving toward the root, heapifyDown ensures that every subtree satisfies the heap property.
How: Each node is treated as a root, and heapifyDown ensures that its subtree becomes a valid heap.
3. Extract-Max or Extract-Min Operation
When: In a max-heap (or min-heap), when the largest (or smallest) element is extracted.
Why: The extraction disturbs the heap structure as the last element is moved to the root.
How: heapifyDown restores the heap property by propagating the root element downward.
*/
