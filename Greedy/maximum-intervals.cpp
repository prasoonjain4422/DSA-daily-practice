class Solution {
public:
    
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    
    
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int i, j=INT_MIN, ans = 0, n = pairs.size();
        
        for(i=0; i<n; i++)
        {
            if(pairs[i][0] > j)
            {
                ans++;
                j = pairs[i][1];
            }
        }
        
        return ans;
    }
};