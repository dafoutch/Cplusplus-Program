#include <iostream>
#include <string>
#include "ItemTracker.h"

using namespace std;

int main() {
    string file_name = "CS210_Project_Three_Input_File.txt";
    ItemTracker itemTracker(file_name);

    while (true) {
        cout << "\nMenu Options:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string word;
            cout << "Enter the item you wish to search: ";
            cin >> word;
            int frequency = itemTracker.countFrequency(word);
            cout << "Frequency of \"" << word << "\": " << frequency << endl;
        }
        else if (choice == 2) {
            itemTracker.printFrequencyList();
        }
        else if (choice == 3) {
            itemTracker.printHistogram();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}