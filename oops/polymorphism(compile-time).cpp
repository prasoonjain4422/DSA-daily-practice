#include <bits/stdc++.h>

using namespace std;

//  overloading of functions

class Pct
{
    private:
        int age;

    public:
        void setAge(int i)
        {
            age = i;
        }

        void getAge()
        {
            cout<<"Parent-Age-1"<<endl;
        }
        
        void getAge(int x)
        {
            cout<<"Parent-Age-2"<<endl;
        }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Pct obj;
    obj.setAge(225);

    obj.getAge();
    obj.getAge(1);

    return 0;
}
