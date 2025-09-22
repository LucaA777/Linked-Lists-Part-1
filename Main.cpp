#include <iostream>
#include "Student.h"
#include "Node.h"


using namespace std;

void add(Student* nStudent, Node* head);
void print(Node* head);

int main() {

  Node* head = NULL;

  add(new Student("Luca", 497022), head);
  add(new Student("Evan", 530232), head);
  add(new Student("Emily", 457203), head);
  
  return 0;
}

void add(Student* nStudent, Node* head) {
  Node* current = head;

  if (current == NULL) {
    head = new Node();
    head -> setStudent(nStudent);
  }
  else {
    while (current -> getNext() != NULL) {
      current = current -> getNext();
    }
    current -> setNext(new Node());
    current -> getNext() -> setStudent(nStudent);
  }
}

void print(Node* head) {

}
