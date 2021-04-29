class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<bool> c(n, false);
        int i, j, s, e;
        vector<vector<int>> ans;
        vector<int> temp;
        bool doi = false;
        
        for(i=0;i<n;i++)
        {
            if(c[i])
                continue;
            
            s = intervals[i][0];
            e = intervals[i][1];
            for(j=0;j<n;j)
            {
                // if(c[j])
                    // continue;
                
                
                if((s <= intervals[j][0])&&(e >= intervals[j][1]))
                {
                    c[j] = true;
                    j++;
                    continue;
                }
                
                
                if((s >= intervals[j][0])&&(e <= intervals[j][1]))
                {
                    c[j] = true;
                    s = intervals[j][0];
                    e = intervals[j][1];
                    doi=true;
                    // continue;
                }
                
                
                if((s >= intervals[j][0])&&(s <= intervals[j][1]))
                {
                    c[j] = true;
                    s = intervals[j][0];
                    doi=true;
                }
                    
                if((e >= intervals[j][0])&&(e <= intervals[j][1]))
                {
                    c[j] = true;
                    e = intervals[j][1];
                    doi=true;
                }
                
                j++;
                if(doi)
                {
                    doi=false;
                    j=0;
                }
                
                
            }
            
            temp.clear();
            temp.push_back(s);
            temp.push_back(e);
            ans.push_back(temp);
        }
        
        auto ip = unique(ans.begin(), ans.end());
        ans.resize(distance(ans.begin(), ip));
        return ans;
        
        
        
        
        
    }
};