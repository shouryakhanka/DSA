#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void skip(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }

    char ch = up[0];

    if (ch == 'a')
        skip(p, up.substr(1));

    else
        skip(p + ch, up.substr(1));
}

string skipApple(string up)
{
    if (up.empty())
    {
        return "";
    }
    if (up.find("apple") == 0)
    {
        return skipApple(up.substr(5));
    }
    else
    {
        return up[0] + skipApple(up.substr(1));
    }
}

string skipAppNotApple(string up)
{
    if (up.empty())
    {
        return "";
    }
    if ((up.find("app") == 0) && up.find("apple") != 0)
    {
        return skipAppNotApple(up.substr(3));
    }
    else
    {
        return up[0] + skipAppNotApple(up.substr(1));
    }
}

void subSeq(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }

    char ch = up[0];
    subSeq(p + ch, up.substr(1));

    subSeq(p, up.substr(1));
}

// using the vector
vector<string> subSeq2(string p, string up)
{
    if (up.empty())
    {
        vector<string> list;
        list.push_back(p);
        return list;
    }

    char ch = up[0];
    vector<string> left = subSeq2(p + ch, up.substr(1));

    vector<string> right = subSeq2(p, up.substr(1));

    left.insert(left.end(), right.begin(), right.end());
    return left;
}

void subseqAscii(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }
    char ch = up[0];
    int c = static_cast<int>(ch);
    subseqAscii(p + ch, up.substr(1));
    subseqAscii(p, up.substr(1));
    subseqAscii(p + to_string(ch), up.substr(1));
}

// time: O(n * 2 ^ n), space: O(2 ^ n * n)
vector<vector<int>> subset(int arr[], int n)
{
    vector<vector<int>> outer;
    vector<int> inner;
    outer.push_back(inner);
    for (int i = 0; i < n; i++)
    {
        int m = outer.size();
        for (int j = 0; j < m; j++)
        {
            vector<int> newInternal(outer[j]);
            newInternal.push_back(arr[i]);
            outer.push_back(newInternal);
        }
    }
    return outer;
}

vector<vector<int>> subsetDuplicate(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> outer;
    outer.push_back({});
    int start = 0;
    int end = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        start = 0;
        if (i > 0 && arr[i] == arr[i - 1])
        {
            start = end + 1;
        }
        end = outer.size() - 1;

        int n = outer.size();
        for (int j = start; j < n; j++)
        {
            vector<int> internals = outer[j];
            internals.push_back(arr[i]);
            outer.push_back(internals);
        }
    }
    return outer;
}

int main()
{
    vector<int> arr = {1, 2, 2};

    vector<vector<int>> result = subsetDuplicate(arr);
    for (const auto &subset : result)
    {
        for (const auto &element : subset)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}