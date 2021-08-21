#include <bits/stdc++.h>

using namespace std;

class Encap
{
        
    private:
        int ppid;
    
    public:
        int pid;
        
        void fillPid(int x)
        {
            pid = x;
        }
        
        void fillPpid(int x)
        {
            ppid = x;
        }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    
    
    Encap obj;
    obj.fillPid(25);
    obj.fillPpid(225);
    
    cout << obj.pid << endl;
    // cout << obj.ppid << endl;

    return 0;
}
