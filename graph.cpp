#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph()
{
    cout << "Enter the number of vertices :" << endl;
    int vertices;
    cin >> vertices;

    cout << "Enter the number of edges" << endl;
    int edges;
    cin >> edges;
    vector<vector<int>> adjList(vertices);
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adjList[v1 - 1].push_back(v2);
        adjList[v2 - 1].push_back(v1);
    }

    return adjList;
}

void printGraph(vector<vector<int>> adjList)
{
    cout << "The graph is :" << endl;
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i + 1 << "--> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

void bfsHelper(vector<vector<int>> &adj, map<int,bool> &visited, int node){
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        // cout<<"Size of q is :"<<q.size()<<endl;
        int front = q.front();
        // cout<<"front :"<<front<<endl;
        q.pop();
        if(!visited[front]){
            // cout<<"here"<<endl;
            visited[front] = 1;
            cout<<front<<" ";
            // cout<<adj[node-1].size()<<endl;
            for(int i=0;i<adj[front-1].size();i++){
                q.push(adj[front-1][i]);
            }
        }
    }
    // cout<<"yo"<<endl;
    cout<<endl;
}

void BFS(vector<vector<int>> &adj){
    map<int,bool> visited;
    // vector<int> ans;

    for(int i=0;i<adj.size();i++){
        if(visited[i+1] == 0){
            bfsHelper(adj,visited,i+1);
        }
    }
}

void dfs(vector<vector<int>>& adj , map<int,bool> &visited , int node){
    if(!visited[node]){
        visited[node] = 1;
        cout<<node<<" ";
        for(int i=0;i<adj[node-1].size();i++){
            dfs(adj,visited,adj[node-1][i]);
        }
    }
}

void DFS(vector<vector<int>> &adj){
    map<int,bool> visited;

    for(int i=0;i<adj.size();i++){
        cout<<"here"<<endl;
        if(!visited[i+1]){
            dfs(adj,visited,i+1);
        }
    }
}

int main()

{
    vector<vector<int>> adjList = createGraph();
    printGraph(adjList);
    BFS(adjList);
    DFS(adjList);
    cout<<endl;
    return 0;
}