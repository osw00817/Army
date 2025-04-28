#include <iostream>
#include <vector>
using namespace std;

//퀵정렬로 풀기
/*
pivot 기준 설정
start < pivot start++;
end > pviot end--;
start > pivot && end < pivot start하고 end swap,start++,end--;
start와 end가 만남,만나는지점의 val < pivot,만난 지점의 오른쪽에 pivot 삽입
val > pivot이면 왼쪽에 삽입.
분리집합후 다시 pivot 설정
분리집합이 1개 이하가 될때까지 과정을 반복
    */
/*
이해는 했으나 퀵정렬이 가장 어려운거같음.
솔직히 이 문제도 혼자 풀라고 하면 못풀었을꺼같다. 피봇 정렬을 사용한다는 조건 하에.,
  */
void quickSort(vector<int> &A,int S,int E,int K);
int partition(vector<int> &A,int S,int E);
void swap(vector<int> &A,int i,int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;
    vector<int> A(N,0);

    for(int i = 0;i<N;i++) {
        cin >> A[i];
    }

    quickSort(A,0,N-1,K-1);
    cout << A[K-1];
    return 0;
}

void quickSort(vector<int> &A,int S,int E,int K) {
    int pivot =partition(A,S,E);
    if(pivot == K) {
        return;
    }
    else if(K < pivot) {
        quickSort(A,S,pivot-1,K);
    }
    else {
        quickSort(A,pivot+1,E,K);
    }
}

int partition(vector<int> &A,int S,int E) {
    
    //2개면 그냥 바로 처리
    if(S+1 == E) {
        if(A[S] > A[E]) {
            swap(A,S,E);
        }
        return E;
    }

    int M = (S+E)/2;
    //피봇 정하기
    swap(A,S,M);
    //start랑 swap
    int pivot = A[S];
    int start = S + 1, end = E;

    while(start<=end) {
        while (end>= S+1 && pivot < A[end]) {
            end--;
        }
        while (start<=end && pivot > A[start]) {
            start++;
        }
        if(start < end)
            swap(A,start++,end--);
        else
            break;
    }
    
    A[S] = A[end];
    A[end] = pivot;
    return end;
}

void swap(vector<int> &A,int i,int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
