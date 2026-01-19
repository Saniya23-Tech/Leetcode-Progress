#include<iostream>
#include<vector>
using namespace std;

bool knightTour(vector<vector<int>> & grid, int r, int c, int expVal, int n) {
    if(r<0 || c< 0 || r >=n || c>=n || grid[r][c] != expVal) {
        return false;
    }

    if(expVal == n*n-1)  {
        return true;
    }
    bool ans1 = knightTour(grid, r-2, c+1, expVal+1 , n);
    bool ans2 = knightTour(grid, r-1, c+2, expVal+1 , n);
    bool ans3 = knightTour(grid, r+1, c+2, expVal+1 , n);
    bool ans4 = knightTour(grid, r+2, c+1, expVal+1 , n);
    bool ans5 = knightTour(grid, r+2, c-1, expVal+1 , n);
    bool ans6 = knightTour(grid, r+1, c-2, expVal+1 , n);
    bool ans7 = knightTour(grid, r-1, c-2, expVal+1 , n);
    bool ans8 = knightTour(grid, r-2, c-1, expVal+1 , n);
    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;

}

bool checkValidGrid(vector<vector<int>> &grid) {
    int n = grid.size();
    return knightTour(grid, 0, 0, 0, n);
}

int main() {
    vector<vector<int>> grid = { { 0, 11, 16, 5, 20},
                                   {17, 4, 19, 10, 15},
                                   {12, 1, 8, 21, 6},
                                   {3, 18, 23, 14, 9},
                                   {24, 13, 2, 7, 22}
                                 };

                                   if(checkValidGrid(grid)) {
                                    cout<<"valid knight tour" << endl;
                                   } else {
                                        cout<<"invalid knight tour" << endl;
                                    }
                                   }




    
