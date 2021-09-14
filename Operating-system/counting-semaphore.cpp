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

void sleep();
void wakeup(Process p);

void P(semaphore s, Process p)
{
    s.value -= 1;
    if (s.value < 0)
    {
        (s.q).push(p);
        sleep();
    }
}

void V(semaphore s)
{
    if (s.q.empty())
    {
        s.value += 1;
    }
    // if (s.value <= 0)
    else
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

    // call P
    //     critical section
    // call V

    return 0;
}
