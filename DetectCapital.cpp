#include <iostream>
#include <cctype>

using namespace std;

bool detectCapitalUse(string word)
{
    int count = 0;

    if (word.size() == 1)
        return true;

    for (int i = 0; i < word.size(); i++)
    {
        if (isupper(word[i]))
            count++;
    }

    if (count == 0)
        return true;

    else if (count == 1 && isupper(word[0]))
        return true;

    else if (count == word.size() || count == 0)
        return true;

    else
        return false;
}

int main()
{
    string word = "FlaG";
    cout << detectCapitalUse(word) << endl;
}
    