#include <cmath>
#include <iostream>
#include <chrono>
#include "MaxHeap.h"

using namespace std;

MaxHeap::MaxHeap() {
    for (int i = 0; i < 15000; i++) {
        arr[i] = 0;
    }
    size = 0;
}

bool MaxHeap::insert(int value) {
    if (size + 1 > 15000) {
        return false;
    }
    else {
        arr[size] = value;
        heapify(size);  // heapify the heap starting at the new node
        size ++;
        return true;
    }
}

void MaxHeap::heapify(int index) {
    if (index == 0) {
        return;
    }
    else {
        int parentIndex = ((index - 1) / 3);
        if (arr[parentIndex] > arr[index]) {        // if the parent is larger than the child   (things are good)
            return;
        }
        else {                                      // if the parent is smaller than the child  (need to swap)
            int temp = arr[index];
            arr[index] = arr[parentIndex];
            arr[parentIndex] = temp;
            heapify(parentIndex);
            return;
        }
    }
}

void MaxHeap::levelOrder() {
    cout << "\nPrinting Max Heap in level order: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

bool MaxHeap::deleteRoot() {
    if (size == 0) {
        return false;
    }
    else if (size == 1) {
        cout << "\nDeleting the value " << arr[0] << " from the Max Heap.\n";
        arr[0] = 0;
        size --;
        return true;
    }
    else {
        cout << "\nDeleting the value " << arr[0] << " from the Max Heap.\n";
        arr[0] = arr[size - 1];         // Swapping the last node with the root
        arr[size - 1] = 0;
        deleteSwapper(0);               // Reorder everything (starting at the root) to maintain heap property
        size --;
        return true;
    }
}



void MaxHeap::deleteSwapper(int index) {
    if (arr[index * 3 + 1] == 0) {      // ie if there are no chilcren (no first child), return now
        return;
    }
    else {
        int firstChildIndex = index * 3 + 1;
        int secondChildIndex = index * 3 + 2;
        int thirdChildIndex = index * 3 + 3;

        //  If first child is bigger than node, and first child is bigger than the other 2 children
        //  NOTE: When this is copied over to minheap, we also need to check to make sure that the children exist
        if ((arr[firstChildIndex] > arr[index]) && (arr[firstChildIndex] > arr[secondChildIndex]) &&(arr[firstChildIndex] > arr[thirdChildIndex])) {
                swap(index, firstChildIndex);
                deleteSwapper(firstChildIndex);
                return;
        }

        //  We know that first child is not bigger than second child
        //  So, if second child is bigger than node, and second child is bigger than 3rd child
        else if ((arr[secondChildIndex] > arr[index]) && (arr[secondChildIndex] > arr[thirdChildIndex])) {
            swap(index, secondChildIndex);
            deleteSwapper(secondChildIndex);
            return;
        }

        else if (arr[thirdChildIndex] > arr[index]) {
            swap(index, thirdChildIndex);
            deleteSwapper(thirdChildIndex);
            return;
        }

        //  The node is bigger than it's 3 children, so no further swapping is necessary
        else {
            return;
        }
    }

}

void MaxHeap::swap(int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
    return;
}

void MaxHeap::PQHighest() {
    cout << "\nThe value with the maximum priority on the Max Heap is " << arr[0] << ".\n";
    return;
}

void MaxHeap::PQLowest() {
    int lowest = 0;
    if (size == 1) {
        lowest = arr[0];
    }
    else {
        int firstLeafIndex = 0;
        while ((firstLeafIndex * 3 + 1) < size) {
            firstLeafIndex = (firstLeafIndex * 3 + 1);
        }
        // cout << "\nI think the first leaf (level-order) is the value " << arr[firstLeafIndex] << endl;
        lowest = arr[firstLeafIndex];
        for (int i = firstLeafIndex; i < size; i++) {
            if (arr[i] < lowest) {
                lowest = arr[i];
            }
        }
    }
    cout << "\nThe value with the lowest priority on the Max Heap is " << lowest << ".\n";
    return;
}

void MaxHeap::timeLowestPQ() {  // To learn timing in C++ some of this is pretty directly lifted from the tutorial at https://www.geeksforgeeks.org/chrono-in-c/
    chrono::time_point<std::chrono::system_clock> start = chrono::system_clock::now();
    PQLowest();
    chrono::time_point<std::chrono::system_clock> end = chrono::system_clock::now();
    chrono::duration<double> elapsedTime = end - start;
    cout << "Finding lowest priority value on the Max Heap took " << elapsedTime.count() << " seconds.\n";
    return;
}