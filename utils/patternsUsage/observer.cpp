#include "../utils.hpp"

#include <iostream>
#include <map>

class Subscriber {
  public:
    virtual void onNotify(const char* data) = 0;
};

class DataManager {
  public:
    void subscribe(const char* key, Subscriber* value) {
      subscribers.emplace(key, value);
    }
    void unsubscribe(const char* key, Subscriber* value) {
      auto found = subscribers.equal_range(key);
      for (auto el = found.first; el != found.second; ++el)
        if (el->second == value) {
          subscribers.erase(el);
          return;
        }
    }
    void notify(const char* key, const char* data) {
      auto found = subscribers.equal_range(key);
      for (auto el = found.first; el != found.second; ++el)
        el->second->onNotify(data);
    }

  private:
    std::multimap<const char*, Subscriber*> subscribers;
};

class InfoLogger : public Subscriber {
  public:
    void onNotify(const char* data) override {
      std::cout << "[Info]: " << data << std::endl;
    }
};

class SymbolLogger : public Subscriber {
  public:
    SymbolLogger(const char* symbol) : symbol(symbol) {}
    void onNotify(const char* data) override {
      std::cout << symbol << ' ' << data << ' ' << symbol << std::endl;
    }
  
  private:
    const char* symbol;
};

namespace utils {
  void useObserver() {
    InfoLogger infoLogger;
    SymbolLogger symbolLogger("***");
    DataManager dataManager;

    dataManager.subscribe("warn", &infoLogger);
    dataManager.subscribe("warn", &symbolLogger);
    dataManager.subscribe("error", &infoLogger);

    dataManager.notify("error", "1 e");
    dataManager.notify("warn", "1 w");

    dataManager.unsubscribe("warn", &infoLogger);
    dataManager.notify("warn", "2 w");
    dataManager.notify("error", "2 e");
  }
}
