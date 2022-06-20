#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1,q2;
    public:
        void push(int data);
        bool pop();
};

void Stack::push(int data){
    q1.push(data);
}

bool Stack::pop(){
    if(q1.size() == 0){
        cout<<"the stack is empty";
        return false;
    }
    if(q1.size() == 1){
        cout<<"the data popped out is :"<<q1.front()<<endl;    
        return true;
    }
    while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
    }
    cout<<"the data popped out is :"<<q1.front()<<endl;
    q1.pop();
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    return true;
}


int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.push(5);
    s.pop();
    s.push(6);
    s.push(7);
    s.push(8);
    s.pop();
    return 0;
}