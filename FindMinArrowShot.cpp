#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> &x, vector<int> &y)
{
    return (x[1] < y[1]);
}

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() == 0)
        return 1;

    if (points.size() == 1)
        return 1;

    sort(points.begin(), points.end(), comp);

    int arrows = 1;
    int prev = points[0][1];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][1] <= prev)
            continue;

        arrows++;
        prev = points[i][1];
    }
    return arrows;
}

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    cout << findMinArrowShots(points) << endl;

    return 0;
}