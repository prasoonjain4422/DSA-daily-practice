#include <bits/stdc++.h>

using namespace std;

class Encap
{
    private:
        int ppid;
    
    public:
        int pid;
        
        void fillPpid(int x)
        {
            ppid = x;
        }
        
        void showPpid()
        {
            cout<<ppid;
        }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    
    
    Encap obj;
    obj.pid = 34;
    obj.fillPpid(225);
    
    cout << obj.pid << endl;
    obj.showPpid();

    return 0;
}
