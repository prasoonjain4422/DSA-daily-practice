// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    int i, j, u, v, w, e = edges.size();
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    
	    for(i=0; i<n-1; i++)
	    {
    	    for(j=0; j<e; j++)
    	    {
    	        u = edges[j][0];
    	        v = edges[j][1];
    	        w = edges[j][2];
    	        
    	        if((dist[u] != INT_MAX)&&((dist[u] + w) < dist[v]))
    	            dist[v] = dist[u] + w;
    	    }
	    }
	    
	    for(j=0; j<e; j++)
	    {
	        u = edges[j][0];
	        v = edges[j][1];
	        w = edges[j][2];
	        
	        if((dist[u] != INT_MAX)&&((dist[u] + w) < dist[v]))
	        {
	            return 1;
	        }
	    }
   
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends