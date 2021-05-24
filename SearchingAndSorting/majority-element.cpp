// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
        int i, c=1, m=0;
        for(i=1; i<size; i++)
        {
            if(a[i] == a[m])
                c++;
            else
                c--;
            
            if(c == 0)
            {
                m = i;
                c = 1;
            }
        }
        
        c=0;
        for(i=0; i<size; i++)
        {
            if(a[m] == a[i])
                c++;
        }
        
        if(c>size/2)
            return a[m];
        
        return -1;
        
}

        
// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends