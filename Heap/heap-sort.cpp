// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    void heapify(int a[], int n, int i) 
    {
    
        int lar = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;
        
        if((l<n) && (a[l] > a[lar]))
            lar = l;
        
        if((r<n) && (a[r] > a[lar]))
            lar = r;
        
        if(i != lar)
        {
            swap(a[lar], a[i]);
            heapify(a, n, lar);
        }
    }

    public:
    void buildHeap(int a[], int n) 
    {
        int i;
        
        for(i = n/2 - 1; i>=0; i--)
        {
            heapify(a, n, i);
        }
    }


    public:
    void heapSort(int a[], int n)
    {
        int i;
        
        buildHeap(a, n);
        // swap(a[0], a[n-1]);
        for(i = n-1; i > 0; i--)
        {
            swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends