#include <iostream>
#include <vector>
using namespace std;

/*
4 3
0
2 1 2
1 3
3 2 3 4
    */

vector<int> ppl;
vector<int> truther;
vector<vector<int>> party;
int result;
void unionf(int a,int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    result = 0;
    
    int n,m;
    int t;
    
    cin >> n >> m;
    cin >> t;
    
    truther.resize(t);
    ppl.resize(n+1);
    party.resize(m);

    // 진실을 아는 사람 리스트 초기화
    for(int i = 0;i<t;i++) {
        cin >> truther[i];
    }
    // 사람들 초기화
    for(int i = 1;i<=n;i++) {
        ppl[i] = i;
    }
    //파티 참여자들 넣기
    for(int i = 0;i<m;i++) {
        int party_size;
        cin >> party_size;
        for(int j=0;j<party_size;j++) {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }
    //유니온 존나하기
    for(int i = 0;i<m;i++) {
        int firstppl = party[i][0];
        for(int j = 1;j<party[i].size();j++) {
            unionf(firstppl,party[i][j]);
        }
    }
    
    for(int i = 0;i<m;i++) {
        bool success = true;
        int cur = party[i][0];
        for(int j = 0;j<t;j++) {
            if(find(cur) == find(truther[j])) {
                success = false;
                break;
            }
        }
        if(success) {
            result++;
        }
    }
    cout << result;
    return 0;
}

int find(int a) {
    if(a==ppl[a]) {
        return a;
    }
    return ppl[a] = find(ppl[a]);
}
void unionf(int a,int b) {
    a = find(a);
    b = find(b);

    if(a!=b) {
        ppl[b] = a;
    }
}

//성공한거

// 아래는 실패한거 합칠라다가 실패함

#include <iostream>
#include <vector>
using namespace std;

vector<int> ppl;
vector<int> truther;
vector<int> first_ppl;
int result;
void unionf(int a,int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    result = 0;
    
    int n,m,t;
    
    cin >> n >> m >> t;
    
    truther.resize(t);
    ppl.resize(n+1);
    first_ppl.resize(m+1);

    // 진실을 아는 사람 리스트 초기화
    for(int i = 0;i<t;i++) {
        cin >> truther[i];
    }
    
    // 사람들 초기화
    for(int i = 1;i<=n;i++) {
        ppl[i] = i;
    }
    //파티 참여자들 넣고 바로 유니온 어디가 잘못됬는지 파악이 안됨;; 아
    for(int i = 0;i<m;i++) {
        int party_size;
        cin >> party_size;
        if(party_size > 0) {
            int first_person;
            cin >> first_person;
            first_ppl.push_back(first_person);
            for(int j = 1;j<party_size;j++) {
                int next_person;
                cin >> next_person;
                unionf(first_person,next_person);
            }
        }
    }
    
    for(int i = 0;i<m;i++) {
        bool success = true;
        int cur = first_ppl[i];
        for(int j = 0;j<t;j++) {
            if(find(cur) == find(truther[j])) {
                success = false;
                break;
            }
        }
        if(success) {
            result++;
        }
    }
    cout << result;
    return 0;
}

int find(int a) {
    if(a==ppl[a]) {
        return a;
    }
    return ppl[a] = find(ppl[a]);
}
void unionf(int a,int b) {
    a = find(a);
    b = find(b);

    if(a!=b) {
        ppl[b] = a;
    }
}
