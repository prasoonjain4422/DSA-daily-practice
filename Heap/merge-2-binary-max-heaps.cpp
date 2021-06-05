// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.
#include <bits/stdc++.h>
using namespace std;

void mergeHeaps(int merged[], int a[], int b[], int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        int merged[m + n];
        mergeHeaps(merged, a, b, n, m);

        for (int i = 0; i < n + m; i++) cout << merged[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

void heapify(int a[], int n, int i)
{
    
    int lar = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l<n && a[l] > a[lar])
    {
        lar = l;
    }
    
    if(r<n && a[r] > a[lar])
    {
        lar = r;
    }
    
    if(i != lar)
    {
        swap(a[i], a[lar]);
        heapify(a, n, lar);
    }
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) 
{
    
    int i;
    for(i=0; i<n; i++)
    {
        merged[i] = a[i];
    }
    for(i=0; i<m; i++)
    {
        merged[n+i] = b[i];
    }

    for(i = (n+m)/2 - 1; i >= 0; i--)
    {
        heapify(merged, n+m, i);
    }
}
