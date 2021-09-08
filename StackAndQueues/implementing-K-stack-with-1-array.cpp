#include <bits/stdc++.h>
using namespace std;

class Kstacks
{
    public:
        int *arr;
        int *top;
        int *prev;
        
        int *freespace;                 //stack for free spaces
        int ns, size;
        int cur = 0;
        
        void push(int x, int n)         //push x in nth stack
        {
            if(n < 1 || n > ns)
            {
                return;
            }
            
            arr[cur] = x;
            prev[cur] = top[n];
            top[n] = cur;
            cur++;
        }
        
        void pop(int n)             //pop from nth stack
        {
            top[n] = prev[top[n]];
        }
};


int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    
    int i, j, n, k;
    
    Kstacks obj;
    
    cin>>obj.ns;       //  no. of stacks
    cin>>obj.size;     //  size of each stack
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
