#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int i, val = 0;

    if (ruleKey == "type")
        i = 0;
    if (ruleKey == "color")
        i = 1;
    if (ruleKey == "name")
        i = 2;

    for (int j = 0; j < items.size(); j++)
    {
        if (items[j][i] == ruleValue)
            val++;
    }

    return val;
}

int main()
{
    vector<vector<string>> items = {{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}};
    string ruleKey = "color";
    string ruleValue = "silver";

    cout << countMatches(items, ruleKey, ruleValue);
    return 0;
}