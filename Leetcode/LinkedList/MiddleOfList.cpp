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

class Solution
{
public:

// time complexity: O(n)
// space complexity: O(n)
    ListNode *middleNode(ListNode *head)
    {
        ListNode *p = head;
        vector<ListNode*> res;
        int length = 0;

        while (p)
        {
            length++;
            res.push_back(p);
            p = p->next;
        }

        return res[length / 2];
    }

// Amazon, microsoft
// two pointer approach: end pointer move by 2 and middle pointer by 1
// at the end of the list our middle pointer will be in its right place
// time: O(n/2)
// space: O(1)
// Floyd’s cycle finding algorithm or Hare-Tortoise algorithm

    ListNode* middleNode2(ListNode* head) {
        ListNode* end = head;
        ListNode* middle = head;

        while(end && end->next) {
            end = end->next->next;
            middle = middle->next;
        }

        return middle;
    }


        ListNode* middleNode3(ListNode* head) {
                ListNode* temp = head;

        int length = 0;

        while(temp) {
            length++;
            temp = temp->next;
        }

temp = head;

        for(int i = 0; i<length / 2; i++) {
            temp = temp->next;
    
        }
    return temp;
    }

};
int main()
{
    return 0;
}