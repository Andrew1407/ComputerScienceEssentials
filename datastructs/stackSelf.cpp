#include "stackSelf.hpp"
#include <iostream>

namespace self {

  template<typename T>
  Stack<T>::~Stack() {
    if (empty()) return;
    Node* currentNode = last;
    while (currentNode) {
      Node* prev = currentNode->prev;
      delete currentNode;
      currentNode = prev;
    }
  }

  template<typename T>
  int Stack<T>::size() { return length; }

  template<typename T>
  void Stack<T>::pop() {
    if (empty()) return;
    std::lock_guard guard(mutex);
    Node* prev = last->prev;
    delete last;
    last = prev;
    --length;
  }

  template<typename T>
  void Stack<T>::push(T value) {
    std::lock_guard guard(mutex);
    Node* newLast = new Node();
    newLast->value = value;
    newLast->prev = last;
    last = newLast;
    ++length;
  }

  template<typename T>
  T& Stack<T>::top() {
    if (!empty()) return last->value;
    throw std::runtime_error("stack underflow");
  }

  template<typename T>
  bool Stack<T>::empty() { return length == 0; }

}
