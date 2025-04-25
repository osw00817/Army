5#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int sum,cnt,num,start,end;
    cnt = 1;
    sum = 1;
    start = 1;
    end = 1;

    cin >> num;

    while(end != num) {
       if(num == sum) {
           cnt++;
           end++;
           sum += end;
       }
        else if(num > sum) {
            end++;
            sum += end;
        }
        else {
            sum -= start;
            start++;
        }
        //cout << start << ' ' << end << ' '<< sum << ' '<< cnt << '\n';
    }
    
    cout << cnt;
    return 0;
}
