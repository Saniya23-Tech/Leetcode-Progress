#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>


vector<int> RepeatedValueandMissingValue( vector <vector<int>> &grid  ) {
    vector <int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a , b;  // repeated and Missing value

    int expSum= 0 , actualSum = 0;

    for(int i =0; i<n; i++ ) {
        for(int j=0 ; j<n; j++) {
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()) {
                a= grid[i][j];
                ans.push_back(a);
            }
                            s.insert(grid[i][j]); 
        }
    
    expSum = n*n * (n*n + 1) / 2;
    b= expSum +a-actualSum;
    ans.push_back(b);

return ans;
}

};

int main() {
vector<vector<int>> grid = {{9,1,7} , {8,9,2}, {3,4,6}};
vector <int> result = RepeatedValueandMissingValue(grid);
for(int i =0 ; i< result.size(); i++) {
    cout << result[i] << endl;
}
return 0;
}