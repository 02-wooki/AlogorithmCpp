#include <iostream>
using namespace std;

void insert(int idx, int num, int arr[], int& len) {
    // insert 함수: 배열의 특정 위치(idx)에 값을 삽입하는 함수
    
    // 배열의 끝에서부터 idx 위치까지 요소를 한 칸씩 뒤로 이동
    for(int i = len; i > idx; i--)
      arr[i] = arr[i - 1];

    // idx 위치에 새로운 값(num) 삽입
    arr[idx] = num;
    
    // 배열의 길이를 1 증가
    len += 1;
}

void erase(int idx, int arr[], int& len) {
    // erase 함수: 배열의 특정 위치(idx)에서 값을 삭제하는 함수

    // 배열의 길이를 1 감소
    len -= 1;

    // idx 위치 이후의 요소들을 한 칸씩 앞으로 이동
    for(int i = idx; i < len; i++)
      arr[i] = arr[i + 1];
}

int main() {

  

  return 0;
}