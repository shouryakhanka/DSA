#include <iostream>
using namespace std;

void Nto1(int n)
{
    if (n == 0)
        return;

    Nto1(n - 1);

    cout << n << endl;
}

int main()
{
    Nto1(5);
    return 0;
}