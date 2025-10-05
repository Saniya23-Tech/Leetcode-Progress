#include <iostream>
#include <string>
using namespace std;

bool ispalindrome(string S) {
    int st = 0, end = S.size() - 1;
    while (st < end) {
        if (S[st] != S[end]) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);   // ✅ use getline for whole line input (with spaces)

    if (ispalindrome(str)) {
        cout << "Yes, it is a palindrome." << endl;
    } else {
        cout << "No, it is not a palindrome." << endl;
    }

    return 0;
}
