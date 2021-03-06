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
                // cout << " - " << s[i] << " " << itr->freq << endl;
            }
            else
            {
                itr = itr->child[s[i] - 'a'];
                itr->freq++;
                // cout << " - " << s[i] << " " << itr->freq << endl;
            }
        }
        itr->isEnd = true;
    }

    void search(string s)
    {
        int i, n = s.length();
        TrieNode *itr = root;

        for (i = 0; i < n; i++)
        {
            if (itr->child[s[i] - 'a'] == NULL)
            {
                return;
            }
            else
            {
                itr = itr->child[s[i] - 'a'];
            }
        }

        if (itr->isEnd)
        {
            cout << "Found" << endl;
            return;
        }

        cout << "Not Found" << endl;
    }

    void dfs(TrieNode *itr, string cur, vector<string> &ans)
    {
        
        if (itr == NULL)
            return;

        if (itr->freq == 1)
        {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (itr->child[i] != NULL)
            {
                char ch = 'a' + i;
                // cout << cur << endl;
                cur.append(1, ch);
                // cout << cur << endl;
                dfs(itr->child[i], cur, ans);
                cur = cur.substr(0, cur.size() - 1);
            }
        }
    }

    void prefix(vector<string> &ans)
    {

        for (int i = 0; i < 26; i++)
        {
            TrieNode *itr = root;
            if (itr->child[i] != NULL)
            {
                string s = string(1, 'a' + i);
                dfs(itr->child[i], s, ans);
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

    obj.search("nature");
    obj.search("natural");
    obj.search("tendency");
    obj.search("characterstics");

    vector<string> ans;

    obj.prefix(ans);

    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}
