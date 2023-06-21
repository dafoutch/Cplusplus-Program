#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>
using namespace std;

class ItemTracker {
public:
    ItemTracker(const string& file_name);
    int countFrequency(const string& word) const;
    void printFrequencyList() const;
    void printHistogram() const;
    void createBackupFile() const;

private:
    string file_name;
    map<string, int> frequency_list;

    void calculateFrequencies();
};

#endif
