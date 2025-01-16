#include <iostream>
using namespace std;

const int MX = 1000001;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void traverse() {
    // 시작점은 nxt[0]. nxt[0]은 연결 리스트의 첫 번째 데이터 노드를 가리킴
    // cur 변수를 사용하여 현재 위치를 추적
    int cur = nxt[0];
    
    // cur이 -1이 될 때까지 반복
    while (cur > -1) {
      // dat[cur]에 저장된 데이터를 출력
      cout << dat[cur];
      // nxt[cur]을 cur에 대입하여 다음 노드로 이동
      cur = nxt[cur];
    }

    // 모든 노드를 순회한 후 줄 바꿈을 추가하여 출력을 정리
    cout << '\n';
}

void insert(int addr, char num) {
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

  ios::sync_with_stdio(0);
  cin.tie(0);

  // 초기화: 모든 이전, 다음 노드 인덱스를 -1로 설정
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);

  string init;
  cin >> init;

  int cursor = 0;                 // 커서 위치 초기화 (더미 노드)
  for (char c: init) {            // 초기 문자열의 각 문자에 대해
      insert(cursor, c);          // 문자를 삽입하고
      cursor = nxt[cursor];       // 커서를 삽입한 위치로 이동
  }

  // 명령어의 총 개수 입력
  int T;
  cin >> T;

  // 각 명령어를 처리
  for (int t = 0; t < T; t++) {
    // 명령어 종류 입력 ('P', 'L', 'D', 'B')
    char command;
    cin >> command;

    // 'P': 현재 커서 위치에 문자 삽입
    if (command == 'P') {
      // 삽입할 문자 입력
      char input;
      cin >> input;
    
      insert(cursor, input);    // 삽입 연산 수행
      cursor = nxt[cursor];     // 커서를 삽입된 문자 위치로 이동
    }
    
    // 'L': 커서를 왼쪽으로 이동
    else if (command == 'L') {
      if (pre[cursor] != -1)   // 커서의 왼쪽 노드가 존재하면
        cursor = pre[cursor];    // 커서를 왼쪽 노드로 이동
    }

    // 'D': 커서를 오른쪽으로 이동
    else if (command == 'D') {
      if (nxt[cursor] != -1)    // 커서의 오른쪽 노드가 존재하면
        cursor = nxt[cursor];     // 커서를 오른쪽 노드로 이동
    }

    // 'B': 커서 왼쪽의 문자 삭제
    else if (command == 'B') {
      if (dat[cursor] != -1) {  // 삭제할 노드가 존재하면
        erase(cursor);            // 삭제 연산 수행
        cursor = pre[cursor];     // 커서를 왼쪽 노드로 이동
      }
    }
  }
  traverse();

return 0;
}