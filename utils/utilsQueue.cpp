#include "utils.hpp"
#include <iostream>
#include <queue>
#include "../datastructs/queueSelf.hpp"

namespace utils {
  void useQueueLib() {
    std::queue<int> q;
    q.push(25);
    q.push(2);
    q.pop();

    std::cout << "\ngquiz.size() : " << q.size();
    std::cout << "\ngquiz.front() : " << q.front();
    std::cout << "\ngquiz.back() : " << q.back() << std::endl;
  }

  void useQueue() {
    self::Queue<int> q;
    q.push(25);
    q.push(2);
    q.front() += 50;
    
    std::cout << q.size() << std::endl;
    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;
  }
}
