#include "utils.hpp"

#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <array>
#include <map>
#include <unordered_map>

namespace utils {
  void stringCollection() {
    std::string s = "bobos";

    // for (auto i = s.rbegin(); i < s.rend(); ++i)
    //   std::cout << *i << std::endl;

    s.replace(2, 2, "k");
    std::cout << s << std::endl;
  }

  void vectorCollection() {
    // std::vector v = { 18, -2, 30 };
    std::vector<int> v(2, 3);

    v[1] = 34;
    v.insert(v.begin() + 1, v.rbegin(), v.rend());
    v.emplace_back(65);
    v.push_back(262);
    // v.assign(2, 3);
    // std::cout << v.front() << std::endl;
    for (int& el : v) std::cout << el << std::endl;
    // std::cout << v.size() << std::endl;
  }

  void listCollection() {
    std::list f1 = { 1, 2, 3 };
    std::list f2 = { 60, 78, 45 };

    f1.emplace_back(2);

    f1.splice(f1.begin(), f2, f2.begin(), --f2.end());

    f1.remove_if([] (int& value) { return value % 2; });

    f1.unique([] (int& first, int& second) { return first > second; });

    f2.assign({ 1, 2, 85 });
    f1.merge(f2);

    f1.sort([] (int& a, int& b) { return b < a; });

    f1.reverse();

    for (auto el = f1.begin(); el != f1.end(); ++el)
      std::cout << *el << std::endl;
  }

  void mapCollection() {
    std::map<char, int> m;

    m['d'] = 12;
    m['k'] = 18;
    m['~'] = 9;
    m.emplace('~', 19);

    // for (const auto& [key, value] : m)

    // m.erase(m.begin(), --m.end());
    // std::cout << (++m.upper_bound('d'))->first << std::endl;
    std::cout << m.equal_range('d').first->first << std::endl;

    // std::cout << std::endl;
    // for (auto el = m.begin(); el != m.end(); ++el) {
    //   for (int i = 0; i < el->second; ++i) std::cout << el->first;
    //   std::cout << std::endl;
    // }
  }
}
