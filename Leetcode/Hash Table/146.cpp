#include <iostream>
#include <unordered_map>
using namespace std;

// google, facebook, microsoft, amazon, uber, bloomberg, linkedin
// can we approach this problem using the arrays i.e. linear TC
// a better approach can be to use hashmap and DLL
class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;

        node *prev;
        node *next;

        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int cap;
    unordered_map<int, node *> m;

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *existing = m[key];
            m.erase(key);
            deletenode(existing);
        }

        if (m.size() == cap)
        {
            m.erase(tail->prev->val);
            deletenode(tail->prev);
        }

        addnode(
    };

    int main()
    {
        LRUCache *obj = new LRUCache(capacity);
        int param_1 = obj->get(key);
        obj->put(key, value);

        return 0;
    }
