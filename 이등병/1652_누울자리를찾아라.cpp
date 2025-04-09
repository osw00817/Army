#include <iostream>
#include <string>
using namespace std;

int main() {
    int loop;
    std::cin >> loop;

    //char 2차원 배열 할당 및 초기화
    char **room = new char*[loop];
    
    for(int i = 0;i<loop;i++) {
        room[i] = new char[loop];
        fill_n(room[i],loop,0);
        for(int j = 0;j<loop;j++)
            cin>>room[i][j];
    }

    //1과2는 예외처리
    if(loop == 1)
        std::cout << "0 0";
    if(loop == 2)
        std::cout << "2 2";
    
    int x_lie = 0;
    int y_lie = 0;
    
    for(int x = 0;x<loop;x++) {
        for(int y = 0;y<loop;y++) {
            if(y == 0 && room[x][y] != 'X' && room[x][y+1] != 'X')
                y_lie++;
            if(y==loop-1 && room[x][y] != 'X' && room[x][y-1] != 'X')
                y_lie++;
            if(x == 0 && room[x][y] != 'X' && room[x+1][y] != 'X')
                x_lie++;
            if(x == loop-1 && room[x][y] != 'X' && room[x-1][y] != 'X')
                x_lie++;
            if(room[x][y] == 'X') {
                if(x>=3 && x<=loop-4) {
                    if(room[x-1][y] != 'X' && room[x-2][y] != 'X')
                        x_lie++;
                    if(room[x+1][y] != 'X' && room[x+2][y] != 'X')
                        x_lie++;
                }
                if(y>=3 && y<=loop-4) {
                    if(room[x][y-1] != 'X' && room[x][y-2] != 'X')
                        y_lie++;
                    if(room[x][y+1] != 'X' && room[x][y+2] != 'X')
                        y_lie++;
                }
            }
        }
    }
    
    std::cout << x_lie << " " << y_lie;

    //하 틀린데 어디가 문젠지 모르겠어 ㅁㄴㅇㄻ너ㅣㅏㄹㄴㅁㄻㄴㅇㄹ
    
    //hanging tree - jennifer lawrence (macon's HYPERTECHNO remix) [Extended]
    //노래 좋음
    
    for(int i = 0;i<loop;i++) 
        delete[] room[i];
    delete []room;
    
    return 0;
}
