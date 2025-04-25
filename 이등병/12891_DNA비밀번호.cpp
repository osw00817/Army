#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> code(4,0); //암호충족조건
vector<int> slice(4,0); //슬라이싱문자열
int cnt = 0; //4이면 암호충족
void add(char c);
void remove(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // s: 총 문자열 , p: 암호문자열길이
    int s,p,result = 0;
    cin >> s >> p;
    string dna;
    cin >> dna;

    //암호충족조건 초기화
    for(int i = 0;i<4;i++) {
        cin >> code[i];
        if(code[i] == 0)
            cnt++;
    }

    //기본 슬라이싱 문자열 초기화
    for(int i = 0;i<p;i++) {
        add(dna[i]);
    }

    //초기화된 문자열 암호충족여부확인
    if(cnt == 4)
        result++;

    //하나씩 뺴고 추가하며 충족여부 확인
    for(int i = 0;i<s-p;i++) {
        remove(dna[i]);
        add(dna[i+p]);
        if(cnt == 4)
            result++;
    }

    cout << result;
    return 0;
}

void add(char c) {
    switch (c) {
        case 'A':
            slice[0]++;
            if(slice[0] == code[0])
                cnt++;
            break;
        case 'C':
            slice[1]++;
            if(slice[1] == code[1])
                cnt++;
            break;
        case 'G':
            slice[2]++;
            if(slice[2] == code[2])
                cnt++;
            break;
        case 'T':
            slice[3]++;
            if(slice[3] == code[3])
                cnt++;
            break;
            
    }
}

void remove(char c) {
     switch (c) {
        case 'A':
            if(slice[0] == code[0])
                cnt--;
            slice[0]--;
            break;
        case 'C':
            if(slice[1] == code[1])
                cnt--;
            slice[1]--;
            break;
        case 'G':
           if(slice[2] == code[2])
                cnt--;
            slice[2]--;
            break;
        case 'T':
           if(slice[3] == code[3])
                cnt--;
            slice[3]--;
            break;
    }
}
