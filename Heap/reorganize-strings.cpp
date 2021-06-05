class Solution {
public:
    
    string reorganizeString(string s) 
    {
        
        int n = s.size();
        
        map<char, int> m;
        
        for(auto x: s)
        {
            m[x]++;
            
            
                // cout<<x<<" "<<m[x]<<" "<<n<<endl;
            if(m[x] > (n+1)/2)
            {
                return ("");
            }
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto x: m)
        {
            pq.push({x.second, x.first});
        }
        
        
        int i = 0;
        while(!pq.empty())
        {
            
            auto x = pq.top();
            pq.pop();
            
            while(x.first > 0)
            {
                if(i>=n)
                {
                    i = 1;
                }

                s[i] = x.second;
                x.first--;
                i += 2;
            }
        }
        
        return s;
    }
};