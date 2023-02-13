#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int n = s.size();
    vector<int> ans;

    for (int i = 0; i + 3 < n; i++)
    {
        string firstThree = s.substr(i, 3);
        sort(firstThree.begin(), firstThree.end());

        if (firstThree == p)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// For 2 strings to be anagrams of each other,
// they should have the same elements with the same frequency.
vector<int> findAnagrams1(string s, string p)
{
    int p_len = p.size();
    int s_len = s.size();

    if (s.size() < p.size())
        return {};

    vector<int> freq(26, 0);
    vector<int> window(26, 0);

    // first window
    for (int i = 0; i < p_len; i++)
    {
        freq[p[i] - 'a']++;
        window[s[i] - 'a']++;
    }

    vector<int> ans;
    if (freq == window)
        ans.push_back(0);

    for (int i = p_len; i < s_len; i++)
    {
        window[s[i - p_len] - 'a']--;
        window[s[i] - 'a']++;

        if (freq == window)
            ans.push_back(i - p_len + 1);
    }
    return ans;
}

int main()
{
    string s = "abab";
    string p = "ab";

    vector<int> res = findAnagrams1(s, p);

    for (int i = 0; i < res.size(); i++)
    {
        cout << i << " ";
    }

    return 0;
}