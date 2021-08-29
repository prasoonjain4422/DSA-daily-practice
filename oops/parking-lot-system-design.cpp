#include<bits/stdc++.h>

using namespace std;

class Elevator
{
    public :
        int floor;
        int direction;
        // int currentDest;
        queue<int> opQueue;
        unordered_map<int, bool> done;
        unordered_map<int, bool> inQueue;
        unordered_map<int, bool> reqDir;
        
        
        //  this function will be called to perform operation from queue(LIFS manner)
        void goToFloor(int floor)
        {
            
            // while()
            
            
            
        }
        
        //  this function will be called for every floor
        //  will stop the elevator(on current floor) if needed
        void isStopage(int floor)
        {
            if((inQueue[floor])&&(!done[floor])&&(reqDir[floor] == 0))  // if it was a internal request
            {
                // stop();  // stop on this floor
                done[floor] = true;
                inQueue[floor] = false;
            }
            
            if((inQueue[floor])&&(!done[floor])&&(reqDir[floor] == direction))  // if it was a external request with same direction as elevator
            {
                // stop();  // stop on this floor
                done[floor] = true;
                inQueue[floor] = false;
            }
        }
        
        // to handle request from inside elevator
        void inReq(int toFloor)
        {
            opQueue.push(toFloor);
            reqDir[toFloor] = 0;
            done[toFloor] = false;
            inQueue[toFloor]  = true;
        }
    
        // to handle request from outside elevator
        void outReq(int dir, int fromFloor)
        {
            opQueue.push(fromFloor);
            reqDir[fromFloor] = dir;
            done[fromFloor] = false;
            inQueue[fromFloor]  = true;
        }
        
    
};


int main()
{
    
    Elevator e1;
    
    
    while(true)
    {
        
        while(!e1.opQueue.empty())
        {
            e1.goToFloor(e1.opQueue.front());
            e1.opQueue.pop();
        }
        
        
        
    }
    
    
    
    return 0;
}
