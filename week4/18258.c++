#include <iostream>
#include <queue>
using namespace std;

#define MAX 2000000

int q[MAX];
int head = 0;
int tail = 0;

void push(int x) {
  q[tail++] = x;
}

int pop() {
  if (head == tail)
    return -1;
  return q[head++];
}

int size() {
  return tail - head;
}

int empty() {
  if (head == tail)
    return 1;
  return 0;
}

int front() {
  if (head == tail)
    return -1;
  return q[head];
}

int back() {
    if (head == tail)
      return -1;
  return q[tail - 1];
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    if (!str.compare("push")) {
      int x;
      cin >> x;

      push(x);
    } else if (!str.compare("pop")) {
      cout << pop() << '\n';
    } else if (!str.compare("size")) {
      cout << size() << '\n';
    } else if (!str.compare("empty")) {
      cout << empty() << '\n';
    } else if (!str.compare("front")) {
      cout << front() << '\n';
    } else if (!str.compare("back")) {
      cout << back() << '\n';
    }
  }

  return 0;
}