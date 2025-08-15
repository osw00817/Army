#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);
vector<vector<int>> A;
vector<int> answer;
vector<bool> visited;


/*
5 4
3 1
3 2
4 3
5 3
    */

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long N, E;
    cin >> N >> E;
    A.resize(N+1);
    answer.resize(N+1);
    visited.resize(N+1);

    for(int i = 0;i<E;i++) {
        int a,b;
        cin >> a >> b;

        A[a].push_back(b);
    }

    for(int i = 1;i<=N;i++) {
        fill(visited.begin(),visited.end(),false);
        BFS(i);
    }
    
    int maxVal = 0;
    for(int i = 1;i<=N;i++) {
        maxVal = max(maxVal,answer[i]);
    }
    
    for(int i = 1;i<=N;i++) {
        if(maxVal == answer[i]) {
            cout << i << " ";
        }
    }
    return 0;
}

void BFS(int node) {
    queue<int> queue;
    queue.push(node);
    visited[node] = true;

    while(!queue.empty()) {
        int tmp = queue.front();
        queue.pop();
        for(int i:A[tmp]) {
            if(visited[i] == false) {
                visited[i] = true;
                queue.push(i);
                answer[i]++;
            }
        }
    }
}
