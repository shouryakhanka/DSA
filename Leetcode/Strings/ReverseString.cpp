#include <iostream>
using namespace std;

void Reverse1()
{
    int i, j;
    char str[] = "shourya";
    char B[7];

    for (i = 0; str[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = str[i];
    }
    B[j] = '\0';

    for (auto i : B)
    {
        cout << i << " ";
    }
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse2()
{
    char str[] = "khanka";
    int j;

    for (j = 0; str[j] != '\0'; j++)
    {
    }

    int i = 0;
    j = j - 1;

    for (int i = 0; i < j; i++, j--)
    {
        swap(&str[i], &str[j]);
    }

    for (auto i : str)
    {
        cout << i << " ";
    }
}

int main()
{
    // Reverse1();
    Reverse2();

    return 0;
}