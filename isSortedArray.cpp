#include <iostream>
using namespace std;
#include<vector>

bool isSorted(vector<int> arr, int n) {
   if(n==1 || n==0) {
    return true;
   }

   return arr[n-1] >= arr[n-2] && isSorted(arr, n-1); // here we are checking in the array the last element is sorted or not then we will check for other
}

int main() {
   vector<int> arr= {1,2,3,4,5};
   cout<< isSorted(arr , arr.size()) << endl;
   return 0;

}