#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAlloweddistance) {
    int cows = 1, lastStallPos = arr[0]; // first cow at first stall

    for (int i = 1; i < N; i++) {  // start from second stall
        if (arr[i] - lastStallPos >= minAlloweddistance) {
            cows++;
            lastStallPos = arr[i];
        }
        if (cows == C) {
            return true; // placed all cows
        }
    }
    return false; // couldn't place all cows
}

int getDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end()); // sort stall positions

    int st = 1, end = arr[N-1] - arr[0], ans = -1;
    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, N, C, mid)) {
            ans = mid;      // store valid answer
            st = mid + 1;   // try for larger distance
        } else {
            end = mid - 1;  // try smaller distance
        }
    }
    return ans;
}

int main() {
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout << getDistance(arr, N, C) << endl;
    return 0;
}
