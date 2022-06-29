// https://www.learning.algozenith.com/problems/Circular-Queue-524

/*

Description

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

In a normal Queue, we can insert elements until the queue becomes full. But once the queue becomes full, we can not insert the next element even if there is a space in front of the queue.

Implement the following functions:

MyCircularQueue(k): Initializes the object with the size of the queue to be k.
int Front(): Gets the front item from the queue. If the queue is empty, return -1.
int Rear(): Gets the last item from the queue. If the queue is empty, return -1.
bool enQueue(int value): Inserts an element into the circular queue. Return true if the operation is successful.
bool deQueue(): Deletes an element from the circular queue. Return true if the operation is successful.
bool isEmpty(): Checks whether the circular queue is empty or not.
bool isFull(): Checks whether the circular queue is full or not.
Initially, the queue is empty.

You must solve the problem without using the built-in queue data structure in your programming language. 


Input Format

The first line of input contains Q - the number of queries.
The second line contains k.
Each of the next lines contains queries of one of the types mentioned in the problem statement.


Constraints

1 ≤ k, Q ≤ 105


Sample Input 1

9
3
enQueue 1
enQueue 2
enQueue 3
enQueue 4
Rear
isFull
deQueue
enQueue 4
Rear

Sample Output 1

True
True
True
False
3
True
True
True
4

*/


class MyCircularQueue
{
public:
    list<int>lst;
    int n;
    MyCircularQueue(int k)
    {
        n=k;
    }

    bool enQueue(int value)
    {
        if(lst.size()==n) return 0;
        lst.push_front(value);
        return 1;
    }

    bool deQueue()
    {
        if(lst.size()==0) return 0;
        lst.pop_back();
        return 1;
    }

    int Front()
    {
        if(lst.empty()) return -1;
        return lst.back();
    }

    int Rear()
    {
        if(lst.empty()) return -1;
        return lst.front();
    }

    bool isEmpty()
    {
        return lst.empty();
    }

    bool isFull()
    {
        return lst.size()==n;
    }
};
