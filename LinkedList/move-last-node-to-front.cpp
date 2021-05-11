// { Driver Code Starts
using namespace std;
#include <bits/stdc++.h>

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    void lastToFront( Node *head) 
    {
        
        if((head == NULL)||(head->next == NULL))
            return;
        
        Node *cur = head;
        Node *nex = head->next;
        
        while((nex->next) != NULL)
        {
            cur = nex;
            nex = nex->next;
        }
        
        cur->next = NULL;
        nex->next = head;
        
        return;
    }
};


// { Driver Code Starts.
