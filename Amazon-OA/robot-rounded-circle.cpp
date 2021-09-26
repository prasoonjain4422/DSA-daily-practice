

//tag - maths logic

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string s)
    {

        int i, u = 0, f = 0, l = 0, n = s.size();
        bool uc = false, fc = true;

        for (i = 0; i < n; i++)
        {
            if ((s[i] == 'G') && (abs(l) % 2 == 0))
            {
                if (fc)
                    f++;
                else
                    f--;
            }
            else if ((s[i] == 'G') && (abs(l) % 2 != 0))
            {
                if (uc)
                    u++;
                else
                    u--;
            }
            else if ((s[i] == 'L') || (s[i] == 'R'))
            {

                if (s[i] == 'L')
                    l++;
                else
                    l--;

                if (abs(l) % 4 == 0)
                {
                    fc = true;
                }
                else if (abs(l) % 4 == 1)
                {
                    uc = true;
                }
                else if (abs(l) % 4 == 2)
                {
                    fc = false;
                }
                else
                {
                    uc = false;
                }
            }
        }

        cout << l;
        if ((f == 0) && (u == 0))
            return true;
        else if (abs(l) % 4 != 0)
            return true;

        return false;
    }
};