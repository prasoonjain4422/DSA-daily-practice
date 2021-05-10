
class Solution
{
public:
    //Function to remove a loop in the linked list.
    Node *firstNodeOfLoop(Node *head)
    {

        unordered_set<Node *> s;
        s.insert(head);

        while (head != NULL)
        {
            if (s.find(head->next) != s.end())
            {
                return (head->next);
            }
            head = head->next;
            s.insert(head);
        }
    }
};

// { Driver Code Starts.
