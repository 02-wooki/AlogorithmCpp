#include <iostream>
#include <map>
using namespace std;

int main() {

// 배열 크기와 배열 선언
  int n;
  cin >> n;

  int map<int, int> m;

  // 입력 및 배열 초기화
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (m.find(x) == m.end())
      m[x] = 0;
    else
      m[x]++;
  }

  for (int i = 0; i < ; i++) {
    
  }

  // 초기 카운터 및 최빈값 변수 초기화
  

  // 배열을 순회하며 최빈값과 빈도 계산


  // 첫 번째 또는 이전 값과 같을 경우 카운터 증가


  // 값이 달라질 경우 현재 값의 빈도 확인 및 최빈값 갱신


  // 마지막 값의 빈도 확인


  // 최빈값 출력

  return 0;
}