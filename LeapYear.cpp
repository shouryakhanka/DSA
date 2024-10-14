#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the year";
    int year;

    cin >> year;

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        cout << "It is a leap year";

    else
        cout << "Not a leap year";

    return 0;
}