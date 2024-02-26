#include "utils.hpp"
#include <iostream> 
#include <stack>
#include "../datastructs/stackSelf.hpp"

namespace utils {
  void useStackLib() {
    std::stack<int> s;
    s.push(25);
    s.push(5);
    s.pop();

    std::cout << "gquiz.size() : " << s.size();
    std::cout << "\ngquiz.top() : " << s.top() << std::endl;
  }

  void useStack() {
    self::Stack<int> s;
    s.push(25);
    s.push(5);
    s.push(5);
    s.pop();
    s.push(545);

    std::cout << "gquiz.size() : " << s.size();
    std::cout << "\ngquiz.top() : " << s.top() << std::endl;
  }
}
