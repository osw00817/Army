#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> A(n,0);
    vector<int> ans(n,0);

    for(int i = 0;i<n;i++) {
        cin >> A[i];
    }

    stack<int> myStack;
    myStack.push(0);

    for(int i = 1;i<n;i++) {
        while(!myStack.empty() && A[myStack.top()] < A[i]) {
            ans[myStack.top()] = A[i];
            myStack.pop();
        }
        myStack.push(i);
    }
    while(!myStack.empty()) {
        ans[myStack.top()] = -1;
        myStack.pop();
    }

    for(int i = 0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }

    // 알고리즘 자체는 이해를 했으나 이걸 어떻게 생각해내지 라는 생각이 드는 알고리즘
    // stack을 사용함에 있어 값을 담지말고 인덱스를 담을수도 있다는 발상
    return 0;
}
