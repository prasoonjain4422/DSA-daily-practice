#include <bits/stdc++.h>

using namespace std;

//  private membersa never gets inherited

class Parent
{
    public:
        int v1;
        
    protected:
        int v2;
        
    private:
        int v3;
};

class Child1 : public Parent
{
    public:
        void getpv1()
        {
            cout<<v1;
        }
        void getpv2()
        {
            cout<<v2;
        }
        void getpv3()
        {
            cout<<v3;     //error - private members never gets inherited
        }
};
class Child2 : protected Parent
{
    public:
        void getpv1()
        {
            cout<<v1;     // public will become protected
        }
        void getpv2()
        {
            cout<<v2;     // protected will become protected
        }
        void getpv3()
        {
            cout<<v3;     //error - private members never gets inherited
        }
};

class Child3 : private Parent
{
    public:
        void getpv1()
        {
            cout<<v1;    // public will become private
        }
        void getpv2()
        {
            cout<<v2;    // protected will become private
        }
        void getpv3()
        {
            cout<<v3;    //error - private members never gets inherited
        }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Child1 obj1;
    obj1.v1 = 1;
    // obj1.v2 = 2;  //error
    // obj1.v3 = 3;  //error
    obj1.cid = 4;
    
    Child2 obj2;
    // obj2.v1 = 1;  //error because protected inheritance makes public members protected
    // obj1.v2 = 2;  //error
    // obj1.v3 = 3;  //error
    obj2.cid = 4;
    
    Child3 obj3;
    obj3.v1 = 1;
    // obj1.v2 = 2;  //error
    // obj1.v3 = 3;  //error
    obj3.cid = 4;
    
    
    
    
    
    
    return 0;
}
