#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    방법 크게 2개로 생각됨.
    받고 정렬 후 합배열 생성후 찾기
    받고 투포인터 사용해서 와르르 찾기
        */
    int N;
    cin >> N;
    vector<long> A(N,0);
    for(int i = 0;i<N;i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    
    int cnt = 0;
    for(int z = 0;z<N;z++) {
        //문제점: 반복문 진입 조차 안되는중
        //N을 입력안받은거였음 ㅋㅋ
        long goal = A[z];
        int i = 0,j = N-1;
        while(i < j) {
            //cout << goal << ' ' << A[i]+A[j] << '\n';
            if(A[i]+A[j] == goal) {
                //책 보고 꺠우친 내용
                //입력값에 0이 있는 경우 같은수가 있을수도 있기때문에 이를 제외하여야한다.
                if(i != z && j != z) {
                    cnt++;
                    break;
                }
                else if(i == z) {
                    i++;
                }
                else if(j == z) {
                    j--;
                }
            }
            else if(A[i]+A[j] < goal) {
              i++;
            }
            else {
                j--;
            }
        }
    }
    cout << cnt;
    return 0;

}
