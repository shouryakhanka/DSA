#include <iostream>
#include <vector>
using namespace std;

class StringCompression
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        int j = 0;
        int newLen = 0;
        int n = chars.size();

        while (i < n)
        {
            j = i;

            while (j < n && chars[j] == chars[i])
            {
                j++;
            }

            chars[newLen++] = chars[i];

            if (j - i > 1)
            {
                for (char c : to_string(j - i))
                {
                    chars[newLen++] = c;
                }
            }
            i = j;
        }
        return newLen;
    }
};

int main()
{
    StringCompression str;

    vector<char> chars = {"a", "a", "b", "b", "c", "c", "c"};
    cout << str.compress(chars) << endl;

    return 0;
}