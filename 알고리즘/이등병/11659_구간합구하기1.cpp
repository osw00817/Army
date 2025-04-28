#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    이렇게 하는게 더 빠름.
      */
    int size,loop;
    cin >> size >> loop;

    int s[100001] = {};
    s[0] = 0;
    
    for(int i = 1;i<=size;i++) {
        int tmp;
        cin >> tmp;
        s[i] = s[i-1] + tmp;
    }
    
    while(loop--) {
        int start,end;
        cin >> start >> end;
        cout << s[end]-s[start-1] << "\n";
    }
    return 0;
}
