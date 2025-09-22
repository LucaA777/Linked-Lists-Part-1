/*
This program creates a linked list of students. It has the capabilities
to add to the list and print the list. 
  
Author: Luca Ardanaz
Last Updated: 9/21/2025
 */

#include <iostream>
#include "Student.h"
#include "Node.h"


using namespace std;

void add(Student* nStudent, Node* &head);
void print(Node* current, Node* &head);

int main() {

  //define the head
  Node* head = NULL;

  //add and print tests
  add(new Student("Luca", 497022), head);
  print(head, head);
  add(new Student("Evan", 530232), head);
  print(head, head);
  add(new Student("Emily", 457203), head);
  print(head, head);

  
  return 0;
}

void add(Student* nStudent, Node* &head) {
  Node* current = head;

  //if the head is empty, then assign the student to the head
  if (current == NULL) {
    head = new Node();
    head -> setStudent(nStudent);
  }
  else {
    //iterate till a null node is found
    while (current -> getNext() != NULL) {
      current = current -> getNext();
    }
    //assign the student to a new node at the end
    current -> setNext(new Node());
    current -> getNext() -> setStudent(nStudent);
  }
}

void print(Node* current, Node* &head) {

  //if its the first node, print list start
  if (current == head) {
    cout << "List: ";
  }

  //if the current node isn't null, print it and recursively call into the next node
  if (current != NULL) {
    cout << current -> getStudent() -> getName() << " ";
    print(current -> getNext(), head);
  }
  else {
    cout << endl;
  }
}
