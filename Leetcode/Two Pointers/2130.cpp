#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // space: O(1), time: O(n)
    int pairSum(ListNode *head)
    {

        ListNode *slow = head, *fast = head;
        int maxval = 0;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL, *nextNode = NULL;
        // reversing the second part of linked list

        while (slow)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // calculating the maximum value
        while (prev)
        {
            maxval = max(maxval, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        return maxval;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << sol.pairSum(head) << endl;
    return 0;
}