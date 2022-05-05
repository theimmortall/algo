#include <iostream>
using namespace std;

// Function to find maximum number
int getMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int divisor) {
    int result[n];
    int frequency[10] = {0};

    // Store frequency of numbers in frequency[]
    for (int i = 0; i < n; i++) {
        frequency[(arr[i] / divisor) % 10]++;
    }

    
    for (int j = 1; j < 10; j++) {
        frequency[j] += frequency[j - 1];
    }

    // Put the elements into their correct position
    for (int i = n - 1; i >= 0; i--) {
        result[frequency[(arr[i] / divisor) % 10] - 1] = arr[i];
        frequency[(arr[i] / divisor) % 10]--;
    }

  
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

void radixSort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int max = getMaximum(arr, n);

    // Perform counting sort for every digit.
    // Whole array of numbers is passed
    // instead of passing the individual digits.
    // Also divisor is passed so that digits could be extracted.
    // Divisor is 10^i where i is current digit number
    for (int divisor = 1; max / divisor > 0; divisor *= 10) {
        countSort(arr, n, divisor);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "\nEnter the elements in array\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "\nArray after sorting\n";
    print(arr, n);
    return 0;
}