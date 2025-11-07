#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;  

void getAllCombinations(vector<int> &arr, int idx, int tar,
                        vector<vector<int>> &ans, vector<int> &combin) {
    //base case
    if (tar == 0) {
        if (s.find(combin) == s.end()) {  // check if combination is new
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    if (idx >= arr.size() || tar < 0)
        return;

    combin.push_back(arr[idx]);
    getAllCombinations(arr, idx, tar - arr[idx], ans, combin);  
    combin.pop_back();  // backtrack

    getAllCombinations(arr, idx + 1, tar, ans, combin);
}

vector<vector<int>> CombinationSum(vector<int> &arr, int tar) {
    vector<vector<int>> ans;
    vector<int> combin;
    getAllCombinations(arr, 0, tar, ans, combin);
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 5, 7};
    int tar = 7;

    vector<vector<int>> result = CombinationSum(arr, tar);

    cout << "All Combinations:\n";
    for (auto &ans : result) {
        cout << "[ ";
        for (int num : ans)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
