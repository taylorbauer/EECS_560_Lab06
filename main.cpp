#include <iostream>
#include <fstream>
#include <chrono>
#include "Menu.h"
#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "\nPlease make sure you are including a filename in the command line!\n";
        cout << "Ex: ./Lab06 data.txt\n\n";
        return 0;
    }

    fstream myFile;
    myFile.open(argv[1]);

    if (!myFile) {
        cout << "\nError opening file! Please make sure it is a valid file and try again.\n\n";
        return 0;
    }
    else {
        cout << "\nSuccessfully opened file.\n\n";
    }

    int valueCount = 0;
    int currentValue = ' ';
    while (!myFile.eof()){
        myFile >> currentValue;
        valueCount ++;
    }

    myFile.close();
    myFile.open(argv[1]);

    int tempArr[valueCount];
    for (int i; i < valueCount; i++) {
        myFile >> tempArr[i];
    }
    myFile.close();


    MaxHeap max;
    MinHeap min;
    

    auto start = chrono::high_resolution_clock::now();

    for (int i; i < valueCount; i++) {
        //max.insert(tempArr[i]);
        min.insert(tempArr[i]);
    }

    auto  end = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    cout << "heapify() took " << elapsedTime.count()  << " nanoseconds.\n";
    
    
    Menu mainMenu(max, min);
    mainMenu.run();

    return 0;
}