#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(vector<char> &str, vector<char> &ans, int i, vector<vector<char>> &allSubsets) {
    if (i == str.size()) {
        allSubsets.push_back(ans);
        return;
    }

    // Include
    ans.push_back(str[i]);
    getAllSubsets(str, ans, i + 1, allSubsets);

    // Exclude
    ans.pop_back();
    getAllSubsets(str, ans, i + 1, allSubsets);
}

vector<vector<char>> subsets(vector<char> &str) {
    vector<vector<char>> allSubsets;
    vector<char> ans;
    getAllSubsets(str, ans, 0, allSubsets);
    return allSubsets;
}

int main() {
    vector<char> str = {'a', 'b', 'c'};
    vector<vector<char>> result = subsets(str);

    cout << "All subsets:\n";
    for (auto &subset : result) {
        cout << "[ ";
        for (char c : subset) cout << c << " ";
        cout << "]\n";
    }

    return 0;
}
