#ifndef MENU_H
#define MENU_H
#include "MaxHeap.h"
#include "MinHeap.h"

//  The class that handles all user interaction and manages the two heaps
class Menu {
public:

    //  Basic menu constructor, requires a minheap and maxheap object
    Menu(MaxHeap maxHeap, MinHeap minHeap);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:
    MaxHeap max;
    MinHeap min;
};

#endif