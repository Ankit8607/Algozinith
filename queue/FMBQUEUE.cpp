// https://www.learning.algozenith.com/problems/FMBQUEUE-627

/*

Description

Design a queue that supports push and pop operations in the front, middle, and back.


Input Format

Implement the FrontMiddleBack class:

FrontMiddleBack() : Initializes the queue.
void pushFront(int val) : Adds val to the front of the queue.
void pushMiddle(int val) : Adds val to the middle of the queue.
void pushBack(int val) : Adds val to the back of the queue.
int popFront() : Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() : Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() : Removes the back element of the queue and returns it. If the queue is empty, return -1.
Note: When there are two middle position choices, the operation is performed on the left middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].

Output Format

For every pop function, return the popped element.


Constraints

1 ≤ val ≤ 109

At most 105 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.


Sample Input 1

9
pushFront 1
pushBack 2
pushMiddle 3
pushMiddle 4
popFront
popMiddle
popMiddle
popBack
popFront

Sample Output 1

1
3
4
2
-1

Note

The state of the queue after the operations:
[1]
[1, 2]
[1, 3, 2]
[1, 4, 3, 2]
[4, 3, 2]
[4, 2]
[2]
[]
-1 -> [] (The queue is empty)

*/


class FrontMiddleBackQueue
{
public:
    deque<int> first,second;
    FrontMiddleBackQueue()
    {
    }
    
    void update(){
        while(first.size()+1<second.size()){
            int t=second.front();
            second.pop_back();
            first.push_back(t);
        }
        while(first.size()>second.size()){
            int t=first.back();
            first.pop_back();
            second.push_front(t);
        }
    }

    void pushFront(int val)
    {
        first.push_front(val);
    }

    void pushMiddle(int val)
    {
        update();
        first.push_back(val);
    }

    void pushBack(int val)
    {
        second.push_back(val);
    }

    int popFront()
    {
        int tot=first.size()+second.size();
        if(tot==0) return -1;
        int t;
        if(first.size()>0)t=first.front(), first.pop_front();
        else t=second.front(), second.pop_front(); 
        return t;
    }

    int popMiddle()
    {
        int tot=first.size()+second.size();
        if(tot==0) return -1;
        update();
        int t;
        if(first.size()==second.size()) t=first.back(), first.pop_back();
        else t=second.front(), second.pop_front();
        return t;
    }

    int popBack()
    {
        int tot=first.size()+second.size();
        if(tot==0) return -1;
        int t;
        if(second.size()>0)t=second.back(), second.pop_back();
        else t=first.back(), first.pop_back(); 
        return t;
    }
};
