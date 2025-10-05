#include <iostream>
using namespace std;

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) { 
        int curr = arr[i];       // store value to insert
        int prev = i - 1;        // start comparing from previous element

        // shift elements greater than curr to the right
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;    // insert curr at correct position
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

    insertionsort(arr, n);
    printArray(arr, n);

    return 0;
}
