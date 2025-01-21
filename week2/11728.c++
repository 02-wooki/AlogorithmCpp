#include <iostream>
#include <list>
using namespace std;

int main() {

  list<int> a;
  list<int> b;

  int aSize, bSize;
  cin >> aSize >> bSize;

  for (int i = 0; i < aSize; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < bSize; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }

  a.merge(b);
  list<int>:: iterator x = a.begin();

  for (list<int>:: iterator x = a.begin(); x != a.end(); x++)
    cout << *x << ' ';

  return 0;
}