#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> TwoSum(vector<int> &nums, int tar) {  

    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        int first = nums[i];
        int sec = tar - first;     

        if (m.find(sec) != m.end()) {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }

        m[first] = i;  
    }

    return ans;
}

int main() {
    vector<int> arr = {5, 2, 11, 7, 15};
    int tar = 9;

    vector<int> result = TwoSum(arr, tar);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
