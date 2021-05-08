// { Driver Code Starts
#include <iostream>
#include <string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << PalinArray(a, n) << endl;
    }
} // } Driver Code Ends

/*Complete the function below*/
int PalinArray(int a[], int n)
{

    int i = 0, num, num2, d;
    for (i = 0; i < n; i++)
    {
        num = a[i];
        num2 = 0;
        while (num > 0)
        {
            d = num % 10;
            num = num / 10;
            num2 = (num2 * 10) + d;
        }

        if (num2 != a[i])
            return 0;
    }

    return 1;
}
