// https://www.mock.algozenith.com/test/MICROSOFT/live?attempt_id=1991&xcord=0&ycord=1

/*

Description

Consider an infinite 2D plane divided into four quadrants by the x-axis and the y-axis. A tiny creature called minion is present at the origin i.e. (0,0) at time T = 0. Minion is very confused and is trying to find his friends. He can travel in only 4 directions namely, +ve x-axis, +ve y-axis, -ve x-axis and -ve y-axis. Initially, he is travelling in the +ve x-axis direction at a speed of 1 unit distance per unit of time.

Minion's friends are quite worried about him and reach at the origin (0,0) while looking for him. They know all the turns taken by minion at various points of time between 0 (beginning) and N (present time). They hand the data to you. You have to find the current location of the minion to help his friends.


Input Format

The first line of input contains two space-separated integers N and L - the present time, and the number of turns taken.
Each of the next L lines contains two space-separated integers time, and turn - the time at which turn is taken and for the ease of taking inputs, the left turn is denoted by 0 and the right turn is denoted by 1.

Note: The L inputs are not necessarily in increasing order of time.


Output Format

Print the sum of the X coordinate of the minion's current position and Y coordinate of the minion's current position.


Constraints

1 ≤ N ≤ 109
1 ≤ L ≤ 105
1 ≤ time ≤ N
0 ≤ turn ≤ 1


Sample Input 1

2 1
1 1

Sample Output 1

0

Note

At time =0, position =(0,0). 
At time =1, position =(1,0) . Here, he takes a right turn. 
At time =2 position =(1,-1).

*/


#include<bits/stdc++.h>
using namespace std;
const int mod= 10000007;
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

void solve(){
    int time,n; cin>>time>>n;
    vector<ii>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S;
    }
    sort(arr.begin(),arr.end());
    arr.push_back({time,1});
    int dir=1;
    int x=0,y=0,last=0;
    for(int i=0;i<=n;i++){
        int dur=arr[i].F-last;
        if(dir==1){
            x+=dur;
            if(arr[i].S) dir=2;
            else dir=0;
        }
        else if(dir==2){
            y-=dur;
            if(arr[i].S) dir=3;
            else dir=1;
        }
        else if(dir==3){
            x-=dur;
            if(arr[i].S) dir=0;
            else dir=2;
        }
        else{
            y+=dur;
            if(arr[i].S) dir=1;
            else dir=3;
        }
        last=arr[i].F;
    }

    cout<<x+y<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
