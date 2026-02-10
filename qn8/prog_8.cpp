#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void myBubbleSort(int myNumbers[], int howMany) {
    int compCount = 0;
    int swapCount = 0;

    for (int i = 0; i < howMany - 1; i++) {
        for (int j = 0; j < howMany - i - 1; j++) {
            
            compCount++;
            
            if (myNumbers[j] > myNumbers[j + 1]) {
                
                int temp = myNumbers[j];
                myNumbers[j] = myNumbers[j + 1];
                myNumbers[j + 1] = temp;
                
                
                swapCount++;
            }
        }
    }

    cout << "\nSorting completed!" << endl;
    cout << "Total Comparisons: " << compCount << endl;
    cout << "Total Swaps: " << swapCount << endl;
}


void showTheList(int theList[], int howMany) {
    for (int i = 0; i < howMany; i++) {
        cout << theList[i] << " ";
    }
    cout << endl;
}

int main() {
    int howMany;
    
    
    srand(time(0));

    cout << "How many random numbers do you want? ";
    cin >> howMany;

    
    int myNumbers[howMany];

    
    for (int i = 0; i < howMany; i++) {
        myNumbers[i] = (rand() % 1000) + 1;
    }

    cout << "\nOriginal List: " << endl;
    showTheList(myNumbers, howMany);

    cout << "\nChoose sorting algorithm (1 for Bubble Sort): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        myBubbleSort(myNumbers, howMany);
    } else {
        cout << "Invalid choice, but I'll do Bubble Sort anyway!" << endl;
        myBubbleSort(myNumbers, howMany);
    }

    cout << "\nSorted List: " << endl;
    showTheList(myNumbers, howMany);

    return 0;
}
