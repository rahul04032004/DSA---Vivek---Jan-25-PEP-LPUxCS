/*Write a recursive function to calculate the sum of the digits of a given positive integer.

Input:
Enter a positive integer: 12345

Output:
The sum of the digits of 12345 is 15.
*/
#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "The sum of the digits of " << num << " is " << sumOfDigits(num) << endl;
    return 0;
}
