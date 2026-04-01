#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL; 
    }

    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* splitatMid(Node* &head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) prev->next = NULL;

    return slow;
}

Node* merge(Node* &left, Node* &right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }

    Node* result = ans.head;
    ans.head = NULL;  // IMPORTANT FIX
    return result;
}

Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rightHead = splitatMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

int main(){
    List ll;

    ll.push_back(4);
    ll.push_back(2);
    ll.push_back(1);
    ll.push_back(3);

    cout << "Original List: ";
    ll.print();

    ll.head = mergeSort(ll.head);

    cout << "Sorted List: ";
    ll.print();

    return 0;
}