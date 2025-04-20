#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size,loop;
    cin >> size >> loop;
    vector<vector<int>> S(size+1,vector<int>(size+1,0));;
    
    for(int i = 1;i <=size;i++) {
        for(int j = 1;j<=size;j++) {
            int tmp;
            cin >> tmp;
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + tmp;;
        }
    }

    while(loop--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] + S[x1-1][y1-1] - S[x2][y1-1] - S[x1-1][y2] << '\n';
    }
    
    return 0;
}
