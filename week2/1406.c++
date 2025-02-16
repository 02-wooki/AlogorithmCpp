#include <iostream>
using namespace std;

class Node {
  public:
    // 생성자
    Node(char data, Node* prevNode, Node* nextNode) {
      // 앞, 뒤 노드의 포인터를 이 객체로 지정
      if (nextNode != NULL)
        nextNode -> prev = this;
      if (prevNode != NULL)
        prevNode -> next = this;

      // 이 객체의 포인터를 앞, 뒤 노드로 지정
      this -> next = nextNode;
      this -> prev = prevNode;

      this -> data = data;
    }

    Node* getHead() {
      Node* head = this;
      while (head -> prev != NULL)
        head = head -> prev;

      return head;
    }

    char data;
    Node* next;
    Node* prev;
};

int main() {

  // 커서 왼쪽의 문자열 노드와 커서 오른쪽의 문자열 노드 각각 선언
  Node* curPrev = NULL;
  Node* curNext = NULL;

  string init;
  int n;

  // 초기 문자열 입력
  cin >> init;
  for (char c: init)
    curPrev = new Node(c, curPrev, curNext);

  cin >> n;
  while (n--) {
    char cmd, x;
    cin >> cmd;

    if (cmd == 'L' && curPrev != NULL) {
      curNext = curPrev;
      curPrev = curPrev -> prev;
    } else if (cmd == 'D' && curNext != NULL) {
      curPrev = curNext;
      curNext = curNext -> next;
    } else if (cmd == 'B' && curPrev != NULL) {
      // 커서 앞을 지울 노드 앞 노드로 변경
      Node* deletedNode = curPrev;
      curPrev = curPrev -> prev;

      // 노드들의 앞, 뒤 포인터 새로 연결
      if (curPrev != NULL)
        curPrev -> next = curNext;
      if (curNext != NULL)
        curNext -> prev = curPrev;

      // 삭제한 노드 메모리 해제
      delete(deletedNode);
    } else if (cmd == 'P') {
      cin >> x;
      curPrev = new Node(x, curPrev, curNext);
    }
  }

  // 출력
  Node* cur;
  if (curPrev == NULL && curNext == NULL)
    return 0;

  if (curPrev == NULL)
    cur = curNext -> getHead();
  else
    cur = curPrev -> getHead();
  while (cur != NULL) {
    cout << cur -> data;
    cur = cur -> next;
  }

  return 0;
}