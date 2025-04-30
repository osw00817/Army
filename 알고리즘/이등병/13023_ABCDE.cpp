#include <iostream>
#include <vector>
using namespace std;

void DFS(int s,int d);
vector<bool> visited;
vector<vector<int>> A;
bool friends;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,e;
    friends = false;
    cin >> n >> e;
    
    A.resize(n);
    visited = vector<bool>(n,false);
    
    for(int i = 0;i<e;i++) {
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    
    for(int i = 0;i<n;i++) {
        DFS(i,1);
        if(friends)
            break;
    }

    if(friends)
        cout << 1 << "\n";
    else 
        cout << 0 << "\n";
    
    return 0;
}

void DFS(int s,int d) {
    //s: start_node, d:depth
    if(d == 5 || friends) {
        friends = true;
        return;
    } 
    
    visited[s] = true;
    for(int i : A[s]) {
        if(!visited[i])
            DFS(i,d+1);
    }
    visited[s] = false;
}

//진짜 레전드 의문점
//아래와 같이 동작을 해도 연산과정이 더 많아지고 오래걸린다해도 결국 결과값은
//같아야한다고 생각함. 틀리는 이유가 유추는 가능하나 받아들일수가없음.
//visited 배열을 재귀함수가 공유하는 과정에서 생기는 문제 같은데 
//이게 맞는지도 맞아도 어떤식으로 오류가 발생하는건지 모르겠음.
//이거 문제가 뭔지 해결해줄 사람 구함

/*

void DFS(int s,int d) {

    //s: start_node, d:depth
    
    if(d == 5 || friends) {
        if(!visited[i])
            friends = true;
        return;
    } 
    
    visited[s] = true;
    
    for(int i : A[s]) {
        DFS(i,d+1);
    }
    
    visited[s] = false;
}
*/