#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int v);
void BFS(int node);
vector<vector<int>> A;
vector<bool> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node,edge,start;
    cin >> node >> edge >> start;

    A.resize(node+1);
    
    for(int i = 0;i<edge;i++) {
        int s,e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    for(int i = 1;i<=node;i++) {
       sort(A[i].begin(),A[i].end());
    }
    
  
    //DFS 
    visited = vector<bool>(node+1,false);
    DFS(start);
    
    cout << "\n";
    
    
    //BFS 
    visited = vector<bool>(node+1,false);
    BFS(start);
    
    return 0;
}

void DFS(int v) {
    
    if(visited[v])
        return;
    
    cout << v << " ";
    
    visited[v] = true;
    
    for(int i: A[v]) {
        if(!visited[i]) {
            DFS(i);
        }
            
    }
}

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()) {
        int now = myqueue.front();
        myqueue.pop();
        cout << now << " ";
        for(int i : A[now]) {
            if(!visited[i]) {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}