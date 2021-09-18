#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> vis;

bool isv(string str)
{
    int i, n = str.size();
    stack<char> s;

    for (i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            s.push('(');
        }
        else if (str[i] == ')')
        {
            if ((!s.empty()) && (s.top() == '('))
            {
                s.pop();
            }
            else
            {
                s.push(')');
            }
        }
    }

    if (s.empty())
        return true;

    return false;
}

void dfs(string str, int j, vector<string> &ans)
{
    
    if(vis[str])
        return;
    
    // cout << str << endl;
    if (j == 0)
    {
        if (isv(str))
        {
            ans.push_back(str);
        }
    }
    else
    {
        int i, n = str.size();

        for (i = 0; i < n - 1; i++)
        {
            dfs(str.substr(0, i) + str.substr(i + 1), j - 1, ans);
        }
        dfs(str.substr(0, n - 1), j - 1, ans);
    }
    
    vis[str] = true;
    
}

vector<string> removeInvalidParentheses(string str)
{

    int i, j, n = str.size();
    vector<int> l, r;
    stack<char> s;

    for (i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            s.push('(');
        }
        else if (str[i] == ')')
        {
            if ((!s.empty()) && (s.top() == '('))
            {
                s.pop();
            }
            else
            {
                s.push(')');
            }
        }
    }

    vector<string> ans;
    j = s.size();
    cout << j << endl;

    for (i = 0; i < n - 1; i++)
    {
        dfs(str.substr(0, i) + str.substr(i + 1), j - 1, ans);
    }

    dfs(str.substr(0, n - 1), j - 1, ans);

    return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    vector<string> out = removeInvalidParentheses(s);

    if (out.size() == 0)
        cout << "0/-";

    for (auto x : out)
    {
        cout << x << endl;
    }

    return 0;
}
