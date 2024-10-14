// https://leetcode.com/problems/word-pattern/

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<string, int> s2i;
    unordered_map<char, int> p2i;

    int n = pattern.size();

    istringstream in(s);
    string word;

    int i = 0;

    for (i = 0; in >> word; i++)
    {
        if (i == n || p2i[pattern[i]] != s2i[word])
            return false;

        p2i[pattern[i]] = s2i[word] = i + 1;
    }

    return i == n;
}

int main()
{
    string pattern = "aaaa";
    string s = "dog cat cat fish";

    cout << wordPattern(pattern, s) << endl;

    return 0;
}