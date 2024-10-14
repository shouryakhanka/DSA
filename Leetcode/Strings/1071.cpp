#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool valid(string str1, string str2, int k)
{
    int len1 = str1.length(), len2 = str2.length();

    if (len1 % k > 0 || len2 % k > 0)
        return false;

    else
    {
        string base = str1.substr(0, k);
        return str1.replace(0, base.length(), "").empty() && str2.replace(0, base.length(), "").empty();
    }
}

string gcdOfStrings(string str1, string str2)
{
    int len1 = str1.length(), len2 = str2.length();

    for (int i = min(len1, len2); i >= 1; i--)
    {
        if (valid(str1, str2, i))
        {
            return str1.substr(0, i);
        }
    }
    return " ";
}

int main()
{
    string str1 = "LEET", str2 = "CODE";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}