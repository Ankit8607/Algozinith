// https://www.learning.algozenith.com/problems/Consecutive-Numbers-586

/*

Description

You are given an array consisting of n integers and a number k.
You need to determine if you can divide the array into sets of k consecutive integers. Each set must contain k integers and each element of the array must be present in 1 set. One element cannot be present in more than 1 set.


Input Format

The first line of input contains two integers n and k.
The second line contains n integers denoting the input array.


Output Format

Print ‘Yes’ if you can divide the array into sets of k consecutive integers. If you cannot, print ‘No’.


Constraints

1 <= n <= 100000
1 <= k <= n
1 <= v[i] <= 100000

Sample Input 1

8 4
2 3 1 4 9 8 7 6

Sample Output 1

Yes

Sample Input 2

4 3
5 6 7 8

Sample Output 2

No

Sample Input 3

8 4
1 2 3 3 4 4 5 6

Sample Output 3

Yes

Note

We can divide the array into two sets:
[1, 2, 3, 4]
[6, 7, 8, 9]
We cannot divide 4 integers into sets of size 3.
Two sets are: [1, 2, 3, 4] and [3, 4, 5, 6]

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
    int n,k; cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        mp[a]++;
    }
    while(1){
        if(mp.size()<k) break;
        int last=((mp.begin())->F)-1;
        auto it=mp.begin();
        for(int i=0;i<k;i++){
            if((it->F)-last==1){
                last=it->F;
                it->S=it->S-1;
                auto tmp=it;
                it++;
                if(tmp->S==0) mp.erase(tmp);
            }
            else {
                cout<<"No"<<endl;
                return;
            }
        }
        if(mp.size()==0){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
