#include "hashDH.hpp"
#include <iostream>

using namespace std;

HashTable::HashTable(int bsize){
    tableSize = bsize;
    int hashTable[tableSize];
    table = hashTable;
    for(int i = 0; i < bsize; i++){
        table[i] = -1;
    }
    
}

bool HashTable::insertItem(int key){
    int tempCollisions = 0;
    bool keyInserted = false;
    int index = hashFunction(key);
    while(keyInserted == false){
        if(table[index] == -1){
            table[index] = key;
            keyInserted = true;
        }
        else{
            tempCollisions++;
            
            index = (hashFunction(key) + (tempCollisions * hashFunctionDH(key))) % tableSize;
            if(tempCollisions > 5){
                cout << index << endl;
            }
        }
    }
    numOfcolision += tempCollisions;
    return keyInserted;
}

unsigned int HashTable::hashFunction(int key){
    return key % tableSize;
}

unsigned int HashTable::hashFunctionDH(int key){
    return (8363 - (key % 8363));
}

void HashTable::printTable(){
    for(int i = 0; i < 10009; i++){
        if(table[i] == -1){
            cout << i << ": Blank\t";
        }
        else{
            cout << i << ": " << table[i] << "\t";
        }
    }
    cout << endl;
    cout << endl;

    cout << table[10008] << endl;
    // if(table[10008] == -1){
    //     cout << "true1" << endl;
    // }
    // if(table[0] == -1){
    //     cout << "true2" << endl;
    // }
}

int HashTable::getNumOfCollision(){
    return numOfcolision;
}

int HashTable::searchItem(int key){
    int tempCollisions = 0;
    bool keyFound = false;
    int index = hashFunction(key);
    while(keyFound == false){
        if(table[index] == key){
            keyFound = true;
            return index;
        }
        else{
            tempCollisions++;
            index = (index + (tempCollisions * hashFunctionDH(key))) % tableSize;
        }
    }
    return 0;
}