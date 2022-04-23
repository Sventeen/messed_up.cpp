#include<iostream>

class Node {
public:
    int value;
    Node *next;
    Node() {
        this->value = 0;
        this->next = NULL;
    }
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;
    Node* reverse(Node* head) {
        if(!head || head->next == NULL)
            return head;
        Node* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
public:
    LinkedList() {
        head = NULL;
    }
    void insertNode(int data) {
        Node* newNode = new Node(data);
        if(!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp -> next)
            temp = temp->next;
        temp->next = newNode;
    }
    void printList() {
        Node* temp = head;
        while(temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
    void reverseIter() {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void reverse() {
        head = reverse(head);
    }
    bool detectLoop() {
        //head->next->next = head; uncomment to create a loop for testing.
        if(!head || head->next == NULL)
            return false;
        Node* slow = head->next;
        Node* fast = head->next->next;
        while(fast && fast->next) {
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
    Node* loopStarting() {
        if(!detectLoop())
            return NULL;
        Node* slow = head->next;
        Node* fast = head->next->next;
        while(fast && fast->next) {
            if(slow == fast)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow != fast)
            return NULL;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    void removeLoop() {
        if(!detectLoop())
            return;
        Node* starting = loopStarting();
        Node* temp = starting;
        while(temp->next != starting)
            temp = temp->next;
        temp->next = NULL;
    }
};

int main() {
    LinkedList test;
    test.insertNode(6);
    test.insertNode(9);
    test.insertNode(4);
    test.printList();

    test.reverse();
    test.printList();
    std::cout << test.detectLoop() << "\n";
    if(test.detectLoop())
        std::cout << test.loopStarting()->value << "\n";
    else
        std::cout << -1 << "\n";

    test.removeLoop();
    test.printList();
    return 0;
}