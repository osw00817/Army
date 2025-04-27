#include <iostream>
#include <vector>
using namespace std;

//계수 정렬 ㄹㅈㄷ
//기수 정렬은 좀 복잡할듯
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> A(10001,0);
    int num;
    for(int i = 0;i<n;i++) {
        cin >> num;
        A[num]++;
    }

    for(int i = 0;i<10001;i++) {
        if(A[i] != 0) {
            for(int j = 0;j<A[i];j++) {
                cout << i << "\n";
            }
        }
    }
    return 0;
}
