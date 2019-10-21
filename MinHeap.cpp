#include <cmath>
#include <iostream>
#include <chrono>
#include "MinHeap.h"

using namespace std;

MinHeap::MinHeap() {
    for (int i = 0; i < 15000; i++) {
        arr[i] = 0;
    }
    size = 0;
}

bool MinHeap::insert(int value) {
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

void MinHeap::heapify(int index) {
    if (index == 0) {
        return;
    }
    else {
        int parentIndex = ((index - 1) / 3);
        if (arr[parentIndex] < arr[index]) {        // if the parent is smaller than the child   (things are good)
            return;
        }
        else {                                      // if the parent is larger than the child  (need to swap)
            int temp = arr[index];
            arr[index] = arr[parentIndex];
            arr[parentIndex] = temp;
            heapify(parentIndex);
            return;
        }
    }
}

void MinHeap::levelOrder() {
    cout << "\nPrinting Min Heap in level order: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

bool MinHeap::deleteRoot() {
    if (size == 0) {
        return false;
    }
    else if (size == 1) {
        cout << "\nDeleting the value " << arr[0] << " from the Min Heap.\n";
        arr[0] = 0;
        size --;
        return true;
    }
    else {
        cout << "\nDeleting the value " << arr[0] << " from the Min Heap.\n";
        arr[0] = arr[size - 1];         // Swapping the last node with the root
        arr[size - 1] = 0;
        deleteSwapper(0);               // Reorder everything (starting at the root) to maintain heap property
        size --;
        return true;
    }
}



void MinHeap::deleteSwapper(int index) {
    if (arr[index * 3 + 1] == 0) {      // ie if there are no chilcren (no first child), return now
        return;
    }
    else {
        int firstChildIndex = index * 3 + 1;
        int secondChildIndex = index * 3 + 2;
        int thirdChildIndex = index * 3 + 3;

        //  If first child is smaller than node, and first child is smaller than the other 2 children, and the children exist

        //  THIS BLOCK OF CODE IS FOR IF ALL THREE CHILDREN EXIST
        if (arr[thirdChildIndex] != 0){
            if ((arr[firstChildIndex] < arr[index]) && (arr[firstChildIndex] < arr[secondChildIndex]) &&(arr[firstChildIndex] < arr[thirdChildIndex])) {
                swap(index, firstChildIndex);
                deleteSwapper(firstChildIndex);
                return;
        }
        else if ((arr[secondChildIndex] < arr[index]) && (arr[secondChildIndex] < arr[thirdChildIndex])) {
            swap(index, secondChildIndex);
            deleteSwapper(secondChildIndex);
            return;
        }

        else if (arr[thirdChildIndex] < arr[index]) {
            swap(index, thirdChildIndex);
            deleteSwapper(thirdChildIndex);
            return;
            }
        }

        //  THIS BLOCK OF CODE IS FOR IF ONLY 2 CHILDREN EXIST
        else if (arr[secondChildIndex] != 0) {
            if ((arr[firstChildIndex] < arr[index]) && (arr[firstChildIndex] < arr[secondChildIndex])) { //ie, the first child is higher priority than the second
                swap(index, firstChildIndex);
                deleteSwapper(firstChildIndex);
                return;
            }
            else if (arr[secondChildIndex] < arr[index]) {
                swap(index, secondChildIndex);
                deleteSwapper(secondChildIndex);
                return;
            }
        }

        //  THIS BLOCK OF CODE IS FOR IF THERE IS ONLY ONE CHILD
        else{
            if (arr[firstChildIndex] < arr[index]){
                swap(index, firstChildIndex);
                deleteSwapper(firstChildIndex);
                return;
            }
        }

        //  This line will only be executed when no more swapping is necessary
        return;
    }

}

void MinHeap::swap(int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
    return;
}

void MinHeap::PQHighest() {
    cout << "\nThe value with the maximum priority on the Min Heap is " << arr[0] << ".\n";
    return;
}

void MinHeap::PQLowest() {
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
            if (arr[i] > lowest) {
                lowest = arr[i];
            }
        }
    }
    cout << "\nThe value with the lowest priority on the Min Heap is " << lowest << ".\n";
    return;
}

void MinHeap::timeLowestPQ() {  // To learn timing in C++ some of this is pretty directly lifted from the tutorial at https://www.geeksforgeeks.org/chrono-in-c/
    auto start = chrono::high_resolution_clock::now();
    PQLowest();
    auto  end = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Finding lowest priority value on the Min Heap took " << elapsedTime.count() << " nanoseconds.\n";
    return;
}

void MinHeap::time() {
    auto start = chrono::high_resolution_clock::now();
    deleteRoot();
    auto  end = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Deleting highest priority value on the Min Heap took " << elapsedTime.count() << " nanoseconds.\n";
    return;
}