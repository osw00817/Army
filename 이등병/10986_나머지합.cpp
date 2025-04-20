#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    long cnt = 0;
    cin >> N >> M;

    vector<long> S(N,0);
    vector<long> R(M,0);
    cin >> S[0];
    
    for(int i = 1;i<N;i++) {
        int tmp;
        cin >> tmp;
        S[i] = S[i-1] + tmp;
    }

    for(int i = 0;i<N;i++) {
        int remain = S[i] % M;
        if(remain == 0)
            cnt++;
        R[remain]++;
    }

    for(int i = 0;i<M;i++) {
        if(R[i] > 1){
            cnt += R[i] * (R[i]-1) / 2;
        }
    }
    cout << cnt;
    return 0;
}
