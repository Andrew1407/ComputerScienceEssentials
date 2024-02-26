#pragma once
#include <mutex>

namespace self {
  template<typename T>
  class Queue {
    public:
      ~Queue();
      int size();
      void pop();
      void push(T value);
      T& front();
      T& back();
      bool empty();

    private:
      struct Node {
        T value;
        Node* next = nullptr;
      };
      std::mutex mutex;
      Node* first = nullptr;
      Node* last = nullptr;
      int length = 0;
  };

  template class Queue<int>;
}
