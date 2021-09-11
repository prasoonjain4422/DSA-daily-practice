#include <bits/stdc++.h>
using namespace std;

// we have to do double recursion

void insert_bottom(stack<int> s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    
    int i = s.top();
    s.pop();
    
    insert_bottom(s, x);
    s.push(i);
}

void reverse(stack<int> s)
{
    if(s.empty())
        return;
    
    int x = s.top();
    s.pop();
    reverse(s);
    
    insert_bottom(s, x);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, k, d = 0;
    
    
    
    
    
    
       
        
    
    
    
    
    return 0;
}
