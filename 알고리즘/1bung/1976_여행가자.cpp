#include <iostream>
#include <vector>
using namespace std;
/*
레전드 휴대폰 타자로 침.
  */

vector<int> cities;
void unionf(int a,int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int m;
    cin >> m;
    
    cities.resize(n+1);
    for(int i=1;i<=n;i++){
        cities[i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            cin >> tmp;
            if(tmp==1){
                unionf(i,j);
            }
        }
    }
    
    int tmp;
    cin >> tmp;
    
    int start = find(cities[tmp]);
    bool connect = true;
    
    for(int i=1;i<m;i++){
        cin >> tmp;
        if(start!=find(cities[tmp])){
            cout<<"NO"<<"\n";
            connect = false;
            break;
        }
    }
    
    if(connect){
        cout << "YES"<<"\n";
    }
}
int find(int a){
    if(cities[a]==a){
        return a;
    }
    return cities[a] = find(cities[a]);
}
void unionf(int a,int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        cities[b] = a;
    }
}
