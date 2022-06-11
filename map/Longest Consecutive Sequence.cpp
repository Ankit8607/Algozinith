// https://www.learning.algozenith.com/problems/Longest-Consecutive-Sequence-609

/*

Description

You are given an unsorted array nums consisting of n integers. A beautiful sequence is a sequence of integers that consist of consecutive integers.
For example,

5 6 9 7 8 10 - is a beautiful sequence because it contains consecutive integers.
1 1 2 3 - is not a beautiful sequence because 1 appears twice.
You need to find the maximum length of a beautiful sequence that can be made using the elements of nums.
Try to solve the problem in O(n) time complexity.


Input Format

Implement the LongestConsecutive function that takes the array nums.


Output Format

Return the maximum length of a beautiful sequence that can be made using the elements of nums.


Constraints

1 <= n <= 100000

-109 <= nums[i] <= 109


Sample Input 1

6
-5 1 -3 -2 -1 -4

Sample Output 1

5

Note

-1 -2 -3 -4 -5
Is the maximum length beautiful sequence that can be obtained.

*/


#include <bits/stdc++.h>
using namespace std;

int LongestConsecutive(vector <int>& nums) {
	unordered_map<int,int>mp;
    for(auto i:nums) mp[i]++;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i]-1)!=mp.end()) continue;
        int tmp=0;
        for(int j=nums[i];mp.find(j)!=mp.end();j++){
            tmp++;
            mp.erase(j);
        }
        ans=max(ans,tmp);
    }
    return ans;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	cout << LongestConsecutive(nums);
}
