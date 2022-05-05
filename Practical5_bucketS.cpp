#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float> arr, int size) 
{
    int key = 0, j = 0;
    for (int i = 1; i < size; i++) 
	{
        key = arr[i];
        j = i - 1;
       
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
   
    vector<float> buckets[n];

    
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], buckets[i].size());
    }

    
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void print(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    float arr[n];
    cout << "\nEnter the elements in array\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }

    bucketSort(arr, n);

    cout << "\nArray after sorting\n";
    print(arr, n);
    return 0;
}