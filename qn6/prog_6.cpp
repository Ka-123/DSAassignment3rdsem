#include <iostream>

using namespace std;

// This function swaps two numbers in the array
void swapThem(int myNums[], int i, int j) {
    int temp = myNums[i];
    myNums[i] = myNums[j];
    myNums[j] = temp;
}

// Maintenance function for Max-Heap
// I just learned that we start from the parent and check children
void fixDownMax(int myNums[], int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;  // Formula for left child
    int right = 2 * i + 2; // Formula for right child

    // Check if left child is bigger than parent
    if (left < heapSize && myNums[left] > myNums[largest]) {
        largest = left;
    }

    // Check if right child is bigger than the biggest so far
    if (right < heapSize && myNums[right] > myNums[largest]) {
        largest = right;
    }

    // If largest is not the parent, swap and keep fixing down
    if (largest != i) {
        swapThem(myNums, i, largest);
        fixDownMax(myNums, heapSize, largest);
    }
}

// Maintenance function for Min-Heap
void fixDownMin(int myNums[], int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is smaller than parent
    if (left < heapSize && myNums[left] < myNums[smallest]) {
        smallest = left;
    }

    // Check if right child is smaller than the smallest so far
    if (right < heapSize && myNums[right] < myNums[smallest]) {
        smallest = right;
    }

    // If smallest is not the parent, swap and keep fixing down
    if (smallest != i) {
        swapThem(myNums, i, smallest);
        fixDownMin(myNums, heapSize, smallest);
    }
}

// Function to build Max-Heap from bottom-up
void buildMaxHeap(int myNums[], int heapSize) {
    // We start from the last non-leaf node and go up to the root
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        fixDownMax(myNums, heapSize, i);
    }
}

// Function to build Min-Heap from bottom-up
void buildMinHeap(int myNums[], int heapSize) {
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        fixDownMin(myNums, heapSize, i);
    }
}

// Simple function to print the array
void showArray(int myNums[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << myNums[i] << " ";
    }
    cout << endl;
}

int main() {
    // My test array - I chose these random numbers for my assignment
    int testArray[] = {45, 12, 89, 7, 34, 66, 10, 5, 20};
    int heapSize = sizeof(testArray) / sizeof(testArray[0]);

    cout << "Original Array: ";
    showArray(testArray, heapSize);

    // Creating a copy for Min-Heap since building one will change the array
    int minHeapArr[9];
    int maxHeapArr[9];
    
    for(int i = 0; i < heapSize; i++) {
        minHeapArr[i] = testArray[i];
        maxHeapArr[i] = testArray[i];
    }

    cout << "\nBuilding Max-Heap..." << endl;
    buildMaxHeap(maxHeapArr, heapSize);
    cout << "Max-Heap: ";
    showArray(maxHeapArr, heapSize);

    cout << "\nBuilding Min-Heap..." << endl;
    buildMinHeap(minHeapArr, heapSize);
    cout << "Min-Heap: ";
    showArray(minHeapArr, heapSize);

    return 0;
}
