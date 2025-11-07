#include <iostream>
using namespace std;

int BinarysearchRecursive(int tar, int arr[], int st, int end) {
    if (st > end) 
        return -1;  // target not found

    int mid = st + (end - st) / 2;

    if (arr[mid] == tar)
        return mid;

    if (tar > arr[mid])
        return BinarysearchRecursive(tar, arr, mid + 1, end);
    else
        return BinarysearchRecursive(tar, arr, st, mid - 1);
}

int main() {
    int arr[] = {3, 5, 6, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tar = 8;

    int result = BinarysearchRecursive(tar, arr, 0, n - 1);

    if (result == -1)
        cout << "Target not found";
    else
        cout << "Target found at index " << result;

    return 0;
}
