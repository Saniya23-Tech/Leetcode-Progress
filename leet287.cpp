#include <iostream>
using namespace std;
#include <vector>


int  findDuplicate(vector <int> &arr) {
    int slow = arr[0] , fast= arr[0];


    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }  while(slow != fast);

    slow = arr[0];
    while( slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;

    }



    int main() {
        vector <int> arr =  {8,9,4,2,2,6};
            int result = findDuplicate(arr);

            cout << "duplicate number is:" <<  result << endl;
            }

    



