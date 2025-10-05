#include <iostream>
using namespace std;

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {   // outer loop
        bool isSwap = false;          // reset flag for each pass

        for (int j = 0; j < n-i-1; j++) {  // inner loop
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }

        // if no swaps happened → array is already sorted
        if (!isSwap) {
            return;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    bubblesort(arr, n);
    printArray(arr, n);

    return 0;
}
