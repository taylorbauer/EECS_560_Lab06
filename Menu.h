#ifndef MENU_H
#define MENU_H
#include "MaxHeap.h"
#include "MinHeap.h"

class Menu {
public:
    Menu(MaxHeap maxHeap, MinHeap minHeap);
    void run();
private:
    MaxHeap max;
    MinHeap min;
};

#endif