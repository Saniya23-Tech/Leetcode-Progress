#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int inv_count = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            inv_count += (mid - i + 1); // key line
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[st + k] = temp[k];
    }

    return inv_count;
}

int mergeSort(vector<int>& arr, int st, int end) {
    if (st >= end)
        return 0;

    int mid = st + (end - st) / 2;

    int leftInv = mergeSort(arr, st, mid);
    int rightInv = mergeSort(arr, mid + 1, end);
    int mergeInv = merge(arr, st, mid, end);

    return leftInv + rightInv + mergeInv;
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};

    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "No. of inversions are: " << ans << endl;

    return 0;
}
