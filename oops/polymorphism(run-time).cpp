#include <bits/stdc++.h>
using namespace std;

//  overriding of functions in derived class

class Parent
{
    private:
        int age;

    public:
        void setAge(int i)
        {
            age = i;
        }

        // virtual void ageType() = 0;
        
        
        virtual void getAge()
        {
            cout<<"Parent-Age-1"<<endl;
        }
        
        void getAge(int x)
        {
            cout<<"Parent-Age-2"<<endl;
        }
};

class Child : public Parent
{
    public :
        void getAge()
        {
            cout<<"Child-Age-1"<<endl;
        }
};

int main()
{
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    
    Parent pobj;
    Child cobj;
    
    Parent *pp = &cobj;

    pobj.setAge(225);

    pobj.getAge();
    pobj.getAge(1);

    
    cobj.getAge();
    pp->getAge();
    
    return 0;
}