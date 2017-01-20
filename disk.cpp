#include <iostream>
#include <fstream>
#include <vector>
#include "stdlib.h"

using namespace std;

void requester(char *fname) {
    ifstream diskfile(fname);
    vector<int> diskreq;
    int num;
    if (!diskfile) {
        cerr << "error: unable to open file" << fname << endl;
        return;
    } 
    while (diskfile >> num) {
        cout << "request number: " << num << endl; 
        diskreq.push_back(num);   
    }
    return; 
}

int main(int argc, char *argv[]) {
    int MAX_DISK_QUEUE = atoi(argv[1]);
    for (int i = 1; i != argc; ++i) {
        requester(argv[i+1]);       
    }
    return 0;
}
