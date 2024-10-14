#include <iostream>
using namespace std;

int main()
{
    int num1, num2, hcf;

    cout << "Enter the two no.s";
    cin >> num1 >> num2;

    // calc hcf

    int smaller = (num1 < num2) ? num1 : num2;

    for (int i = 1; i <= smaller; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            hcf = i;
    }

    // lcm
    int lcm = (num1 * num2) / hcf;

    cout << "LCM of the numbers" << lcm << endl;
    cout << "HCF of the numbers" << hcf;

    return 0;
}
