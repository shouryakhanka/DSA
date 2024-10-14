#include <iostream>
using namespace std;

bool checkIfPangram(string sentence)
{
    int len = sentence.length();
    bool arr[26];

    for (int i = 0; i < len; i++)
    {
        arr[sentence.at(i) - 'a'] = true;
    }

    for (char c : arr)
    {
        if (!c)
            return false;
    }
    return true;
}

int main()
{
    string sentence = "leetcode";
    cout << checkIfPangram(sentence);
    return 0;
}