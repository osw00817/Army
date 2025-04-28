#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,e;
    cin >> n >> e;

    A.resize(n+1);
    visited = vector<bool>(n+1,false);
    
    for(int i = 0;i<e;i++) {
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    int cnt = 0;

    for(int i = 1;i<n+1;i++) {
        if(!visited[i]) {
            DFS(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}

void DFS(int start) {
    if(visited[start])
        return;

    visited[start] = true;
    
    for(int i : A[start]) {
        if(!visited[i]) {
            DFS(i);
        }
    }
    
}
