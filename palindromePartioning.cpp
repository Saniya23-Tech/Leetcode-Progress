#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
   

bool isPalin(string S) {
    string S2 = S; //Make a copy of string 
    reverse(S2.begin() , S2.end());
    return S2 == S;
}


void getAllParts( string S , vector<vector<string>> &ans,vector<string> &Partitions) {
    //basecase
if(S.size()== 0) {
ans.push_back(Partitions);
return;
}

for (int i=0; i<S.size(); i++) {
string part = S.substr(0, i+1);

if(isPalin(part)) {
    Partitions.push_back(part);
    getAllParts(S.substr(i+1) , ans, Partitions);
    Partitions.pop_back();
}
}
}


vector<vector<string>> palindromePartitioning(string S) {
vector<vector<string>> ans;
vector<string> Partitions;

getAllParts(S, ans, Partitions);
return ans;

}


int main() {
    string S = "aab";
    vector<vector<string>> result = palindromePartitioning(S);

    cout << "All palindrome partitions:\n";
    for(auto &ans : result) {
        cout << "[";
        for(auto &vec : ans) cout<< vec << " ";
        cout<< "]\n";
}
return 0;
}