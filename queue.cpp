#include<iostream>
#include<vector>
#include<list>
using namespace std;


// using linked list
class queue {
    class Node {
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:

    queue(){
        head = tail = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(isEmpty()){
        cout << "Queue is empty\n";
        return;
        }
        Node* temp = head;
        head = head -> next;
        if(head == NULL){   
        tail = NULL;
        }
        temp -> next = NULL;
        delete temp;
    }

    int front(){
        if(isEmpty()){
        cout << "Queue is empty\n";
        return -1;
        }
        return head -> data;
    }

    bool isEmpty(){
        return head == NULL;
    }
    

};

// Using circular array
class Queue{
public:
    int* arr;
    int capacity;
    int currSize;

    int f,r;

    Queue(int capacity){
        this -> capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }

    void push(int data){
        if(currSize == capacity){
            cout<<"queue is full"<<endl;
            return;
        }
        if(currSize == 0){
        f = 0;  
        }
        r = (r+1)%capacity;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        if(currSize == 1){
            f = r = -1;   
        } else {
            f = (f + 1) % capacity;
        }
        currSize--;
    }

    int front(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool isEmpty(){
        return currSize == 0;
    }
};

void print(Queue q){
    while(!q.isEmpty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main(){
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(5);
    print(q);
    return 0;

}