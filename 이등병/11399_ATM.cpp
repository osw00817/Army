#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> S(n,0);
    
    for(int i = 0;i<n;i++) {
        cin >> A[i];
    }

    for(int i = 1;i<A.size();i++) {
        int insert_value = A[i];
        int insert_point = i;
        for(int j = i-1;j>=0;j--) {
            if(A[j] > insert_value) {
                insert_point = j;
            }
        }
        for(int j=i;j>insert_point;j--) {
            A[j] = A[j-1];
        }
        A[insert_point] = insert_value;
    }

    S[0] = A[0];
    int sum = S[0];
    for(int i = 1;i<A.size();i++){
        S[i] += S[i-1] + A[i];
        sum += S[i];
    }

    cout << sum;
    return 0;
}
