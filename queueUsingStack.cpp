#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    stack<int> s1,s2;
    bool enqueue(int data);
    bool dequeue();
};

bool Queue::enqueue(int data){
    s1.push(data);
    return true;
}
bool Queue::dequeue(){
    if(s1.empty()){
        cout<<"queue is empty"<<endl;
        return false;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int data = s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    cout<<"data is :"<<data<<endl;
    return data;
    return true;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.dequeue();

    return 0;
}