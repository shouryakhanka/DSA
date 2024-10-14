#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        vector<int> res;
        int length = 0;

        while (p)
        {
            length++;
            res.push_back(p->val);
            p = p->next;
        }

        int j = length - 1;
        int i;

        for (i = 0; i < length / 2; i++)
        {
            if (res[i] != res[j])
            {
                return false;
            }
            j--;
        }

        return true;
    }


        bool isPalindrome2(ListNode *head)
        {
            ListNode *fast = head;
            ListNode *slow = head;

            while (fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }

            ListNode *q = slow;

            ListNode *r = head;

            while (r->next != slow)
            {
                r = r->next;
            }

            ListNode *p = q->next;

            while (q)
            {
                q->next = r;
                r->next = NULL;

                r = q;
                q = p;
                if(p)
                p = p->next;
            }

            p = head;

            while (p)
            {
                if (p->val != r->val)
                {
                    return false;
                }

                p = p->next;
                r = r->next;
            }

            return true;
        }
    
int main()
{
   
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << isPalindrome2(head);
    return 0;
}