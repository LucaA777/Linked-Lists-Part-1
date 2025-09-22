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
void remove(Student* student, Node* previous, Node* current, Node* &head);

int main() {

  //define the head
  Node* head = NULL;

  //add and print tests
  add(new Student("Luca", 497022), head);
  print(head, head);
  Student* s2 = new Student("Evan", 350434);
  add(s2, head);
  print(head, head);
  Student* s3 = new Student("Emily", 463454);
  add(s3, head);
  print(head, head);

  remove(s2, head, head, head);
  cout << "REMOVE SUCCESSFUL" << endl;
  print(head, head);

  
  return 0;
}

void add(Student* nStudent, Node* &head) {
  Node* current = head;

  //if the head is empty, then assign the student to the head
  if (current == NULL) {
    head = new Node(nStudent);
  }
  else {
    //iterate till a null node is found
    while (current -> getNext() != NULL) {
      current = current -> getNext();
    }
    //assign the student to a new node at the end
    current -> setNext(new Node(nStudent));
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

void remove(Student* student, Node* previous, Node* current, Node* &head) {
  
  //if student matches, remove them
  if (student == current -> getStudent()) {
    cout << "-FOUND MATCH" << endl;
    //if the current is the head, then there is no previous
    //next becomes new head
    if (current == head) {
      cout << "--HEAD DELETION" << endl;
      delete head;
      head = current -> getNext();
    }
    //if this is the last node, set the new next to be null
    else if (current -> getNext() == NULL) {
      cout << "--TAIL DELETION" << endl;
      previous -> setNext(NULL);
      delete current;
      cout << "--TAIL DELETION COMPLETED" << endl;
    }
    else {
      cout << "--BODY DELETION" << endl;
      previous -> setNext(current -> getNext());
      delete current;
    }
  }

  //if the current node isn't the last one, continue the search
  else if (current -> getNext() != NULL) {
    remove(student, current, current -> getNext(), head);
  }
}

