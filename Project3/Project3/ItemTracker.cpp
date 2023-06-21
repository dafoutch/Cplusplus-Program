#include "ItemTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ItemTracker::ItemTracker(const string& file_name)
    : file_name(file_name) {
    calculateFrequencies();
    createBackupFile();
}

int ItemTracker::countFrequency(const string& word) const {
    auto it = frequency_list.find(word);
    if (it != frequency_list.end()) {
        return it->second;
    }
    return 0;
}

void ItemTracker::printFrequencyList() const {
    for (const auto& item : frequency_list) {
        cout << item.first << " " << item.second << endl;
    }
}

void ItemTracker::printHistogram() const {
    for (const auto& item : frequency_list) {
        cout << item.first << " ";
        for (int i = 0; i < item.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void ItemTracker::calculateFrequencies() {
    ifstream file(file_name);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string item;
        while (iss >> item) {
            frequency_list[item]++;
        }
    }
    file.close();
}

void ItemTracker::createBackupFile() const {
    ofstream backup_file("frequency.dat");
    for (const auto& item : frequency_list) {
        backup_file << item.first << " " << item.second << endl;
    }
    backup_file.close();
}