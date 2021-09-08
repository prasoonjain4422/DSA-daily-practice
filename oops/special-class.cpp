#include <bits/stdc++.h>
using namespace std;

// How will you make a class in such a way that object
//  of that class can only be made from new operator
// and if tried directly it will show compile error ?


// answer = By making destructor private.



class Cap
{
    private:
        int a;
        ~Cap()
        {}
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    Cap *c = new Cap();
    
    
    
    
    
    
    
    
    return 0;
}
