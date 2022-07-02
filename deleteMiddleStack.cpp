#include<bits/stdc++.h>
using namespace std;

class Stack{
    struct Node{
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
        }
    };
     Node* head = NULL;
     Node* mid = NULL;
     int size = 0;
    public:
        void push(int data);
        int pop();
        int getMiddle();
        int deleteMiddle();
};

void Stack::push(int data){
    // if(size>0){
    //     cout<<"data is :"<<data<<" ";
    //     cout<<"size is :"<<size<<endl;
    //     cout<<"mid is :"<<mid->data<<endl;
    // }
    Node* temp = new Node(data);
    if(size == 0){
        head = temp;
        mid = temp;
        size++;
        cout<<head->data<<" pushed to the stack"<<endl;
        return;
    }
    head->next = temp;
    temp->prev = head;
    head = head->next;

    size++;
    if(size%2 == 1){
        mid = mid->next;
    }
    cout<<head->data<<" pushed to the stack"<<endl;
}

int Stack::pop(){
    if(size == 0){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    // cout<<"poppped out element is :"<<head->data<<endl;

    Node* temp = head;
    int data = temp->data;

    if(size == 1){
        head = NULL;
        mid = NULL;
        size--;
        delete(temp);
        return data;
    }

    head->prev->next = head->next;
    delete(temp);
    size--;
    if(size%2 == 0){
        mid = mid->prev;
    }
    return data;
}

int Stack::getMiddle(){
    if(mid){
        // cout<<"here";
        return mid->data;
    }
    return -1;
}

int Stack::deleteMiddle(){
    if(!mid){
        cout<<"stack is empty"<<endl;
        return -1;
    }

    Node* temp = mid;
    cout<<mid->next->data<<endl;
    int data;
    if(size == 1){
        head = NULL;
        mid = NULL;
        size--;
        data = temp->data;
        delete(temp);
        return data;
    }
    if(size == 2){
        // cout<<"deleted element is :"<<mid->data<<endl;
        mid = mid->next;
        size--;
        data = temp->data;
        delete(temp);
        return data;
    }

    cout<<"here";
    mid->prev->next = mid->next;
    mid->next->prev = mid->prev;
    size--;
    // cout<<"deleted element is :"<<mid->data<<endl;
    if(size%2 == 1){
        mid = mid->next;
    }
    else{
        mid = mid->prev;
    }
    // cout<<"new mid is :"<<mid->data<<" "<<mid->next->data<<endl;
    data = temp->data;
    delete(temp);
    return data;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"the middle element is :"<<s.getMiddle()<<endl;
     cout<<"deleted element is :"<<s.deleteMiddle()<<endl;
    s.push(4);
    cout<<"the middle element is :"<<s.getMiddle()<<endl;
    cout<<"the popped out element is :"<<s.pop()<<endl;
    s.push(5);
    s.push(6);
    // s.push(6);
    cout<<"the middle element is :"<<s.getMiddle()<<endl;
    cout<<"the popped out element is :"<<s.pop()<<endl;
    cout<<"the middle element is :"<<s.getMiddle()<<endl;
    cout<<"deleted element is :"<<s.deleteMiddle()<<endl;
    cout<<"the middle element is :"<<s.getMiddle()<<endl;
    return 0;
}
