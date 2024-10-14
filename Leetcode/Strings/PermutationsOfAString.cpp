#include <iostream>
#include <set>

using namespace std;

void perm(char S[], int k)
{
    static int A[10] = {0};
    static char Res[10];

    if (S[k] == '\0')
    {
        Res[k] = '\0';
        for (char i : Res)
            cout << i << " ";
    }

    else
    {

        for (int i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = S[i];
                A[i] = 1;
                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void perm2(char S[], int l, int n, set<string> &permutations)
{
    if (l == n - 1)
    {
        string current(S);
        permutations.insert(current);
    }
    else
    {
        for (int i = l; i < n; i++)
        {
            swap(&S[l], &S[i]);
            perm2(S, l + 1, n, permutations);
            swap(&S[l], &S[i]);
        }
    }
}

int main()
{
    char arr[] = "ABC";
    int size = sizeof(arr) / sizeof(arr[0]) - 1; // Subtract 1 to exclude the null terminator
    set<string> permutations;
    // perm(arr, 0);

    perm2(arr, 0, size, permutations);

    for (string perm : permutations)
    {
        cout << perm << endl;
    }

    return 0;
}
