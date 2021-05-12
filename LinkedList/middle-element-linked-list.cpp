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
    ListNode *middleNode(ListNode *head)
    {

        if ((head == NULL) || (head->next == NULL))
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;
        int i = 1;

        while (fast != NULL)
        {
            i++;
            fast = fast->next;
            if (fast != NULL)
            {
                i++;
                slow = slow->next;
                fast = fast->next;
            }
        }
        // cout<<i<<"       ";
        if (i % 2 != 0)
            return (slow);
        else
            return (slow->next);
    }
};
