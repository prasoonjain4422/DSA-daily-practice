#include <bits/stdc++.h>

using namespace std;

class Parent
{
    
public:
    int pid;
    
private:
    int ppid;



};

class Child : public Parent
{
public:
    int cid;
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Child obj;
    obj.ppid = 1;
    obj.pid = 1;
    obj.cid = 2;

    cout << obj.pid << endl;
    cout << obj.cid << endl;

    return 0;
}
