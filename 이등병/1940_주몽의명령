#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N,M,cnt = 0;
    
    cin >> N >> M;
    
    vector<int> material(N,0);    
    for(int i = 0;i<N;i++) {
        cin >> material[i];
    }
    sort(material.begin(),material.end());

    int i = 0,j = N-1;
    while(i < j) {
        int sum = material[i] + material[j];
        //cout << sum << ' ' << i << ':' << material[i] << ' ' << j << ':' << material[j] << '\n';
        if(sum == M) {
            cnt++;
            i++;
            j--;
        }
        else if(sum > M) {
            j--;
        }
        else {
            i++;
        }
    }
    cout << cnt;
    return 0;
}
