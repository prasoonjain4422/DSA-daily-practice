#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
};

struct semaphore
{
    enum value {0, 1};
    queue<Process> q;
};

//  wait
void P(semaphore s)
{
    if (s.value == 1)
    {
        s.value = 0;
    }
    else
    {
        q.push(p);
        sleep();
    }
}

//  signal
void V(semaphore s)
{
    if (s.q.empty())
    {
        s.value = 1;
    }
    else
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
