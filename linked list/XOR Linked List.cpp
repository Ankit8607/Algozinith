// https://www.learning.algozenith.com/problems/XOR-Linked-List-546

/*

Description

Implement the MyLinkedList class using a xor linked list with the following functions. A xor linked list can have the attributes: val and npx where val is the value of the current node and npx is the xor of the address to a pointer to the previous and next node.

MyLinkedList(): Initialise MyLinkedList object.
void addAtHead(int val): Add node with value val at the front of the linked list.
vector<int> printList(): Print the Linked List in the forward direction.
void reverseList(): Reverse the Linked List

Input Format

The first line of input contains Q - the number of queries.
Each of the next Q line contains a query of one of the types mentioned in the problem statement.


Constraints

1 ≤ Q ≤ 2000


Sample Input 1

6
addAtHead 1
addAtHead 2
addAtHead 3
printList
reverseList
printList

Sample Output 1

3 2 1
1 2 3

*/


class MyLinkedList {
    struct Node {
        int val;
        Node* npx;
        Node(int val) {
            this->val = val;
            npx = NULL;
        }
    };

    Node* head;

    /** Use this function to get XOR of two pointers  */
    struct Node* XOR (struct Node *a, struct Node *b)
    {
        return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->npx = head;
        // Replace head with new node
        if(head != NULL) {
            head->npx = XOR(head->npx, temp);
        }
        head = temp;
    }

    /** Print the Linked List in the forward direction */
    vector<int> printList() {
        Node* temp = head;
        vector<int> list;
        Node* prev = NULL;
        while(temp != NULL) {
            list.push_back(temp->val);
            Node* prevHead = temp;
            temp = XOR(temp->npx, prev);
            prev = prevHead;
        }
        return list;
    }

    /** Reverse the Linked List */
    void reverseList() {
        Node* newhead = NULL;
        Node* prev = NULL;
        // Traverse to the tail of linked list
        while(head != NULL) {
            newhead = head;
            Node* prevHead = head;
            head = XOR(head->npx, prev);
            prev = prevHead;
        }
        head = newhead;
    }
};
