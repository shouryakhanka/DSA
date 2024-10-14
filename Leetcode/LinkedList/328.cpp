#include<iostream>
#include<vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

void display(ListNode* temp) {
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
    
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        ListNode* p = odd;

        while(p && p->next) {
            p = p->next->next;
        }

        ListNode* q = head->next;
        p->next = q;


        while(q) {
            q = q->next->next;
        }

        return odd;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    ListNode* ans = sol.oddEvenList(head);

    sol.display(ans);

 return 0;
}