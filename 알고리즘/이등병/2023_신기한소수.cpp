#include <iostream>
#include <vector>
using namespace std;

static int n;
void DFS(int number,int jarisu);
bool primie(int num);

//골드임에도 생각보다 쉬웠던 문제.
// 물론 혼자 풀었을때는 약간의 수학적 오류가 있었지만 
// 책보고 오류를 고친뒤 풀었다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
    return 0;
}

void DFS(int number,int jarisu) {
    if(jarisu == n) {
        if(primie(number))
            cout << number << endl;
        return;
    }

    for(int i:{1,3,5,7,9}) {
        if(primie(10*number + i))
            DFS(10*number + i,jarisu+1);
    }
    
}

bool primie(int num) {
    for(int i = 2;i<=num/2;i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}