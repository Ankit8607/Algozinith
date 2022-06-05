// https://www.learning.algozenith.com/problems/Buy-and-Sell-Stock---1-258

/*

Description

You are given N integers, the price of a given stock on each day. You can buy and sell at most one stock. You cannot sell a stock before you buy one. You have to find the maximum profit you can make by buying and selling stocks.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the maximum profit you can make by buying and selling stocks.


Constraints

1 ≤ T ≤ 100

2 ≤ N ≤ 105

0 ≤ Ai ≤ 105


Sample Input 1

3
5
1 5 2 6 3
4
1 2 3 4
4
5 3 2 1

Sample Output 1

5
3
0

Note

For the first test case, you can buy stock on day 1 and sell on day 4. Profit = 6-1 = 5

For the second test case, you can buy stock on day 1 and sell on day 4. Profit = 4-1 = 3

For the third test case, you don’t buy and sell any stock. Profit = 0

*/



#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int BuyAndSellStock(vector<int> &a) 
{
    int ans=0,last=a[0];
    for(int i=1; i<a.size(); i++){
        if(a[i]>last) ans=max(ans,a[i]-last);
        last=min(a[i],last);
    }
    return ans;
}

int main(){
   IOS
   
   int t;
   cin>>t;
   
   while(t--){
       int n;
       cin>>n;
       
       vector<int> a(n);

       for (int i = 0; i < n; ++i) {
           cin>>a[i];
       }
       
       cout << BuyAndSellStock(a) << "\n";
   }

   return 0;
}
