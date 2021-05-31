/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _nei
logo
Explore
Problems
Interview
Contest
Discuss
Store
🚀 May LeetCoding Challenge 2021 🚀
1
Description
Solution
Discuss (999+)
Submissions
Success
Details
Runtime: 8 ms, faster than 77.54% of C++ online submissions for Flood Fill.
Memory Usage: 14.2 MB, less than 37.94% of C++ online submissions for Flood Fill.
Next challenges:
Island Perimeter
Show off your acceptance:
Time Submitted
	
Status
	
Runtime
	
Memory
	
Language
05/31/2021 14:49	Accepted	8 ms	14.2 MB	cpp
05/31/2021 14:48	Wrong Answer	N/A	N/A	cpp
/109

1

class Solution {

2

public:

3

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

4

        

5

        int x, y;

6

        queue<pair<int, int>> q;

7

        int n = image.size();

8

        int m = image[0].size();

9

        bool vis[n][m];

10

        int i, j;

11

        

12

        for(i=0; i<n; i++)

13

        {

14

            for(j=0; j<m; j++)

15

                vis[i][j] = false;

16

        }

17

        

18

        q.push({sr, sc});

19

        

20

        while(!q.empty())

21

        {

22

            

23

            x = (q.front()).first;

24

            y = (q.front()).second;

25

            q.pop();

26

            

27

            if(vis[x][y])

28

                continue;

29

            

30

            

31

            if(((x-1) >= 0)&&(image[x-1][y] == image[x][y]))

32

            {

33

                q.push({x-1, y});

34

            }

35

            

36

            if(((x+1) < n)&&(image[x+1][y] == image[x][y]))

37

            {

38

                q.push({x+1, y});

39

            }

40

​

41

            if(((y-1) >= 0)&&(image[x][y-1] == image[x][y]))

42

            {

43

                q.push({x, y-1});

44

            }

45

            

46

            if(((y+1) < m)&&(image[x][y+1] == image[x][y]))

47

            {

48

                q.push({x, y+1});

49

            }

50

            

51

            image[x][y] = newColor;

52

            vis[x][y] = true;

53

        }

54

        

55

        return image;

56

        

57

    }

58

};

Contribute

Type here...(Markdown is enabled)

​

Saved
Binary Search
This list is empty.
ghbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        
        queue<Node *> q, q2;
        q.push(node);
        map<int, Node*> vis;
        Node *ans, *it;
        ans = new Node(node->val);
        it = ans;
        vis[node->val] = it;
        q2.push(it);
        
        while(!q.empty())
        {
         
            node = q.front();
            it = q2.front();
            q.pop();
            q2.pop();
            
            for(auto x: node->neighbors)
            {
                if(vis[x->val] == NULL)
                {
                    Node *temp = new Node(x->val);
                    (it->neighbors).push_back(temp);

                    vis[x->val] = temp;
                    q.push(x);
                    q2.push(temp);
                }
                else
                {                    
                    (it->neighbors).push_back(vis[x->val]);
                }
                
            }
            
        }
        
        return ans;
        
        
        
        
        
    }
};