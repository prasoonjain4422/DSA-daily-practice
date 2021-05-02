#include<bits/stdc++.h>

class Solution {
public:
    
    int bsearch(vector<int>& nums, int l, int r, int s)
    {
        
        if(l==r)
            return r;
        
        
        int m, index=-1;
        while(l<=r)
        {
            m = (l+r)/2;
            
            if(nums[m] <= s)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
                if((index == -1)||(nums[index]>=nums[m]))
                    index = m;
            }
        }
        return index;
    }
    
    
    void nextPermutation(vector<int>& nums) {
        
        int i, j, n = nums.size();
        
        if(n==1)
            return;
        
        if(n==2)
        {
            swap(nums[0], nums[1]);
            return;
        }
        
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        
        if(i==-1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int index = bsearch(nums, i+1, n-1, nums[i]);
            swap(nums[i], nums[index]);
            i=i+1, j=n-1;
            while(i<j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        
        return;
        
    }
};
