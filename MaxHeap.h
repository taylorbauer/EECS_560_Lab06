#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class MaxHeap{
public:
    MaxHeap();
    bool insert(int value);
    void levelOrder();
    bool deleteRoot();
    void PQHighest();
    void PQLowest();
    void timeLowestPQ();
private:
    void heapify(int index);
    void deleteSwapper(int index);
    void swap(int first, int second);
    int arr[15000]; //The array that holds the values
                    //Instead of nullptr, the empty value is 0
    int size = 0;
};

#endif