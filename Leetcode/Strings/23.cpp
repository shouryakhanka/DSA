#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class FindTheIndex
{
public:
    int strStr10(string haystack, string needle)
    {
        int n = needle.length();

        // create an input string stream object from the string
        istringstream iss(haystack);

        char chr;
        vector<char> vec;

        while (iss >> chr)
        {
            vec.push_back(chr);
        }

        int i = 0;
        while (i < vec.size())
        {
            int j = 0;
            while (j < n && vec[i + j] == needle[j])
            {
                j++;
            }

            if (j == n)
            {
                return i;
            }

            i++;
        }

        return -1;
    }

    int strStr(string haystack, string needle)
    {
        int n = needle.length();

        // create an input string stream object from the string
        istringstream iss(haystack);

        char chr;
        vector<char> vec;

        while (iss >> chr)
        {
            vec.push_back(chr);
        }

        istringstream isss(needle);

        vector<char> need;

        while (isss >> chr)
        {
            need.push_back(chr);
        }

        int j;
        for (int i = 0; i < vec.size(); i++)
        {
            for (j = 0; j < need.size(); j++)
            {
                if (need[j] == vec[j])
                    continue;
            }

            if (j == need.size() - 1)
                return i;
        }
        return -1;
    }

    // time: O((m - n + 1) * n)), space: O(1)
    int strStr2(string haystack, string needle)
    {
        int n = needle.length();
        int m = haystack.length();

        if (n == 0)
        {
            return 0;
        }

        for (int i = 0; i <= m - n; i++)
        {
            bool found = true;
            for (int j = 0; j < n; j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return i;
            }
        }

        return -1;
    }

    int strStr3(string haystack, string needle)
    {
        int n1 = haystack.size();
        int n2 = needle.size();

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {

                if (haystack[i] == needle[j])
                {
                    if (i == n2 - 1 && j == n2 - 1)
                    {
                        return i - n2 + 1;
                    }
                    i++;
                    continue;
                }
                else
                {
                    j = 0;
                }
            }
        }
        return -1;
    }
};

int main()
{
    FindTheIndex find;

    string haystack = "leetleetcode";
    string needle = "leetcode";

    cout << find.strStr2(haystack, needle);

    return 0;
}
