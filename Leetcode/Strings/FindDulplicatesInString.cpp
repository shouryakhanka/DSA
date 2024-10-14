#include <iostream>
#include <cstring>

using namespace std;

void findDulplicate2()
{
    char A[] = "khanka";
    int H[26];
    memset(H, 0, sizeof(H));

    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            cout << static_cast<char>(i + 97) << endl;
            cout << H[i] << endl;
        }
    }
}

void findDulplicate1()
{
    char A[] = "basketball";
    long int h = 0, x = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << A[i] - 97;

        if ((h & x) > 0)
        {
            cout << A[i] << " is the dulplicate element\n";
        }
        else
        {
            h = x | h;
        }
    }
}

int main()
{
    findDulplicate2();

    return 0;
}