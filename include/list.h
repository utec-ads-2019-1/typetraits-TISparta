#ifndef LIST_H
#define LIST_H

#include <exception>
#include <stdexcept>
#include "node.h"

// TO DELETE
#include <iostream>

template <typename Tr>
class List {
public:
  typedef typename Tr::T T;
  typedef typename Tr::Operation Operation;

private:
  Node <T>* head;
  Operation cmp;
  int nodes = 0;

public:
  List(): head(nullptr) {};

  bool find (T search, Node <T> ** pointer) {
    while (*pointer and (*pointer) -> data != search) pointer = &((*pointer) -> next);
    return *pointer; 
  }

  bool insert (T data) {
    if (find(data, &(this -> head))) return false;
    Node <T>* newNode = new Node <T> (data);
    if (not head) {
      this -> head = newNode;
      this -> nodes++;
      return true;
    }
    Node <T>* cur = this -> head;
    Node <T>* prev = nullptr;
    while (cur and not cmp(data, cur -> data)) {
      prev = cur;
      cur = cur -> next;
    }
    if (cur == this -> head) {
      newNode -> next = this -> head;
      this -> head = newNode;
    } else {
      prev -> next = newNode;
      newNode -> prev = prev;
      newNode -> next = cur;
      if (cur) cur -> prev = newNode;
    }
    this -> nodes++;
    return true;
  }

  bool remove (T item) {
    if (not find(item, &(this -> head))) return false;
    Node <T>* cur = this -> head;
    if (item == cur -> data) {
      this -> head = cur -> next;
      delete cur;
      this -> nodes--;
      return true;
    }
    while (cur and cur -> data != item) {
      cur = cur -> next;
    }
    cur -> prev -> next = cur -> next;
    if (cur -> next) cur -> next -> prev = cur -> prev;
    this -> nodes--;
    return true;
  }

  inline int size () const { return this -> nodes; } 

  T operator [] (int index) {
    if (not (0 <= index and index < this -> nodes)) {
      throw std::out_of_range("The index is out of range");
    }
    Node <T>* tmp = this -> head;
    for (int i = 0; i < index; i++) {
      tmp = tmp -> next;
    }
    return tmp -> data;
  }

  ~List () {
    if (this -> head) this -> head -> killSelf();
  }

};

#endif
