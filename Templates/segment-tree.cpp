#include<bits/stdc++.h>
using namespace std;
#define maxvalue INT_MAX;

void constructTree(int input[], int segment[], int low, int high, int pos)
{
    if(low==high)
    {
        segment[pos] = input[low];
        return;
    }
    int mid = (low+high)/2;
    constructTree(input, segment, low, mid, 2*pos+1);
    constructTree(input, segment, mid+1, high, 2*pos+2);
    segment[pos] = min(segment[2*pos+1],segment[2*pos+2]);
}
void rangeMinQuery(int segment[], int qlow, int qhigh, int low, int high, int pos)
{
    if(qlow<=low && qhigh >= high)   //Total overlap
        return segment[pos];

    if(qlow>high || qhigh<low)      //No overlap
        return maxvalue;

    int mid = (low+high)/2;
    return min(rangeMinQuery(segment, qlow, qhigh, low, mid, 2*pos+1),
               rangeMinQuery(segment, qlow, qhigh, mid+1, high, 2*pos+2));
}

int main()
{
}

