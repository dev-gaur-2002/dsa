#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;
    public:
        void push(int data);
        bool pop();
};

void Stack::push(int data){
    q.push(data);
    for(int i=0;i<q.size()-1;i++){
        q.push(q.front());
        q.pop();
    }
}

bool Stack::pop(){
    if(q.size() == 0){
        cout<<"stack is empty"<<endl;
        return false;
    }
    cout<<"popped out element is :"<<q.front()<<endl;
    q.pop();
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