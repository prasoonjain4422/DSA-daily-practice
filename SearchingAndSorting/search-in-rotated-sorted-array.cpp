class Solution {
public:
    int search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l=0;
        int r=n-1;
        int p, m;
        if(n==1)
        {
            if(a[0] == target)
                return 0;
            else
                return -1;
        }
        
        if(a[0] > a[n-1])
        {
            
            if(a[0] >= a[1])
            {
                p = l;
            }
            else
            {
                while(l<=r)
                {
                    p = (l+r)/2;
                    if(((p < n-1)&&(a[p] > a[p+1]))&&((p > 0)&&(a[p] > a[p-1])))
                    {
                        break;
                    }
                    else if((p == n-1)&&(a[p] > a[p-1]))
                    {
                        break;
                    }
                    else if((p == 0)&&(a[p] > a[p+1]))
                    {
                        break;
                    }
                    else if(a[p] >= a[0])
                    {
                        l = p+1;
                    }
                    else
                    {
                        r = p-1;
                    }
                }
            }

            cout<<p<<" ";
            if(a[0] <= target)
            {
                l = 0;
                r = p;
            }
            else
            {
                l = p+1;
                r = n-1;
            }
        }
            
        while(l<=r)
        {
            m = (l+r)/2;
            if(a[m] == target)
            {
                return m;
            }
            else if(a[m] < target)
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        
        if(a[m] == target)
            return m;
        else
            return -1;
    }
};