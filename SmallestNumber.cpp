#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int start = 0;
    int end = letters.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target < letters[mid])
            end = mid - 1;

        else
        {
            start = mid + 1;
        }
    }
    return letters[start % letters.size()];
}
int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'c';

    cout << nextGreatestLetter(letters, target) << endl;
    return 0;
}