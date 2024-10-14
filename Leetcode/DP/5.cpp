#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int lo, maxLen;

public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) 
            return s;

        lo = 0;
        maxLen = 0;

        for (int i = 0; i < len - 1; i++) {
            extendPalindrome(s, i, i);   // assume odd length, try to extend palindrome as much as possible
            extendPalindrome(s, i, i + 1); // assume even length
        }
        return s.substr(lo, maxLen);
    }

private:
    void extendPalindrome(const string& s, int j, int k) {
        while (j >= 0 && k < s.length() && s[j] == s[k]) {
            j--;
            k++;
        }
        if (maxLen < k - j - 1) {
            lo = j + 1;
            maxLen = k - j - 1;
        }
    }
};

int main() {
    Solution sol;
    string s = "babad";
    string res = sol.longestPalindrome(s);

    cout << res << endl;
    return 0;
}