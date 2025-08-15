#include <iostream>
#include <vector>
using namespace std;

void DFS(int node);
vector<vector<int>> A;
vector<int> check;
vector<bool> visited;
bool IsEven;


/*
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
    */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int loop;
    cin >> loop;

    for(int t=0;t<loop;t++) {
        int N,E;
        cin >> N >> E;
        A.resize(N+1);
        check.resize(N+1);
        visited.resize(N+1);
        IsEven = true;
        for(int i = 0;i<E;i++) {
            int a,b;
            cin >> a >> b;
            A[a].push_back(b);
            A[b].push_back(a);
        }
        for(int i = 1;i<=N;i++) {
            if(IsEven) {
                DFS(i);
            } else {
                break;
            }
        }
        if(IsEven) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

        for(int i = 0;i<=N;i++) {
            A[i].clear();
            check[i] = 0;
            visited[i] = false;
        }
    }
    return 0;
}

void DFS(int node) {
    visited[node] = true;

    for(int i : A[node]) {
        if(!visited[i]) {
            check[i] = (check[node] + 1) % 2;
            DFS(i);
        } else if (check[node] == check[i]) {
             IsEven = false;
        }
    }
}
