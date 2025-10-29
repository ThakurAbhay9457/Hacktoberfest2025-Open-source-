#include<iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
  	Node(int x) {
     	data = x;
      	next = nullptr;
    }
};

// Returns count of nodes present in loop.
int countNodes(Node* node) {
    int res = 1;
    Node* curr = node;
    while (curr->next != node) {
        res++;
        curr = curr->next;
    }
    return res;
}

// Detects and Counts nodes in loop
int lengthOfLoop(Node* head) {
    Node *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr 
           && fast->next != nullptr) {
               
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet at
        // some point then there is a loop
        if (slow == fast)
            return countNodes(slow);
    }

    return 0;
}

int main() {
    
  	Node* head = new Node(25);
    head->next = new Node(14);
    head->next->next = new Node(19);
    head->next->next->next = new Node(33);
    head->next->next->next->next = new Node(10);
  	
    head->next->next->next->next->next = head->next->next;
    
    cout << lengthOfLoop(head) << endl;

    return 0;
}
