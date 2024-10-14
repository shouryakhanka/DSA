#include <iostream>
using namespace std;

int Toh(int n, int A, int B, int C)
{
    if (n > 0)
    {

        Toh(n - 1, A, C, B);
        cout << A << " " << C << endl;
        Toh(n - 1, B, A, C);
    }
}

int main()
{
    Toh(3, 1, 2, 3);
    return 0;
}