#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int srow = 0, erow = m - 1, scol = 0, ecol = n - 1;
    vector<int> ans;

    while (srow <= erow && scol <= ecol) {

        // top row
        for (int j = scol; j <= ecol; j++) {
            ans.push_back(mat[srow][j]);
        }

        // right column
        for (int i = srow + 1; i <= erow; i++) {
            ans.push_back(mat[i][ecol]);
        }

        // bottom row (only if there is more than one row)
        if (srow < erow) {
            for (int j = ecol - 1; j >= scol; j--) {
                ans.push_back(mat[erow][j]);
            }
        }

        // left column (only if there is more than one column)
        if (scol < ecol) {
            for (int i = erow - 1; i > srow; i--) {
                ans.push_back(mat[i][scol]);
            }
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 7},
        {13, 12, 24, 15}
    };

    vector<int> result = spiralOrder(mat);

    cout << "Spiral order: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
