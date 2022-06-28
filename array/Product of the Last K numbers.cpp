// https://www.learning.algozenith.com/problems/Product-of-the-Last-K-numbers-523

/*

Description

Design the algorithm which supports the following operations.

add(int x): Add x to the back of the current list of numbers.
getProduct(int k): Print the product of the last k numbers % 1000000007 in the current list. It's guaranteed that the list will contain at least k elements.
Initially, the list is empty.

Complete the code.


Input Format

The first line contains Q - the number of queries.
Each query is one of the types of queries explained in the problem statement.


Constraints

1 ≤ Q ≤ 105
0 ≤ x ≤ 109


Sample Input 1

10
add 3
add 0
add 2
add 5
add 4
getProduct 2
getProduct 3
getProduct 4
add 8
getProduct 2

Sample Output 1

20
40
0
32

*/


#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int power(int a ,int b){
    int ans=1;
    while(b){
        if(b&1) ans=1ll*ans*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return ans;
}

class ProductOfKNumbers {
public:
    vector<int>pre;
	ProductOfKNumbers() {
        pre.clear();
        pre.push_back(1);
	}

	void add(int num) {
        if(num == 0) pre.clear(),pre.push_back(1);
        else pre.push_back(1ll*num*pre.back()%mod);
	}

	int getProduct(int k) {
        if(pre.size()<=k) return 0;
		return 1ll*pre[pre.size()-1]*power(pre[pre.size()-k-1],mod-2)%mod;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	ProductOfKNumbers productOfKNumbers;

	while(Q--) {
		string op;
		cin >> op;

		if (op == "add") {
			int num;
			cin >> num;
			productOfKNumbers.add(num);
		}
		else {
			int k;
			cin >> k;

			cout << productOfKNumbers.getProduct(k) << "\n";
		}
	}

	return 0;
}
