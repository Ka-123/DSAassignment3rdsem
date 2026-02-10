#include <iostream>

using namespace std;


void swapThem(int myNums[], int i, int j) {
    int temp = myNums[i];
    myNums[i] = myNums[j];
    myNums[j] = temp;
}


 fixDownMax(int myNums[], int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    
    if (left < heapSize && myNums[left] > myNums[largest]) {
        largest = left;
    }

    
    if (right < heapSize && myNums[right] > myNums[largest]) {
        largest = right;
    }

    
    if (largest != i) {
        swapThem(myNums, i, largest);
        fixDownMax(myNums, heapSize, largest);
    }
}

void fixDownMin(int myNums[], int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < heapSize && myNums[left] < myNums[smallest]) {
        smallest = left;
    }


    if (right < heapSize && myNums[right] < myNums[smallest]) {
        smallest = right;
    }


    if (smallest != i) {
        swapThem(myNums, i, smallest);
        fixDownMin(myNums, heapSize, smallest);
    }
}


void buildMaxHeap(int myNums[], int heapSize) {
    
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        fixDownMax(myNums, heapSize, i);
    }
}


void buildMinHeap(int myNums[], int heapSize) {
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        fixDownMin(myNums, heapSize, i);
    }
}


void showArray(int myNums[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << myNums[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int testArray[] = {45, 12, 89, 7, 34, 66, 10, 5, 20};
    int heapSize = sizeof(testArray) / sizeof(testArray[0]);

    cout << "Original Array: ";
    showArray(testArray, heapSize);

    
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
