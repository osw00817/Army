#include <iostream>
#include <string>
#include <vector>
using namespace std;

//선택정렬로 풀기
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;

    vector<int> A(s.size());
    for(int i = 0;i<s.size();i++) {
        A[i] = stoi(s.substr(i,1));
    }

    for(int i = 0;i<A.size()-1;i++) {
        //여기서 max = i 로 지정하는게 일반적이지만, 그냥 난 이렇게 했다.
        int max = -1;
        for(int j = i+1;j<A.size();j++) {
            max = (max == -1 || A[max] < A[j]) ? j : max;
        }
        
        if(A[max] > A[i] && max){
            int tmp = A[max];
            for(int j=max;j>i;j--){
                A[j] = A[j-1];
            }
            A[i] = tmp;
        }
    }

    for(int i = 0;i<A.size();i++) {
        cout << A[i];
    }
    
    return 0;
}
