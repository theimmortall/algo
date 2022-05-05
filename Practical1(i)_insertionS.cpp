#include <iostream>
using namespace std;

template <typename T>
void printArray(T arr[], int n);

template <typename T>
void insertionSort(T arr[], int n) {
    T key = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
       
        int comp = 0;
        while (j >= 0 && arr[j] > key) {
            comp += 1;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        if (j >= 0) {
            comp += 1;
        }
        cout << "\nIteration " << i << "\n";
        cout << "Comparisons: " << comp << "\n";
        printArray(arr, n);
    }
}

template <typename T>
void printArray(T arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int main() {
    int n = 0;
    cout << "Enter the size of array:: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements::\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\nArray before sorting\n";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "\nArray after sorting\n";
    printArray(arr, n);

    return 0;
}