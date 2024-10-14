#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// this is going to give tle because of the exponential time complexity
unordered_set<string> set;

bool isConcat(const std::string &word)
{
    int len = word.length();
    for (int i = 1; i < len; i++)
    {
        std::string suffix = word.substr(i);
        if (set.count(word.substr(0, i)) &&
            (set.count(suffix) || isConcat(suffix)))
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> findA11ConcatenatedWordsInADict(std::vector<std::string> &words)
{
    std::vector<std::string> res;
    if (words.size() == 0)
        return res;
    set.clear();
    for (const auto &word : words)
    {
        set.insert(word);
    }
    for (const auto &word : words)
    {
        if (isConcat(word))
            res.push_back(word);
    }
    return res;
}

// dynamic programming
std::vector<int> cache;

bool isConcat1(const std::string &word, int start)
{
    if (cache[start] != -1)
        return cache[start];

    int len = word.length();
    for (int i = start + 1; i < len; i++)
    {
        std::string suffix = word.substr(i);
        if (set.count(word.substr(start, i - start)) &&
            (set.count(suffix) || isConcat1(word, i)))
        {
            cache[start] = 1;
            return true;
        }
    }
    cache[start] = 0;
    return false;
}

std::vector<std::string> findA11ConcatenatedWordsInADict1(std::vector<std::string> &words)
{
    std::vector<std::string> res;
    if (words.size() == 0)
        return res;
    set.clear();
    for (const auto &word : words)
    {
        set.insert(word);
    }
    for (const auto &word : words)
    {
        cache.clear();
        cache.resize(word.length(), -1);
        if (isConcat1(word, 0))
            res.push_back(word);
    }
    return res;
}

int main()
{
    vector<string> words = {"cat", "dog", "catdog"};

    vector<string> ans = findA11ConcatenatedWordsInADict1(words);

    for (string i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
