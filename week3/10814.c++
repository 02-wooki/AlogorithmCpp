#include <iostream>
using namespace std;

class People {
  public:
    People(int age, string name) {
      this->age = age;
      this->name = name;
    }
    People(int age, string name, People* next) {
      this(age, name);
      this->next = next;
    }

    People* next;
  private:
    int age;
    string name;
}

int main() {

  People *head;

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int age;
    string name;
    cin >> age >> name;
    People p = new People();
  }

  return 0;
}