#include <iostream>
#include <queue>
using namespace std;

//2164_카드2

int main() {
    int n;
    cin >> n;

    queue<int> cards;

    for(int i = 1;i<=n;i++) {
        cards.push(i);
    }
    
    while(cards.size() > 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
    
    cout << cards.front();
    return 0;
}