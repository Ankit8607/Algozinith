// https://www.learning.algozenith.com/problems/Building-the-Sum-614

/*

Description

You are given an array nums of n integers and an integer target.
You want to build an expression out of nums by adding one of the symbols ‘+’ and ‘-’ before each integer in the array and then concatenate the integers.

For example, if nums = [1, 2], you can add ‘-’ before 1 and ‘+’ before 2 to obtain the expression “-1+2” which evaluates to 1.
Return the number of different expressions that you can build, which evaluates to target.
Since the answer can be huge output it modulo 109 + 7.


Input Format

Implement the function BuildingtheSum that takes in the array nums and the integer target.


Output Format

Return the number of different expressions modulo 109 + 7 that evaluates to the given target.


Constraints

1 <= n <= 1000
0 <= nums[i] <= 1000
-1000 <= target <= 1000
0 <= sum(nums[i]) <= 1000

Sample Input 1

4 2
1 1 1 1

Sample Output 1

4

Note

+1+1+1-1 = 2
+1+1-1+1 = 2
+1-1+1+1 = 2
-1+1+1+1 = 2

*/


#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
map<int,int>mp[100010];

int rec(int level,int tar,vector <int>& nums){
    if(level==nums.size()){
        if(tar==0) return 1;
        return 0;
    }

    if(mp[level].find(tar)!=mp[level].end()) return mp[level][tar];

    long long ans=rec(level+1,tar+nums[level],nums)+rec(level+1,tar-nums[level],nums);

    return mp[level][tar]=ans%mod;
}

int BuildingtheSum(vector <int>& nums, int target) {
    return rec(0,target,nums);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int target;
	cin >> target;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	cout << BuildingtheSum(nums, target);
}
