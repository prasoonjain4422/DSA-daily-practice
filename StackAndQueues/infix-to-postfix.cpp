// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string exp)
    {
        
        int i, n;
        n = exp.length();
        
        string ans = "";
        stack<char> s;
        unordered_map<char, int> p;
        
        p['('] = 0;
        p[')'] = 0;
        p['+'] = 1;
        p['-'] = 1;
        p['*'] = 2;
        p['/'] = 2;
        p['^'] = 3;
        
        for(i=0; i<n; i++)
        {
            if(exp[i] == '(')
            {
                s.push(exp[i]);
            }
            else if((exp[i] == '+')||(exp[i] == '-')||(exp[i] == '*')||(exp[i] == '/')||(exp[i] == '^'))
            {
                while((!s.empty())&&(p[s.top()] >= p[exp[i]]))
                {
                    ans += s.top();
                    s.pop();
                }
                s.push(exp[i]);
            }
            else if(exp[i] == ')')
            {
                while((!s.empty())&&(s.top() != '('))
                {
                    ans += s.top();
                    s.pop();
                }
                
                if(!s.empty())
                    s.pop();
            }
            else
            {
                ans += exp[i];
            }
        }
        
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        

        
        return ans;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends