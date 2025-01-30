/*Write a recursive function to determine if a given natural number
N is a palindrome. A number is a palindrome if it reads the same backward as forward.

Input: 121
Output: true
*/
#include <iostream>
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

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "The sum of the digits of " << num << " is " << sumOfDigits(num) << endl;
    cout << "Is " << num << " a palindrome? " << (isPalindrome(num) ? "true" : "false") << endl;
    return 0;
}
