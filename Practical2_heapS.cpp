#include <iostream>
using namespace std;

class Heap {
private:
    int heapSize;
public:

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    int parent(int i) {
        return i / 2;
    }

    void maxHeapify(int arr[], int i);

    void buildMaxHeap(int arr[], int len);

    void heapSort(int arr[], int len);

};

void Heap::maxHeapify(int arr[], int i) {
    int left = this->left(i);
    int right = this->right(i);
    int largest = i;
    if (left <= this->heapSize && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= this->heapSize && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest);
    }
}

void Heap::buildMaxHeap(int arr[], int len) {
    heapSize = len;
    for (int i = heapSize / 2; i >= 0; i--) {
        maxHeapify(arr, i);
    }
}

void Heap::heapSort(int arr[], int len) {
    buildMaxHeap(arr, len);
    for (int i = heapSize; i >= 1; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapSize--;
        maxHeapify(arr, 0);
    }
}

int main() {
    int size = 0;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[20];
    cout << "Enter the elements in array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    Heap *heap = new Heap();
    heap->heapSort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    delete heap;
    return 0;
}