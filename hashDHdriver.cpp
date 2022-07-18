#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "hashDH.hpp"

using namespace std;

int main(int argc, char* argv[]){
    // int data[10000];
    // int index = 0;
    // string input;
    // string ID;
    // ifstream inFile;

    // inFile.open(argv[1]);
    // getline(inFile, input);
    // stringstream str(input);

    // while(getline(str, ID, ',')){
    //     data[index] = stoi(ID);
    //     index++;
    // }

    int data[10000];
    int index = 0;
    float insert[50];
    float search[50];

    string input;
    string ID;
    ifstream inFile;

    inFile.open(argv[1]);
    getline(inFile, input);
    stringstream str(input);

    while(getline(str, ID, ',')){
        data[index] = stoi(ID); 
        index++;
    }

    HashTable hashT = HashTable(10009);
    //hashT.printTable();
    int timesThru = 0;

    for(int i = 0; i < 50; i++){
        auto start = chrono::steady_clock::now();
        for(int j = 0; j < 200; j++){
            hashT.insertItem(data[j + timesThru]);
            //hashT.printTable();
        }
        //cout << i << ": here" << endl;
        auto end = chrono::steady_clock::now();
        insert[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 200.0;
        timesThru += 200;
    }

    timesThru = 0;
    int randIndex[200];
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 200; j++){
            randIndex[j] = timesThru + (rand()%200);
        }
        auto start = chrono::steady_clock::now();
        for(int j = 0; j < 200; j++){
            hashT.searchItem(data[randIndex[j]]);
        }
        auto end = chrono::steady_clock::now();
        search[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 200.0;
        timesThru += 200;
    }

}
