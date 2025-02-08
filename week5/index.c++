#include <bits/stdc++.h>  // C++의 표준 라이브러리를 한 번에 포함
using namespace std;  // 표준 네임스페이스 사용

#define X first  // pair에서 첫 번째 원소를 X로 간단하게 표현
#define Y second // pair에서 두 번째 원소를 Y로 간단하게 표현

// 2차원 배열을 사용하여 1은 방문해야 할 점(파란 점), 0은 방문하지 않을 점(빨간 점)으로 구분
int board[502][502] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

bool vis[502][502] = { { false, }, };  // 방문 여부를 저장하는 배열, 기본값은 false(0)
int n = 7, m = 10;   // 행(n)과 열(m)의 크기 설정
int dx[4] = {1, 0, -1, 0}; // 상(↓), 우(→), 하(↑), 좌(←) 방향 이동을 위한 배열
int dy[4] = {0, 1, 0, -1}; // 위와 동일한 순서로 y좌표 이동

int main(void) {
    ios::sync_with_stdio(0); // 입출력 속도를 향상
    cin.tie(0); // C와 C++ 입출력을 분리하여 실행 속도 향상

    queue<pair<int, int>> Q; // BFS 탐색을 위한 큐 선언
    vis[0][0] = 1; // (0, 0) 좌표를 방문했음을 표시
    Q.push({0, 0}); // BFS 시작점 (0, 0)을 큐에 삽입

    while (!Q.empty()) { // 큐가 빌 때까지 반복 (BFS 수행)
        pair<int, int> cur = Q.front(); // 큐의 front 값을 가져옴 (현재 방문한 좌표)
        Q.pop(); // front 값을 제거
        cout << cur.X << ", " << cur.Y << " -> "; // 현재 방문한 좌표 출력

        for (int dir = 0; dir < 4; dir++) { // 상하좌우 네 방향 탐색
            int nx = cur.X + dx[dir]; // 새로운 x좌표 계산
            int ny = cur.Y + dy[dir]; // 새로운 y좌표 계산
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어나면 무시
            if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문했거나, 값이 1이 아니면 무시
            vis[nx][ny] = 1;    // 새로운 좌표를 방문했다고 표시
            Q.push({nx, ny});   // 새로운 좌표를 큐에 삽입하여 다음 탐색 진행
        }
    }

    return 0; // 프로그램 종료
}