    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr, arr+n);
        int add, sub, i, b = arr[n-1] - k, s = arr[0] + k, ans = arr[n-1] - arr[0];
        if(s>b)
            swap(s, b);
        
        
        for(i=1;i<n-1;i++)
        {
            add = arr[i] + k;
            sub = arr[i] - k;
            
            if((sub >= s)||(add <= b))
                continue;
            
            
            if(((b - sub) <= (add - s)) && (sub >= 0))
                s = sub;
            else
                b = add;
        }
        
        ans = min(ans, (b - s));
        
        b = arr[n-1] - k;
        s = arr[0] + k;
        if(s>b)
            swap(s, b);
        
        for(i=n-2;i>0;i--)
        {
            add = arr[i] + k;
            sub = arr[i] - k;
            
            if((sub >= s)||(add <= b))
                continue;
            
            
            if(((b - sub) <= (add - s)) && (sub >= 0))
                s = sub;
            else
                b = add;
        }
        
        
        return min(ans, (b - s));