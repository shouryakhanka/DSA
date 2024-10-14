#include <iostream>
#include <vector>

using namespace std;

class CountOddNo
{
public:
    int countOdds(int low, int high)
    {
        int count = 0;

        for (int i = low; i <= high; i++)
        {
            if ((i % 2))
                count++;
        }
        return count;
    }
};

int main()
{
    int low = 8, high = 10;

    CountOddNo count;
    int ans = count.countOdds(low, high);

    cout << ans << endl;

    return 0;
}