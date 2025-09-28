#include <vector>
#include <queue>
using namespace std;

// Do NOT define ListNode here — platform provides it.

struct Compare
{
    bool operator()(ListNode *a, ListNode *b) const
    {
        return a->val > b->val; // min-heap by value
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        for (auto node : lists)
            if (node)
                pq.push(node);

        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
                pq.push(node->next);
        }
        return dummy.next;
    }
};
#ifndef MY_LISTNODE_DEF
#define MY_LISTNODE_DEF

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif // MY_LISTNODE_DEF

// Then the same Solution class as above (or include it from Option A).
