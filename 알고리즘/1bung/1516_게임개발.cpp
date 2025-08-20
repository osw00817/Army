#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> prior;
    vector<int> build_time;
    vector<int> indegree;
    vector<int> answer;
    
    int N;
    cin >> N;
    build_time.resize(N+1);
    prior.resize(N+1);
    indegree.resize(N+1);
    answer.resize(N+1);
    for(int i = 1;i<=N;i++) {
        indegree[i] = 0;
        answer[i] = 0;
    }
    for(int i = 1;i<=N;i++) {
        cin >> build_time[i];
        int tmp;
        cin >> tmp;
        while(tmp != -1) {
            prior[tmp].push_back(i);
            indegree[i]++;
            cin >> tmp;
        }
    }
    
    queue<int> wait;
    for(int i = 1;i<=N;i++) {
        if(indegree[i] == 0) {
            wait.push(i);
        }
    }
    while(!wait.empty()) {
        int now = wait.front();
        wait.pop();
        for(int next: prior[now]) {
            indegree[next]--;
            answer[next] = max(answer[next],answer[now] + build_time[now]);
            // 그니깐 건물 두개가 있으면 둘이 동시에 짓는다치면 더 오래걸리는거만 영향이 간다고 계산하는거임
            // 조건을 이렇게 숨겨두면 무슨 하.. 내가 문제를 잘못 읽은건가 예시 통해서 알았네 이게 말이되나;;
            if(indegree[next]==0) {
                wait.push(next);
            }
        }
    }
    for(int i = 1;i<=N;i++) {
        cout << answer[i]+build_time[i] << "\n";
    }
}

/*
    중복이 생기는 잘못된 코드의 예시임. ㅇㅇ
    int N;
    cin >> N;
    build_time.resize(N+1);
    prior.resize(N+1);
    answer.resize(N+1);
    for(int i = 1;i<=N;i++) {
        cin >> build_time[i];
        int tmp;
        cin >> tmp;
        while(tmp != -1) {
            prior[i].push_back(tmp);
            cin >> tmp;
        }
    }
    for(int i = 1;i<=N;i++) {
        answer[i] = 0;
    }
    for(int i = 1;i<=N;i++) {
        queue<int> wait;
        wait.push(i);
        while(!wait.empty()) {
            int next = wait.front();
            wait.pop();
            answer[i] += build_time[next];
            for(int need_build : prior[next]) {
                wait.push(need_build);
            }
        }
        //아 이렇게하면 중복 생김. 
    }
    for(int i = 1;i<=N;i++) {
        cout << answer[i] << "\n";
    }
    return 0;
*/
