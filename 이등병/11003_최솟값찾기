#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> Node;

//이때까지 부분합 구하거나 투포인터,슬라이싱에 대해 배움
//자료구조 스택,큐,덱,우선순위 큐에 대해 배울차례
// 덱이란? -> 대충 node들로 이루어진 리스트임. 앞뒤에서 노드들 뺴고 더하는거인듯.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,L;
    cin >> N >> L;
    deque<Node> mydeque;
    
    //너무 어려워서 거의 책 보고함..
    // 일반적으로 입력을 한개씩 받으면서 계속 정렬하면서 진행하는 방식을 생각함
    // 그러면 시간복잡도가 n^2 * long n 임.
    // 덱을 쓰면 n^2으로 끝내버림.
    
    for(int i = 0;i<N;i++){
        int now;
        cin >> now;

        while(mydeque.size() && mydeque.back().first > now){
            mydeque.pop_back();
        }
        mydeque.push_back(Node(now,i));

        if(mydeque.front().second <= i-L)
            //i-L+1부터가 포함 범위이므로 i-L 부터는 삭제
            mydeque.pop_front();

        cout << mydeque.front().first << " ";
    }

    return 0;
}
