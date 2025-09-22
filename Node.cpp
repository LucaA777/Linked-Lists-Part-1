#include "Node.h"

Node::Node() {
  student = NULL;
  next = NULL;
}

Node::~Node() {
  delete &student;
  next = NULL;
}

void Node::setStudent(Student* nStudent) {
  student = nStudent;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* nNext) {
  next = nNext;
}

Node* Node::getNext() {
  return next;
}
