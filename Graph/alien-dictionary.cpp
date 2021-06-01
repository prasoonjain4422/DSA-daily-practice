// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        int i, j;
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;
        
        for(i=1; i<N; i++)
        {
            for(j=0; j<min(dict[i-1].size(), dict[i].size()); j++)
            {
                if(dict[i-1][j] != dict[i][j])
                {
                    adj[dict[i-1][j]].push_back(dict[i][j]);
                    // indeg[dict[i][j]]++;
                    // indeg[dict[i-1][j]]++;
                    // indeg[dict[i-1][j]]--;
                    break;
                }
            }
        }
        
        queue<char> q;
        for(auto x: adj)
        {
            indeg[x.first]++;
            indeg[x.first]--;
            for(auto y: x.second)
            {
                indeg[y]++;
            }
        }
        
        for(auto x: adj)
        {
            if(indeg[x.first] == 0)
            {
                q.push(x.first);
            }
        }
        
        
        char c;
        string s = "";
        while(!q.empty())
        {
            c = q.front();
            q.pop();
            s = s + c;
            // cout<<c<<" "<<s<<endl;
            
            for(auto x: adj[c])
            {
                indeg[x]--;
                if(indeg[x] == 0)
                {
                    q.push(x);
                }
            }

        }
        // cout<<s;
        return s;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends