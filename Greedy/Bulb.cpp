// Link: https://www.learning.algozenith.com/problems/Bulb-527


/*

Description

Given a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are off.

A permutation a of integers from 1 to n is given. At the k-th moment (k varies from 0 to n-1), the a[k]-th bulb is turned on.

A bulb turns blue if it is turned on and all the bulbs to its left are turned on.

Find the number of moments in which all the bulbs, which are turned on, are blue.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 100000)

The first line of each test case contains an integer n, the number of bulbs. (1 ≤ n ≤ 10^5).

The next lines contain n space-separated integers, integers are distinct, (1 ≤ a[i] ≤ n).

Sum of n across all test cases ≤ 10^6.


Output Format

For each test case print number of moments in which all the bulbs, which are turned on, are blue in a new line.


Sample Input 1

5
2
1 2
6
4 5 1 6 2 3
9
7 6 8 5 9 1 4 3 2
9
9 2 6 7 8 5 4 3 1
3
3 1 2 

Sample Output 1

2
1
1
1
1

Sample Input 2

1
5
1 3 2 4 5 

Sample Output 2

4

Note

Sample 1
Testcase 1 - When bulb 1 is turned on, then only bulb 1 is turned on and there is no left bulb(<1) that exists and needs to be blue. So bulb 1 will turn blue. As all the turned on bulb are blue, will increase the answer by 1. When bulb 2 is turned on, then bulb <2 which is 1 is already turned on, so bulb 2 will turn blue. As 1,2 both the turned on bulbs are blue, will increase the answer by 1.

Testcase 2 - When bulb 4 is turned on, then all the bulb < 4 (1,2,3) is not turned on. So bulb 4 will not turn blue. As all the bulb turned on is not blue, we will not increment the answer. When bulb 5 is turned on, then it will not turn blue. When bulb 1 is turned on, then it will turn blue as there is no bulb < 1 that needs to be turned on. As all the bulb turned on is not blue we will not increase the answer. When bulb 6 is turned on, it will not turn blue as bulb 2,3 is not turned on. When bulb 2 is turned on it will turn blue as bulb 1 is turned on. When bulb 3 is turned on then bulb 3,4,5,6 will turn blue and all the turned on the bulb is blue so we will increment the answer.

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans[n+1]={0};
        ans[0]=2;
        int res=0;
        int not_blue=0;
        for(int i=0;i<n;i++){
            int t=arr[i];
            if(ans[t-1]==2){
                ans[t]=2;
                while(t+1<=n and ans[t+1]==1){
                    t++;
                    ans[t]=2;
                    not_blue--;
                }
                if(not_blue==0) res++;
            }
            else{
                ans[t]=1;
				not_blue++;
            }
        }
        cout<<res<<endl;
    }
	return 0;
}
