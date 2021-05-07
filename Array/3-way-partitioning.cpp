// { Driver Code Starts
//Initial Template for C

#include <stdio.h>

// } Driver Code Ends
//User function Template for C

void swap(int ar[], int a, int b)
{
    int t = ar[a];
    ar[a] = ar[b];
    ar[b] = t;
}

void threeWayPartition(int ar[], int n, int a, int b)
{
    int i = 0, j;

    a--; // next level thing
    while ((i < n) && (ar[i] <= a))
        i++;

    for (j = i + 1; (j < n) && (i < n); j++)
    {
        if (ar[j] <= a)
        {
            swap(ar, i, j);
            i++;
        }
        while ((i < n) && (ar[i] <= a))
            i++;
    }

    i = 0;
    while ((i < n) && (ar[i] <= b))
        i++;

    for (j = i + 1; (j < n) && (i < n); j++)
    {
        if (ar[j] <= b)
        {
            swap(ar, i, j);
            i++;
        }
        while ((i < n) && (ar[i] <= b))
            i++;
    }
}

// { Driver Code Starts.

int cnt[1000001];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);

        int array[N];

        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &array[i]);
            cnt[array[i]]++;
        }

        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        int original[N];
        for (int i = 0; i < N; i++)
            original[i] = array[i];

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0;
        int kk2 = 0;
        int kk3 = 0;

        for (int i = 0; i < N; i++)
        {
            if (original[i] > b)
                k3++;
            else if (original[i] <= b && original[i] >= a)
                k2++;
            else if (original[i] < b)
                k1++;
        }

        threeWayPartition(array, N, a, b);

        for (int i = 0; i < k1; i++)
        {
            if (array[i] < b)
                kk1++;
        }

        for (int i = k1; i < k1 + k2; i++)
        {
            if (array[i] <= b && array[i] >= a)
                kk2++;
        }

        for (int i = k1 + k2; i < k1 + k2 + k3; i++)
        {
            if (array[i] > b)
                kk3++;
        }

        int ok = 0;
        if (k1 == kk1 && k2 == kk2 && k3 == kk3)
            ok = 1;

        for (int i = 0; i < N; i++)
            cnt[array[i]]--;

        for (int i = 0; i < N; i++)
            if (cnt[array[i]] != 0)
                ok = 0;

        if (ok > 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
} // } Driver Code Ends