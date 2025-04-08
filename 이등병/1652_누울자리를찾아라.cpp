#include <iostream>
#include <string>
using namespace std;

int main() {
    int loop;
    std::cin >> loop;

    //char 2차원 배열 할당 및 초기화
    char *room = new char[loop];
    for(int i = 0;i<loop;i++) {
        room[i] = new char[loop];
        fill_n(room[i],loop,0);
        for(int j = 0;j<M;j++)
            cin>>room[i][j];
    }

    /*
    무조건 벽이나 짐에 닿아야하므로 *과 시작점 위주로 보면 될꺼같음. 
    내일 일과 하면서 시간 날때 생각해두기
        */

    //hanging tree - jennifer lawrence (macon's HYPERTECHNO remix) [Extended]
    //듣다가 내일 이어서 들을 노래(좋진않음)
    
    delete []room;
    // 메모리 할당 해제하는것도 수정해야함 내일
    return 0;
}
