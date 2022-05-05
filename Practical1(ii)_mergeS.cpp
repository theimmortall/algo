#include <iostream>
#include <climits>
using namespace std;

void merge(int arr[], int l, int m, int r) {
   
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1 + 1], R[n2 + 1];
   
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int comparisons = 0;
    
    int i = 0, j = 0, k = l;
    while (k <= r) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
    }
    cout << "Comparisons: " << comparisons << "\n";
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int main() {
    int n = 0;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Array before sorting\n";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Array after sorting\n";
    printArray(arr, n);

    return 0;
}