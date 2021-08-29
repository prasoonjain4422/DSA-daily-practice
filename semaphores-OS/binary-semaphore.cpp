#include <bits/stdc++.h>

#include <sys/wait.h>
#include <unistd.h>

using namespace std;

// enum dt
// {
//     zero,
//     one
// };

// struct Process
// {
//     int pid;
// };

// struct semaphore
// {
//     dt value = zero;
//     queue<Process> q;
// };

// void sleep();
// void wakeup(Process p);

// //  wait
// void P(semaphore s)
// {
//     if (s.value == one)
//     {
//         s.value = zero;
//     }
//     else
//     {
//         // s.q.push(p);
//         // sleep();
//     }
// }

// //  signal
// void V(semaphore s)
// {
//     if (s.q.empty())
//     {
//         s.value = one;
//     }
//     else
//     {
//         Process p = s.q.front();
//         s.q.pop();
//         wakeup(p);
//     }
// }

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // call P
    //     critical section
    // call V

    fork();
    fork();

    cout << "jdh" << endl;

    return 0;
}
