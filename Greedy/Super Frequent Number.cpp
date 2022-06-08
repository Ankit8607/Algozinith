// https://www.learning.algozenith.com/problems/Super-Frequent-Number-573

/*

Description

You are given a list of n integers. The super frequent number of the array is the number that is present in the array more than ⌊n / 2⌋ times. You need to print the super frequent number of the array. Assume that such a number is always present in the input array.
Try to solve the problem in linear time and constant extra space.


Input Format

The first line contains a single integer n.
The next line contains n integers representing the input array.


Output Format

Print the super frequent element of the array.


Constraints

1 <= n <= 100000
1 <= v[i] <= 100000

Sample Input 1

7
4 1 4 1 1 4 4

Sample Output 1

4

Note

4 is present more than n/2 times in the array. So it is the super frequent number.

*/


#include <bits/stdc++.h>
using namespace std;

int SuperFrequentElement(vector<int> &v)
{
    int num=-1,cnt=0;
    for(auto i:v){
        if(cnt==0) num=i;
        if(num==i) cnt++;
        else cnt--;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    cout << SuperFrequentElement(v) << "\n";
}
