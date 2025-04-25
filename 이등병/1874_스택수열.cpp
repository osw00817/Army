#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int loop;
    cin >> loop;
    int tmp = 0;
    stack<int> myStack;
    vector<char> result;
    bool fail = false;
    
    while(loop--) {
        int num;
        cin >> num;
        while(tmp < num) {
            myStack.push(++tmp);
            result.push_back('+');
        }
        if(myStack.top() == num) {
            myStack.pop();
            result.push_back('-');
        } else {
            fail = true;
        }
        //이렇게 하는것도 좋지만 시간복잡도를 더 줄일수있음
        //즉 tmp < num 인지 확인하고 위 과정을 처리하고
        // tmp >= num이면 빼는과정만 수행하는식임.
    }

    if(fail) {
        cout << "NO";
    } else {
        for(int i = 0;i<result.size();i++) {
            cout << result[i] << "\n";
        }
    }
    return 0;
}
