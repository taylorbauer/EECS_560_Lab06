#ifndef MIN_HEAP_H
#define MIN_HEAP_H

class MinHeap{
public:


    MinHeap();

    //  Inserts the given value onto the heap.
    //  It must be a positive integer
    bool insert(int value);

    //  Prints the heap in level-order
    void levelOrder();

    //  Deletes the root and maintains heap properties
    bool deleteRoot();

    //  Prints the highest priority element
    void PQHighest();

    //  Prints the lowest priority element
    void PQLowest();

    //  Finds the lowest element and times the process, printing the results
    void timeLowestPQ();

    //  A secret function not visible to the user but accessible by choosing slection "8"
    //  This is what i used to gather all my time data
    void time();
private:

    //  A helper, recursive function for top-down insertion
    void heapify(int index);

    //  A helper, recursive function for deletion
    void deleteSwapper(int index);

    //  A helper function for deletion and insertion
    void swap(int first, int second);
    
    int arr[15000]; //The array that holds the values
                    //Instead of nullptr, the empty value is 0
    int size = 0;
};

#endif