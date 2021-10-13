#include<bits/stdc++.h>
using namespace std;

vector<int> v;
map<int,set<int>> tr;

void dfs(int node, int parent, int d)
{
    if(d%2==0)
        v[node-1] = 1;
    else
        v[node-1] = 2;

    for(auto i : tr[node])
    {
        if(i==parent)
            continue;
        dfs(i,node,d+1);
    }
}



int main()
{
    int t,n,i,j,u,s;
    cin>>t;
    while(t--)
    {
        cin>>n;

        v.resize(n);
        v.clear();
        tr.clear();

        for(i=0;i<n-1;i++)
        {
            cin>>u>>s;
            tr[u].insert(s);
            tr[s].insert(u);
        }
        dfs(1,-1,1);

        for(i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
