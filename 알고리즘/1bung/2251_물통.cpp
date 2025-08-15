2025.08.15 업뎃#include <iostream>
#include <queue>
using namespace std;

/*
8 9 10
아 다 했는데 갑자기 가용당해서 저장안하고 꺼버림..

Max_Water[3]
Current_Water[3]
visited[201][201]
answer[201]
*/

void BFS();
int Max_Water[3];
bool visited[201][201];
bool answer[201];
int Sender[] = {0,0,1,1,2,2};
int Recevier[] = {1,2,0,2,0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Max_Water[0] >> Max_Water[1] >> Max_Water[2];

    BFS();

    for(int i = 0;i<201;i++) {
        if(answer[i]) {
            cout << i << " ";
        }
    }
    
    return 0;
}

void BFS() {
    visited[0][0] = true;
    answer[Max_Water[2]] = true;
    queue<pair<int,int>> PList;
    PList.push(make_pair(0,0));

    while(!PList.empty()) {
        pair<int,int> Current_Water = PList.front();
        PList.pop();
        int A = Current_Water.first;
        int B = Current_Water.second;
        int C = Max_Water[2] - A - B;

        for(int i = 0;i<6;i++) {
            int Next_Water[] = {A,B,C};
            Next_Water[Recevier[i]] += Next_Water[Sender[i]];
            Next_Water[Sender[i]] = 0;

            if(Next_Water[Recevier[i]] > Max_Water[Recevier[i]]) {
                //여기 아래 연산이 이상해서 하루종일 고생했음, 틀렸던 이유를 몰라서 결국 답지 봄;; 
                //바보짓 레전드
                Next_Water[Sender[i]] = Next_Water[Recevier[i]] - Max_Water[Recevier[i]];
                Next_Water[Recevier[i]] = Max_Water[Recevier[i]];
            }

            if(!visited[Next_Water[0]][Next_Water[1]]) {
                if(Next_Water[0] == 0) {
                    answer[Next_Water[2]] = true;
                }
                visited[Next_Water[0]][Next_Water[1]] = true;
                PList.push(make_pair(Next_Water[0],Next_Water[1]));
            }
        }
    }
}
