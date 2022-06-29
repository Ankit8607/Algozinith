// https://www.learning.algozenith.com/problems/Stack-Increments-605

/*

Description

You have a box and you want to put numbers into it.
The capacity of the box is n. If the box has n numbers, no more numbers can be added to it.
Implement the CustomStack class :

CustomStack(int n): Initialises the object with n which is the maximum capacity of the box.
void push(int x) (1 <= x <= 1000) - Add x to the top of the box. If the box has already reached its capacity, do nothing.
int pop() - Return the number present on top of the box. Return -1 if the box is empty.
void inc(int k, int val) -  (1 <= k <= 104, 0 <= val <= 1000) - Increment the bottom k numbers of the box by val. If there are less than k numbers in the box, just increment all the numbers.

Input Format

Your CustomStack object will be instantiated and called as such:

CustomStack* obj = new CustomStack(maxSize);
obj->push(x);
int param_2 = obj->pop();
obj->inc(k,val);

Output Format

Implement the CustomStack class.


Constraints

1 <= n <= 100000
1 <= q <= 100000  (total number of function calls)
1 <= x <= 1000
1 <= k <= 105
0 <= val <= 1000

Sample Input 1

4 12
push 5
push 9
push 8
push 7
push 6
pop
inc 2 5
inc 6 5
pop
pop
pop
pop

Sample Output 1

7
13
19
15
-1

Note

1. Box will look like [5].
2. Box will look like [5 ,9]
3. Box will look like [5 ,9 ,8].
4. Box will look like [5 ,9 ,8 ,7].
5. Box will look like [5 ,9 ,8 ,7]. Since the capacity of the box is 4, 6 is not added to the box.
6. Box will look like [5 ,9 ,8]. 7 is printed since it is at the top.
7. Box will look like [10 ,14 ,8].
8. Box will look like [15 ,19 ,13]. Since 6 numbers are not present, all of them are incremented.
9. Box will look like [15 ,19]. 13 is printed since it is at the top.
10. Box will look like [15]. 19 is printed since it is at the top.
11. Box will look like []. 15 is printed since it is at the top.
12. Box is empty so -1 is printed.

*/


class CustomStack {
public:
	vector<pair<int,int>>st;
    int n;
	CustomStack(int maxSize) {
        n=maxSize;
	}

	void push(int x) {
		if(st.size()==n) return;
        st.push_back({x,0});
	}

	int pop() {
		if(st.size()==0) return -1;
        int inc=st.back().second;
        int t=inc+st.back().first;
        st.pop_back();
        if(st.size()) st.back().second+=inc;
        return t;
	}

	void increment(int k, int val) {
		if(k>=st.size()) st.back().second+=val;
        else st[k-1].second+=val;
	}
};
