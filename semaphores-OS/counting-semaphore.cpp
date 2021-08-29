#include <bits/stdc++.h>
using namespace std;


struct Process
{
    int pid;
};

struct semaphore
{
    int value;
    queue<Process> q;
};

void P(semaphore s)
{
    s.value -= 1;
    if(s.value < 0)
    {
        q.push(p);
        block();
    }
}

void V(semaphore s)
{
    s.value += 1;
    if(s.value <= 0)
    {
        Process p = q.pop();
        wakeup(p);
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    
    
    
    
    
    
    
    
    return 0;
}
