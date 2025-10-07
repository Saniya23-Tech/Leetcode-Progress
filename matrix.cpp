#include <iostream>
#include <utility> // for pair
using namespace std;

pair<int, int> linearSearch(int mat[4][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return {i, j};  // Return row and column as a pair
            }
        }
    }
    return {-1, -1};  // If not found
}

int main() {
    int matrix[4][3] = {
        {1, 4, 5},
        {5, 6, 7},
        {7, 8, 9},
        {7, 4, 5}
    };
    int rows = 4; 
    int cols = 3; 

    pair<int, int> position = linearSearch(matrix, rows, cols, 8);

    if (position.first != -1)
        cout << "Element found at Row " << position.first 
             << " and Column " << position.second << endl;
    else 
        cout << "Element not found" << endl;

    return 0;
}
