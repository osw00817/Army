#include <iostream>
#include <queue>
using namespace std;

//11286_절댓값힙

struct compare {
    bool operator()(int o1,int o2) {
        int first_abs = abs(o1);
        int second_bas = abs(o2);
        if(first_abs == second_bas) {
            return o1 > o2;
            // o1이 작으면 false, 즉 내림차순정렬임.
            // O1,O2 에서 true인경우 o1이 우선순위가 낮음을 의미
            // o1,o2에서 false이므로 o1이 우선순위가 높음을 의미
        } else {
            return first_abs > second_bas;
        }
    }
};

//비교 함수는 다음과 같은 구조임, 구조체 => bool operator(구현체) => true이면 앞의것이 우선순위가 낮음

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //우선순위 큐 선언 방식: <자료형,구현체,비교 함수명>
    priority_queue<int,vector<int>,compare> MyQueue;

    int N;
    cin >> N;

    for(int i = 0;i<N;i++) {
        int request;
        cin >> request;

        if(request == 0) {
            if(MyQueue.empty()) {
                cout << "0\n";
            } else {
                cout << MyQueue.top() << "\n";
                MyQueue.pop();
            }
        } else {
            MyQueue.push(request);
        }
    }
    
    return 0;
}