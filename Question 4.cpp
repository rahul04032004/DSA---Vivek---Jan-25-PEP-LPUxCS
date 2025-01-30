#include <iostream>
using namespace std;

const int SIZE = 10;

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to reverse the array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

// Function to check if the array is sorted in ascending order
bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to find the maximum and minimum elements
void findMinMax(int arr[], int size, int &min, int &max) {
    min = max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

int main() {
    int arr[SIZE];
    
    // User input
    cout << "Enter " << SIZE << " integer values for the array: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Original Array\n";
        cout << "2. Reverse and Display Array\n";
        cout << "3. Check if Array is Sorted\n";
        cout << "4. Find Maximum and Minimum\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Original Array: ";
                displayArray(arr, SIZE);
                break;
            case 2:
                reverseArray(arr, SIZE);
                cout << "Reversed Array: ";
                displayArray(arr, SIZE);
                reverseArray(arr, SIZE); // Reverse again to restore
                break;
            case 3:
                if (isSorted(arr, SIZE)) {
                    cout << "The array is sorted in ascending order." << endl;
                } else {
                    cout << "The array is NOT sorted." << endl;
                }
                break;
            case 4:
                int min, max;
                findMinMax(arr, SIZE, min, max);
                cout << "Minimum Element: " << min << ", Maximum Element: " << max << endl;
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}
