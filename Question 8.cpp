/*The Tower of Hanoi is a classic problem that involves moving disks from one rod to another under certain constraints. There are three rods: source rod (A), destination rod (C), and auxiliary rod (B). The objective is to move N disks from rod A to rod C, following these rules:

Only one disk can be moved at a time.
A disk can only be placed on top of a larger disk or on an empty rod.
Use the auxiliary rod (B) as needed.
Write a recursive function towerOfHanoi(int n, char source, char destination, char auxiliary) to print the sequence of moves required to solve the problem.

Input: N = 2

Output: Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
*/
#include <iostream>
#include <vector>
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
    
    return 0;
}
