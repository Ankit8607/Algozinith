// https://www.learning.algozenith.com/problems/Moving-Zeros-615

/*

Description

You are given an integer array nums with n integers in it. You have to move all the zeros present in the array to the end of the array while maintaining the relative order of the rest of the elements. 
Solve this problem using constant extra space.
Try to solve the problem using minimum number of swap operations.


Input Format

Implement the MovingZeros function that takes the array nums.


Output Format

The function should make changes in the array itself. No need to return anything.


Constraints

1 <= n <= 100000
-100000 <= nums[i] <= 100000

Sample Input 1

6
0 2 0 0 1 3

Sample Output 1

2 1 3 0 0 0

Note

The relative ordering of the non-zeros elements is maintained and the zeros are moved to the end of the array.

*/


#include <bits/stdc++.h>
using namespace std;

void MovingZeros(vector <int>& nums) {
    int n = nums.size();
    int lastnonzero = 0;
    int cur = 0;
    while (cur < n) {
        if (nums[cur] != 0) {
            swap(nums[lastnonzero++], nums[cur]);
        }
        cur++;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	MovingZeros(nums);
	for (auto i : nums)
		cout << i << " ";
}
