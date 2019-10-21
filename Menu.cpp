#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(MaxHeap maxHeap, MinHeap minHeap) {
    max = maxHeap;
    min = minHeap;
}

void Menu::run() {
    cin.clear();
    int selection = 0;
    cout << "\nWelcome!\n";
    while (selection != 7) {
        cout << "Please choose one of the following commands:\n"
            << "1. Insert\n"
            << "2. Delete\n"
            << "3. PQ Highest\n"
            << "4. PQ Lowest\n"
            << "5. Level Order\n"
            << "6. Time to Lowest PQ\n"
            << "7. Exit\n"
            << "Your selection: ";
        cin >> selection;
        if (selection == 1) {
            cout << "What value would you like to insert (please only insert non-zero, positive integers)? ";
            int insertion;
            cin >> insertion;

            cout << "Max heap:\n";
            if (max.insert(insertion)) {
                cout << "The value " << insertion << " inserted successfully!\n";
            }
            else {
                cout << "Something has gone wrong with insertion.\n";
            }
            cout << "\nMin heap:\n";
            if (min.insert(insertion)) {
                cout << "The value " << insertion << " inserted successfully!\n";
            }
            else {
                cout << "Something has gone wrong with insertion.\n";
            }
        }
        else if (selection == 2) {
            max.deleteRoot();
            min.deleteRoot();
        }
        else if (selection == 3) {
            max.PQHighest();
            min.PQHighest();
        }
        else if (selection == 4) {
            max.PQLowest();
            min.PQLowest();
        }
        else if (selection == 5) {
            max.levelOrder();
            min.levelOrder();
        }
        else if (selection == 6) {
            max.timeLowestPQ();
            min.timeLowestPQ();
        }
        else if (selection == 7) {
            cout << "\n\nGoodbye!!!\n\n";
            return;
        }
        else {
            selection = 0;
            cout << "I don't think that's a valid selection, please try again!";
        }
    }
}
