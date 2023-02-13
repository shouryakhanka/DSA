#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    vector<int> orderMap(26, 0);
    for (int i = 0; i < order.length(); i++)
    {
        orderMap[order[i] - 'a'] = i;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            // If we do not find a mismatch letter between words[i] and words[i + 1],
            // we need to examine the case when words are like ("apple", "app").
            if (j >= words[i + 1].length())
                return false;

            if (words[i][j] != words[i + 1][j])
            {
                int currentWordChar = words[i][j] - 'a';
                int nextWordChar = words[i + 1][j] - 'a';
                if (orderMap[currentWordChar] > orderMap[nextWordChar])
                    return false;
                // if we find the first different letter and they are sorted,
                // then there's no need to check remaining letters
                else
                    break;
            }
        }
    }
    return true;
}

int main()
{
    string order = "abcdefghijklmnopqrstuvwxyz";

    vector<string> words = {"apple", "app"};

    cout << isAlienSorted(words, order) << endl;
}
