#include <iostream>
using namespace std;

/*
 * 배열 insert(임의 위치 삽입), erase(임의 위치 제거) 함수
 */
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

/*
 * 양방향 연결 리스트
 */
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void traverse() {
    // 시작점은 nxt[0]. nxt[0]은 연결 리스트의 첫 번째 데이터 노드를 가리킴
    // cur 변수를 사용하여 현재 위치를 추적
    int cur = nxt[0];
    
    // cur이 -1이 될 때까지 반복
    while (cur > -1) {
      // dat[cur]에 저장된 데이터를 출력
      cout << dat[cur] << '\n';
      // nxt[cur]을 cur에 대입하여 다음 노드로 이동
      cur = nxt[cur];
    }

    // 모든 노드를 순회한 후 줄 바꿈을 추가하여 출력을 정리
    cout << '\n';
}

void insert(int addr, int num) {
    // 전역 변수 unused를 사용하여 새로운 노드의 인덱스를 관리
    // dat[unused]에 삽입할 값을 저장
    dat[unused] = num;

    // 새 노드의 pre 값을 삽입 위치(addr)로 설정
    pre[unused] = addr;

    // 새 노드의 nxt 값을 기존 노드의 nxt 값으로 설정
    nxt[unused] = nxt[addr];

    // 만약 삽입 위치의 다음 노드(nxt[addr])가 존재하면, 그 노드의 pre 값을 새 노드(unused)로 갱신
    if (nxt[addr] != -1)
      pre[nxt[addr]] = unused;

    // 삽입 위치의 nxt 값을 새 노드(unused)로 갱신
    nxt[addr] = unused;

    // unused를 1 증가시켜 다음 삽입에 대비
    unused++;
}

void erase(int addr) {
    // 삭제할 노드의 이전 노드(pre[addr])와 다음 노드(nxt[addr])를 연결
    // pre[addr]이 가리키는 노드의 nxt 값을 nxt[addr]로 갱신
    nxt[pre[addr]] = nxt[addr];
    // nxt[addr]이 가리키는 노드의 pre 값을 pre[addr]로 갱신
    // 만약 삭제할 노드의 다음 노드(nxt[addr])가 존재하지 않을 경우, nxt[addr]은 -1이므로 추가 갱신은 수행하지 않음
    if (nxt[addr] != -1)
      pre[nxt[addr]] = pre[addr];
}

int main() {



  return 0;
}