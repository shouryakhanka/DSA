#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // time: O(n + e), space: O(n)
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<int> inDegree(n, 0);
        for (const auto &e : edges)
        {
            inDegree[e[1]]++;
        }

        std::vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    int n = 6;
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};

    std::vector<int> result = solution.findSmallestSetOfVertices(n, edges);

    std::cout << "Vertices: ";
    for (int vertex : result)
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}
