// https://www.learning.algozenith.com/problems/Merge-Elements-1-154

/*

Description

You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (a+b)%100 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2+A3)%100, A4].
 

Find the Minimum cost to merge all the elements into a single element.


Input Format

The first line contains a single element N. 1 <= N <= 500

The Second line contains N space separated integers, the Ai for the Array.  0 <= Ai < 100


Output Format

Output a single integer, the Minimum cost to Merge all the elements.


Sample Input 1

3
1 2 4 

Sample Output 1

14

Note

If you merge elements 1 and 2 first, You get [3,4] and pay a cost of 1*2=2. Then if you merge 3 and 3, You get [7] and pay a cost of 3*4=12.

Total cost incurred = 2+12 = 14.

If you merge elements 2 and 4 first, You get [1,6] and pay a cost of 24=8. Then if you merge 1 and 6, You get [7] and pay a cost of 16=6.

Total cost incurred =  8+6 = 14.

So the best you can do is at cost 14.

*/


#include<bits/stdc++.h>
using namespace std;
int n;
int a[505];
int pref[505];
long long int dp[505][505];
long long int merge(int l, int r){
    if(l==0){
        return pref[r] % 100;
    }
    else{
        return (pref[r] - pref[l-1]) % 100;
    }
}
long long int solve(int l, int r){
    if(l>=r){
        return 0;
    }
    if(l<0 || r<0){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    long long int mintemp = 1e18;
    for(int k = l; k < r; k++){
        long long int temp = solve(l,k) + solve(k+1,r) + (merge(l,k)*merge(k+1,r));
        if(temp < mintemp){
            mintemp = temp;
        }
    }
    return dp[l][r] = mintemp;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    memset(dp, -1 , sizeof(dp));
    long long int ans = solve(0 , n - 1);
    cout<< ans <<endl;
}
