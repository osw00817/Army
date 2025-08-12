#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
입력

도시 개수, 도로 개수,거리 정보,출발 도시 번호 
*/
void BFS(int node);
vector<vector<int>> A;
vector<int> visited;
vector<int> answer;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long dosi,doro,guri,chulbal;
    cin >> dosi >> doro >> guri >> chulbal;
    A.resize(dosi + 1);
    for(int i = 0;i<doro;i++) {
        int c,d;
        cin >> c >> d;
        A[c].push_back(d);
    }
    visited.resize(dosi+1);

    for(int i = 1;i<=dosi;i++) {
        visited[i] = -1;
    }
    
    BFS(chulbal);

    for(int i = 1;i<=dosi;i++) {
        if(visited[i] == guri) {
            answer.push_back(i);
        }
    }

    if(answer.empty()) {
        cout << -1 << "\n";
    }
    else {
        sort(answer.begin(),answer.end());
        for(int i: answer) {
            cout << i << "\n";
        }
    }
    
    return 0;
}

void BFS(int node) {
    queue<int> queue;
    queue.push(node);
    visited[node]++;

    while(!queue.empty()) {
        int tmp = queue.front();
        queue.pop();
        for(int i: A[tmp]) {
            if(visited[i] == -1) {
                visited[i] = visited[tmp] + 1;
                queue.push(i);
            }
        }
    }
}

// 오랜만에 하니깐 cin 안받고 알고리즘 다 짜두고 왜 안되지 이러고 있었음..
