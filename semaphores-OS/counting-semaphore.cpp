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

void block();
void wakeup(Process p);

void P(semaphore s)
{
    s.value -= 1;
    if (s.value < 0)
    {
        (s.q).push(p);
        block();
    }
}

void V(semaphore s)
{
    s.value += 1;
    if (s.value <= 0)
    {
        Process p = (s.q).front();
        (s.q).pop();
        wakeup(p);
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    semaphore s;
    
    s.q.empty();

    // call P
    //     critical section
    // call V

    return 0;
}
