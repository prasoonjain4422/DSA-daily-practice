
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd = false;
};

class Solution
{
public:
    static void dfs(TrieNode *itr, vector<string> &temp, string &prefix, string cur)
    {
        int j;
        if (itr->isEnd)
        {
            temp.push_back(prefix + cur);
        }

        for (j = 0; j < 26; j++)
        {
            if (itr->child['a' + j] != NULL)
            {
                char ch = 'a' + j;
                cur.append(1, ch);
                dfs(itr->child['a' + j], temp, prefix, cur);
                cur = cur.substr(0, cur.size() - 1);
            }
        }
    }

    vector<vector<string>> displayContacts(int n, vector<string> &contact, string s)
    {
        int i, j, k;
        TrieNode *root = new TrieNode();

        // cout << root->child['t' - 'a'];

        cout << contact[3][10] << endl;

        for (i = 0; i < n; i++)
        {

            cout << i << endl;
            if (i >= n)
                break;
            string con = contact[i];
            cout << con << " " << con[10];
            TrieNode *itr = root;

            cout << " herer " << endl;

            for (j = 0; j < con.size(); j++)
            {
                if (itr == NULL)
                    cout << "sdv" << endl;

                cout << endl;
                if (itr->child[con[j] - 'a'] == NULL)
                    cout << "        kdfu ";

                cout << itr->child[con[j] - 'a'] << " " << con[j] << " ";
                if (itr->child[con[j] - 'a'] == NULL)
                {
                    cout << " new ";
                    itr->child[con[j] - 'a'] = new TrieNode();
                    itr = itr->child[con[j] - 'a'];
                }
                else
                {
                    cout << " old ";
                    itr = itr->child[con[j] - 'a'];
                }
            }
            
            cout << " out " << endl;
            
            // itr->isEnd = true;
        }

        cout << " y ";

        vector<vector<string>> ans;
        string prefix;

        // for (i = 0; i < s.length(); i++)
        // {
        //     vector<string> temp;
        //     TrieNode *itr = root;
        //     prefix = s.substr(0, i + 1);

        //     for (j = 0; j < (i + 1); j++)
        //     {
        //         if (itr->child[prefix[j] - 'a'] != NULL)
        //         {
        //             itr = itr->child[prefix[j] - 'a'];
        //         }
        //         else
        //         {
        //             temp.push_back("0");
        //             break;
        //         }
        //     }

        //     if (j >= (i + 1))
        //     {
        //         for (j = 0; j < 26; j++)
        //         {
        //             if (itr->child['a' + j] != NULL)
        //             {
        //                 char ch = 'a' + j;
        //                 string cur = string(1, ch);
        //                 dfs(itr->child['a' + j], temp, prefix, cur);
        //             }
        //         }
        //     }

        //     ans.push_back(temp);
        // }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> contact(n);
        string s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];

        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends