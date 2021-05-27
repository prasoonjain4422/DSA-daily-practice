
// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.

long long int ans=0;

void merge(long long int l, long long int m, long long int r, long long a[])
{
    long long int l1 = m - l + 1, l2 = r - m, i, j, k;

    long long le[l1], re[l2];

    for (i = 0; i < l1; i++)
        le[i] = a[i + l];

    for (i = 0; i < l2; i++)
        re[i] = a[i + m + 1];


    i = 0, j = 0, k = l;
    while ((i < l1) && (j < l2))
    {
        if (le[i] > re[j])
        {
            a[k++] = re[j++];
            ans += l1 - i;
            // cout << m - i + 1 << "k" << endl;
        }
        else
        {
            a[k++] = le[i++];
        }
    }

    while (j < l2)
    {
        a[k++] = re[j++];
    }

    while (i < l1)
    {
        a[k++] = le[i++];
    }
}

void mergeS(long long int l, long long int r, long long a[])
{
    if (l >= r)
        return;

    long long int m = (l + r) / 2;

    mergeS(l, m, a);
    mergeS(m + 1, r, a);
    merge(l, m, r, a);
}

long long int inversionCount(long long arr[], long long N)
{
    
    ans = 0;
    mergeS(0, N - 1, arr);

    
    return ans;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends