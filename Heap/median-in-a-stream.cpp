// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    public:
    priority_queue<double> pqmax;
    priority_queue<double, vector<double>, greater<double>> pqmin;
    
    void insertHeap(int &x)
    {
        if(pqmin.size() < pqmax.size())
        {
            // cout<<x<<"  in"<<endl;
                if(x > pqmax.top())
                {
                    pqmin.push(x);
                }
                else
                {
                    pqmin.push(pqmax.top());
                    pqmax.pop();
                    pqmax.push(x);
                }
        }
        else
        {
            
            // cout<<x<<"  ax"<<endl;
            if(pqmax.empty())
            {
                pqmax.push(x);
            }
            else
            {
                if(x < pqmin.top())
                {
                    pqmax.push(x);
                }
                else
                {
                    pqmax.push(pqmin.top());
                    pqmin.pop();
                    pqmin.push(x);
                }
            }
        }
        
    }
    
    void balanceHeaps()
    {
        pqmax = priority_queue<double>();
        pqmin = priority_queue<double, vector<double>, greater<double>>();
    }
    
    
    double getMedian()
    {
        if(pqmax.size() > pqmin.size())
        {
            return (pqmax.top());
        }
        else
        {
            return ((pqmax.top() + pqmin.top())/2);
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
        ob.balanceHeaps();
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends