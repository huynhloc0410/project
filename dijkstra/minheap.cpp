#include <stdlib.h>  
#include <stdio.h> 
#include <iomanip>
#include "minheap.h"

MinHeap::MinHeap() : capacity(0), size(0), keys(nullptr), values(nullptr) {}

void MinHeap::init(int size) {
    //set capacity and size
    capacity = size;
    size = 0;
    //allocate memory for keys(weights) and values(nodes)
    keys = (double*)malloc(capacity * sizeof(double));
    values = (int*)malloc(capacity * sizeof(int));
}



void MinHeap::push(double key, int value) {
    /*
    if heap is full
        return

    increase size
    set key and value at the end with index as size
    heapify up
    */
   if (size >= capacity)
            return;

        size++;
        int index = size - 1;
        keys[index] = key;
        values[index] = value;
        heapifyUp(index);
}

int MinHeap::pop() {
    /*
    if heap is empty
        return sentinel value

    get root value
    replace root with the last element
    decrease size
    heapify down

    return root value
    */
   if (empty())
            return -1; // Sentinel value indicating heap is empty

        int root = values[0];
        values[0] = values[size - 1];
        keys[0] = keys[size - 1];
        size--;
        heapifyDown(0);
        return root;
}

bool MinHeap::empty() const {
    return size == 0;
    //return true if size is 0, false otherwise
}

void MinHeap::heapifyUp(int index) {
    /*
    while index > 1 and current key is less than parent key (parent key is index / 2)
        swap index with parent
        update index to parent
    */
   while (index > 0 && keys[index] < keys[(index - 1) / 2]) {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
}

void MinHeap::heapifyDown(int index) {
    /*
    find the smallest child from left(2*index) or right(2*index+1) child of index
    if smallest child is smaller than current key
        swap with smallest child with index
        update index
        heapify down
    */
   int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && keys[leftChild] < keys[smallest])
            smallest = leftChild;

        if (rightChild < size && keys[rightChild] < keys[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(index, smallest);
            heapifyDown(smallest);
        }
}

void MinHeap::swap(int i, int j) {
    //swap keys and values at positions i and j
    double tempKey = keys[i];
    int tempValue = values[i];
    keys[i] = keys[j];
    values[i] = values[j];
    keys[j] = tempKey;
    values[j] = tempValue;
}
