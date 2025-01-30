/*Problem Statement:
A Direct Address Table is a simple way to map a key to its value using an array. The index of the array represents the key, and the value at that index represents the data associated with the key.

Write a program to implement a Direct Address Table for integer keys ranging from 0 to n-1. You need to support the following operations:

Insert (key, value): Insert a value at the given key.
Search (key): Retrieve the value associated with the given key.
Delete (key): Remove the value associated with the given key.

Input:
The first line contains an integer n (the size of the table).
The second line contains an integer q (the number of queries).
Each of the next q lines contains a query in one of the following formats:
- INSERT key value: Insert value at the position key.
- SEARCH key: Retrieve the value at the position key. If the key does not exist, return ""NOT FOUND"".
- DELETE key: Remove the value at the position key.

Output:
For each SEARCH query, output the value associated with the key or ""NOT FOUND"" if the key does not exist.

Example:
Input:
5
6
INSERT 2 100
INSERT 3 200
SEARCH 2
DELETE 2
SEARCH 2
SEARCH 3

Output:
100
NOT FOUND
200

Explanation:

After INSERT 2 100, the table looks like: [None, None, 100, None, None].
After INSERT 3 200, the table looks like: [None, None, 100, 200, None].
SEARCH 2 retrieves the value 100.
DELETE 2 removes the value at key 2. The table becomes [None, None, None, 200, None].
SEARCH 2 now returns ""NOT FOUND"".
SEARCH 3 retrieves the value 200.
This problem tests the understanding of direct address tables and basic hashing concepts.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

bool isPalindromeHelper(int n, int rev) {
    if (n == 0) return rev;
    return isPalindromeHelper(n / 10, rev * 10 + n % 10);
}

bool isPalindrome(int n) {
    return n == isPalindromeHelper(n, 0);
}

int maxProfit(int n, vector<int>& prices) {
    if (n == 0) return 0;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, prices[i] + maxProfit(n - (i + 1), prices));
    }
    return max_val;
}

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

void directAddressTable(int n) {
    vector<int> table(n, -1);
    int q;
    cin >> q;
    while (q--) {
        string command;
        cin >> command;
        if (command == "INSERT") {
            int key, value;
            cin >> key >> value;
            table[key] = value;
        } else if (command == "SEARCH") {
            int key;
            cin >> key;
            if (table[key] == -1) cout << "NOT FOUND" << endl;
            else cout << table[key] << endl;
        } else if (command == "DELETE") {
            int key;
            cin >> key;
            table[key] = -1;
        }
    }
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "The sum of the digits of " << num << " is " << sumOfDigits(num) << endl;
    cout << "Is " << num << " a palindrome? " << (isPalindrome(num) ? "true" : "false") << endl;
    
    int N = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum profit for rod of length " << N << " is " << maxProfit(N, prices) << endl;
    
    int disks = 2;
    towerOfHanoi(disks, 'A', 'C', 'B');
    
    int tableSize;
    cin >> tableSize;
    directAddressTable(tableSize);
    
    return 0;
}
