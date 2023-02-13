#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> values;

SummaryRanges()
{
}

void addNum(int value)
{
    values.insert(value);
}

vector<vector<int>> getIntervals()
{
    if (values.empty())
        return {};

    vector<vector<int>> intervals;
    int left = -1, right = -1;

    for (int value : values)
    {
        if (left < 0)
        {
            left = right = value;
        }
        else if (value = right + 1)
        {
            right = value;
        }
        else
        {
            intervals.push_back({left, right});
            left = right = value;
        }
    }
    intervals.push_back({left, right});
    return intervals;
}

int main()
{
    SummaryRanges *obj = new SummaryRanges();
    obj->addNum(value);
    vector<vector<int>> param_2 = obj->getIntervals();

    return 0;
}