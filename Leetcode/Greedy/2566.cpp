#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_diff(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());

    int max_num = 0, min_num = 0;
    bool max_set = false, min_set = false;
    for (int i = 0; i < digits.size(); i++) {
        for (int j = 0; j < 10; j++) {
            if (j == digits[i]) {
                continue;
            }
            vector<int> new_digits = digits;
            new_digits[i] = j;
            int new_num = 0;
            for (int k = 0; k < new_digits.size(); k++) {
                new_num += new_digits[k] * pow(10, new_digits.size() - k - 1);
            }
            if (!max_set || new_num > max_num) {
                max_num = new_num;
                max_set = true;
            }
            if (!min_set || new_num < min_num) {
                min_num = new_num;
                min_set = true;
            }
        }
    }
    return max_num - min_num;
}

int main() {
    int n;
    cin >> n;
    cout << max_diff(n) << endl;
    return 0;
}
