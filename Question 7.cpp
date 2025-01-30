/*You are given a rod of length N and an array prices[] where prices[i] represents the price of a rod of length i+1. Your task is to determine the maximum profit you can achieve by cutting the rod into smaller lengths and selling the pieces.

Write a recursive function maxProfit(int n, int[] prices) to calculate the maximum profit.

Input: N = 8
prices = [1, 5, 8, 9, 10, 17, 17, 20]
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

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "The sum of the digits of " << num << " is " << sumOfDigits(num) << endl;
    cout << "Is " << num << " a palindrome? " << (isPalindrome(num) ? "true" : "false") << endl;
    
    int N = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum profit for rod of length " << N << " is " << maxProfit(N, prices) << endl;
    
    return 0;
}
