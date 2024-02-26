#include "queueSelf.hpp"
#include <iostream>

namespace self {
  template<typename T>
  Queue<T>::~Queue() {
    if (empty()) return;
    Node* currentNode = first;
    while (currentNode) {
      Node* next = currentNode->next;
      delete currentNode;
      currentNode = next;
    }
  }

  template<typename T>
  int Queue<T>::size() { return length; }

  template<typename T>
  void Queue<T>::pop() {
    if (empty()) return;
    std::lock_guard guard(mutex);
    Node* firstNext = first->next;
    delete first;
    first = firstNext;
    --length;
  }

  template<typename T>
  void Queue<T>::push(T value) {
    std::lock_guard guard(mutex);
    Node* newLast = new Node();
    newLast->value = value;
    if (length++) {
      last->next = newLast;
      last = newLast;
      return;
    }
    last = newLast;
    first = new Node();
    first->value = value;
    first->next = last;
  }

  template<typename T>
  T& Queue<T>::front() {
    if (!empty()) return first->value;
    throw std::runtime_error("queue underflow");
  };

  template<typename T>
  T& Queue<T>::back() {
    if (!empty()) return last->value;
    throw std::runtime_error("queue underflow");
  };

  template<typename T>
  bool Queue<T>::empty() { return length == 0; }
}
