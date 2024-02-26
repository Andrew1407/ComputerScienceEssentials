#pragma once
#include <mutex>

namespace self {
  template<typename T>
  class Stack {
    public:
      ~Stack();
      int size();
      void pop();
      void push(T value);
      T& top();
      bool empty();

    private:
      struct Node {
        T value;
        Node* prev = nullptr;
      };
      std::mutex mutex;
      Node* last = nullptr;
      int length = 0;
  };

  template class Stack<int>;
}
