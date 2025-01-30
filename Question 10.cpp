/*Problem Statement:
Design and implement a hash table that supports basic operations like insertion, search, and deletion using collision handling techniques. You are required to use either Chaining or Open Addressing based on the user's input.

Requirements:
The program should allow the user to select the collision-handling method:
CHAINING: Use linked lists to handle collisions.
OPEN_ADDRESSING: Use linear probing to handle collisions.
Perform operations such as INSERT, SEARCH, and DELETE on the hash table.

Input Format:
The first line contains an integer m (the size of the hash table).
The second line contains a string method (CHAINING or OPEN_ADDRESSING).
The third line contains an integer q (the number of queries).
The next q lines contain queries in the following format:
- INSERT key: Insert the given key into the hash table.
- SEARCH key: Check if the given key exists in the hash table. Return ""FOUND"" or ""NOT FOUND"".
- DELETE key: Remove the given key from the hash table.

Output Format:
For each SEARCH query, output ""FOUND"" if the key exists or ""NOT FOUND"" otherwise.

Example:
Input:
10
CHAINING
6
INSERT 15
INSERT 25
SEARCH 15
DELETE 15
SEARCH 15
SEARCH 25

Output:
FOUND
NOT FOUND
FOUND*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int size;
    string method;
    vector<list<int>> chainTable;
    vector<int> openAddressingTable;
    
public:
    HashTable(int s, string m) : size(s), method(m) {
        if (method == "CHAINING") chainTable.resize(size);
        else openAddressingTable.assign(size, -1);
    }
    
    int hashFunction(int key) { return key % size; }
    
    void insert(int key) {
        int index = hashFunction(key);
        if (method == "CHAINING") {
            chainTable[index].push_back(key);
        } else {
            while (openAddressingTable[index] != -1) index = (index + 1) % size;
            openAddressingTable[index] = key;
        }
    }
    
    bool search(int key) {
        int index = hashFunction(key);
        if (method == "CHAINING") {
            for (int val : chainTable[index]) if (val == key) return true;
        } else {
            while (openAddressingTable[index] != -1) {
                if (openAddressingTable[index] == key) return true;
                index = (index + 1) % size;
            }
        }
        return false;
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        if (method == "CHAINING") {
            chainTable[index].remove(key);
        } else {
            while (openAddressingTable[index] != -1) {
                if (openAddressingTable[index] == key) {
                    openAddressingTable[index] = -1;
                    return;
                }
                index = (index + 1) % size;
            }
        }
    }
};

int main() {
    int m, q;
    string method;
    cin >> m >> method >> q;
    HashTable ht(m, method);
    
    while (q--) {
        string command;
        int key;
        cin >> command >> key;
        if (command == "INSERT") ht.insert(key);
        else if (command == "SEARCH") cout << (ht.search(key) ? "FOUND" : "NOT FOUND") << endl;
        else if (command == "DELETE") ht.remove(key);
    }
    return 0;
}
