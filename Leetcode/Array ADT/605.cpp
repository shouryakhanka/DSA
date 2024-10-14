#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int res = 0;
    int prev = 0;
    int nxt = 0;

    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0)
        {
            prev = flowerbed[i - 1];
            nxt = flowerbed[i + 1];

            if (i == 0 && nxt == 0)
            {
                res++;
                flowerbed[i] = 1;
            }

            else if (i == flowerbed.size() - 1 && prev == 0)
            {
                res++;
                flowerbed[i] = 1;
            }

            else if (prev == 0 && nxt == 0)
            {
                res++;
                flowerbed[i] = 1;
            }
        }
    }
    if (res >= n)
        return true;
    else
        return false;
}

int main()
{
    vector<int> flowerbed = {0, 0, 1, 0, 1};
    int n = 1;

    cout << canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}