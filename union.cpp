#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int ranks[1000];

void make_set(){
    for(int i=0;i<1000;i++){
        parent[i] = i;
    }
    for(int i=0;i<1000;i++){
        ranks[i] = 0;
    }
}

int getParent(int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = getParent(parent[node]);
}

void unionFunc(int node1, int node2){
     node1 = getParent(node1);
     node2 = getParent(node2);

    if(ranks[node1] > ranks[node2]){
        parent[node2] = node1;
    }

    else if(ranks[node2] > ranks[node1]){
        parent[node1] = node2;
    }

    else{
        parent[node1] = node2;
        ranks[node2]++;
    }
}

bool check(int node1, int node2){
    if(getParent(node1) == getParent(node2)){
        return true;
    }

    return false;
}

int main()
{
    make_set();
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        unionFunc(a,b);
    }           

    cout<<check(2,3)<<endl;

    return 0;
}