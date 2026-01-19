#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end ) {
    int pivot = arr[end];
    int idx = st -1; // index of smaller element 

    for(int j=st; j<=end-1; j++) {
        if(arr[j] < pivot) {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]); //placing pivot at right position
    return idx;

}

void quicksort(vector<int> &arr, int st, int end) {
    if(st < end) {
      int pivIdx =  partition(arr, st, end);
      quicksort(arr, st, pivIdx -1); // left half
      quicksort(arr, pivIdx + 1, end); // right half

    }

}

int main() {
    vector<int> arr = {12, 31, 35,  8, 32, 17};
    quicksort(arr, 0, arr.size() - 1);

    for( int val : arr) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}