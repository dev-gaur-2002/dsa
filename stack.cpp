#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack{
public:
    int top;
    Stack(){ // contructor
        top = -1;
    }
    int a[MAX];
     

    bool push(int data);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int data){
    if(top == MAX-1){
        cout<<"stack is full"<<endl;
        return false;
    }
    top++;
    a[top] = data;
    return true;
}

int Stack::pop(){
    if(top == -1){
        cout<<"the stack is empty"<<endl;
        return -1;
    }
    top--;
    return a[top+1];
}

int Stack::peek(){
    if(top == -1){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return a[top];
}
bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

class SpecialStack{
        Stack min;
    public:
        void push(int data);
        bool pop();
        int getMin();
};

void SpecialStack::push(int data){
    if(min.top == -1){
        min.push(data);
    }
    else{
        if(data<min.peek()){
            min.push(data);
        }
    }
}

bool SpecialStack::pop(){
    if(min.top == -1){
        return false;
    }
    min.pop();
    return true;
}

int SpecialStack::getMin(){
    if(min.isEmpty()){
        return -1;
    }
    return min.peek();
}


int main()
{
    // Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // // cout<<"popped out element is :"<<s.pop()<<endl;

    // cout<<"The elements of stack are :"<<endl;
    // while(s.top>-1){
    //     cout<<s.peek()<<" ";
    //     s.pop();
    // }
    // cout<<endl;
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin();
    return 0;
}