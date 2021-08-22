#include <bits/stdc++.h>

using namespace std;

class Encap
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
        cout << age;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Encap obj;
    obj.setAge(225);

    obj.getAge();

    return 0;
}
