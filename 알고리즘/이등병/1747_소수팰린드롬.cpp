#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int num;
    std::cin >> num;  
    int list[1500001];
    
    for(int i = 2;i<1500000;i++) {
        list[i] = i;
    }
    
    for(int i = 2;i<=sqrt(1500000);i++) {
        if(list[i] == 0)
            continue;
        for(int j = i*i;j<=1500000;j+=i)
            list[j] = 0;
    }

    for(int i = num;i<=1500000;i++) {
        if(list[i] != 0) {
            string tmp = to_string(list[i]);
            int size = 0;
            int tmp1 = list[i];
    
            while(tmp1 > 0) {
                tmp1 /= 10;
                size++;
            }
            bool pass = true;
            
            //팰린드론 검사
            for(int j=0;j<(size%2==1 ? size/2+1 : size/2);j++) {
                if(tmp[j] != tmp[size-1-j]) {
                    pass = false;
                    j = size;
                    continue;
                }
            }
           if(pass) {
               std::cout << tmp;
               return 0;
           }
               
        }
    }
    return 0;

/*
느낀점
오랜만에 하니깐 진짜 문제 안풀리고
그냥 뇌가 굳은듯?

반례 찾으면서 디버깅 하는 감각이 사라졌노
*/

}
