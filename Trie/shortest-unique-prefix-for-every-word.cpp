#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    int freq = 1;
    bool isEnd = false;
};

class Trie
{
private:
    struct TrieNode *root = new TrieNode();

public:
    TrieNode *newNode()
    {
        TrieNode *temp = new TrieNode();
        temp->freq = 1;
        return temp;
    }

    void insert(string s)
    {
        int i, n = s.length();
        TrieNode *itr = root;

        for (i = 0; i < n; i++)
        {
            if (itr->child[s[i] - 'a'] == NULL)
            {
                itr->child[s[i] - 'a'] = newNode();
                itr = itr->child[s[i] - 'a'];
                cout << " - " << s[i] << " " << itr->freq << endl;
            }
            else
            {
                itr = itr->child[s[i] - 'a'];
                itr->freq++;
                cout << " - " << s[i] << " " << itr->freq << endl;
            }
        }
        itr->isEnd = true;
    }

    bool search(string s)
    {
        int i, n = s.length();
        TrieNode *itr = root;

        for (i = 0; i < n; i++)
        {
            if (itr->child[s[i] - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                itr = itr->child[s[i] - 'a'];
            }
        }

        if (itr->isEnd)
            return true;

        return false;
    }

    void dfs(TrieNode *itr, string cur, vector<string> &ans)
    {
        if (itr == NULL)
            return;

        if (itr->freq == 1)
        {

            // cur += " -> " + cur;

            // for (int i = 0; i < 26; i++)
            // {
            //     if (itr->child[i] != NULL)
            //     {
            //         cur +=
            //     }
            // }

            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (itr->child[i] != NULL)
            {
                char ch = 'a' + i;
                cout << cur << endl;
                cur.append(1, ch);
                cout << cur << endl;
                dfs(itr, cur, ans);
            }
        }
    }

    void prefix(vector<string> &ans)
    {

        TrieNode *itr = root;

        for (int i = 0; i < 26; i++)
        {
            if (itr->child[i] != NULL)
            {
                string s = string(1, 'a' + i);
                dfs(itr, s, ans);
            }
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Trie obj;

    obj.insert("nature");
    obj.insert("natural");
    obj.insert("tendency");
    obj.insert("characterstics");

    vector<string> ans;

    obj.prefix(ans);

    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}
