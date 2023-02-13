#include <iostream>
using namespace std;

int val;
int k;
int count = 0;

DataStream(int value, int k)
{
    val = value;
    k = k;
}

bool consec(int num)
{
    if (val == num)
    {
        count++;
    }

    else
    {
        count = 0;
    }

    return count >= k;
}

int main()
{
    [ "DataStream", "consec", "consec", "consec", "consec" ]

        DataStream *obj = new DataStream(value, k);
    bool param_1 = obj->consec(num);
    return 0;
}