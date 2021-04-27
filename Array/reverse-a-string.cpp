//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
    char c;
    int i=0, n=str.length();
    for(i=0;i<(n-1-i);i++)
    {
        c = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = c;
    }
    
    return str;
}