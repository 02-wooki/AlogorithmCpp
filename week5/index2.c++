#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 간단히 사용하기 위해 정의

int board[502][502] = { // 2D 배열 초기화
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

bool vis[502][502]; // 방문 여부 저장
int n = 7, m = 10; // 행과 열의 크기
int dx[4] = {1, 0, -1, 0}; // 상하좌우 방향
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int> > S; // 스택을 사용한 DFS
    S.push(make_pair(0, 0)); // 시작점 삽입
    vis[0][0] = true; // 시작점 방문 표시

    while (!S.empty()) {
        pair<int, int> cur = S.top();
        S.pop();
        cout << "(" << cur.X << ", " << cur.Y << ") -> ";

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 범위를 벗어나거나 이미 방문했거나 이동할 수 없는 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true; // 방문 처리
            S.push(make_pair(nx, ny)); // 스택에 삽입
        }
    }

    return 0;
}