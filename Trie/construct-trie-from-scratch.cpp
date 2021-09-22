#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd = false;
};

class Trie
{
    private:
        struct TrieNode* root = new TrieNode();

    public:
        TrieNode *newNode()
        {
            TrieNode *temp = new TrieNode();
            return temp;
        }

        void insert(string s)
        {
            int i, n = s.length();
            TrieNode* itr = root;

            for (i = 0; i < n; i++)
            {
                if (itr->child[s[i] - 'a'] == NULL)
                {
                    itr->child[s[i] - 'a'] = newNode();
                    itr = itr->child[s[i] - 'a'];
                }
                else
                {
                    itr = itr->child[s[i] - 'a'];
                }
            }
            itr->isEnd = true;
        }

        bool search(string s)
        {
            int i, n = s.length();
            TrieNode* itr = root;

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
            
            if(itr->isEnd)
                return true;
            
            return false;
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
    obj.insert("tendency");
    obj.insert("characterstics");
    
    
    if(obj.search("nature"))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    
    if(obj.search("natur"))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    
    if(obj.search("nature"))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    
    
    
    
    
    return 0;
}
