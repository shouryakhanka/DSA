#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The code starts by initializing a result vector ans, which will store the digits of the sum of the input array and the integer k. It also initializes two indices i and j, which will be used to traverse the input array and the integer k, respectively. It also initializes a carry variable carry, which will be used to handle the carry from one digit to the next.

// The code then enters a loop that runs as long as there are digits to add or carry. The loop checks if there are digits to add from the input array, the integer k, or the carry. If there are, it retrieves the corresponding digits and adds them together, along with the carry. It then appends the least significant digit of the sum to the result vector ans, and sets the carry to the most significant digit of the sum.

// The loop then moves to the next digit of the input array and the integer k, and increments the index for the integer k. This process continues until there are no more digits to add or carry.

// After the loop completes, the code reverses the result vector ans to obtain the digits in the correct order, and returns it as the final result.

class AddToArrayForm
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> ans;                          // initialize the result vector
        int n = num.size(), i = n - 1, carry = 0; // initialize the indices and the carry
        int x = k, j = 0;                         // initialize the integer to be added and the index for it
        while (x > 0 || i >= 0 || carry > 0)
        {                                // loop while there are digits to add or carry
            int a = i >= 0 ? num[i] : 0; // get the i-th digit of the input array, or 0 if i is out of bounds
            int b = x % 10;              // get the j-th digit of the integer to be added
            int sum = a + b + carry;     // add the digits and the carry
            ans.push_back(sum % 10);     // append the least significant digit to the result vector
            carry = sum / 10;            // set the carry to the most significant digit
            i--;                         // move to the next digit of the input array
            x /= 10;                     // move to the next digit of the integer to be added
            j++;                         // increment the index for the integer to be added
        }
        reverse(ans.begin(), ans.end()); // reverse the result vector
        return ans;                      // return the result
    }
};

int main()
{
    AddToArrayForm add;

    vector<int> num = {1, 2, 0, 0}, k = 34 vector<int> ans = add.addToArrayForm(num, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}