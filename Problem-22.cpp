/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        // Dummy node to handle edge cases smoothly
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroupEnd = &dummy;

        while (true)
        {
            // Step 1: Check if there are k nodes ahead
            ListNode *kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++)
            {
                kth = kth->next;
            }
            if (!kth)
                break; // Not enough nodes left

            // Step 2: Reverse k nodes
            ListNode *groupStart = prevGroupEnd->next;
            ListNode *curr = groupStart->next;

            for (int i = 1; i < k; i++)
            {
                groupStart->next = curr->next;
                curr->next = prevGroupEnd->next;
                prevGroupEnd->next = curr;
                curr = groupStart->next;
            }

            // Step 3: Move prevGroupEnd to the end of this reversed group
            prevGroupEnd = groupStart;
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
