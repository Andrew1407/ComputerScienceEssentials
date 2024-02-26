#include "../utils.hpp"

#include <iostream>

class Storage {
  public:
    virtual void save(const char* data) = 0;
};

class OfflineStorage : public Storage {
  public:
    void save(const char* data) override {
      std::cout << "[data stored offline] " << data << std::endl;
    }
};

class OnlineStorage : public Storage {
  public:
    void save(const char* data) override {
      std::cout << "[data stored online] " << data << std::endl;
    }
};

class LoggerService {
  public:
    LoggerService(Storage& storage) : storage(storage) {}
    void warn() { storage.save("warning action"); }
    void activity() { storage.save("user activity action"); }

  private:
    Storage& storage;
};

void useLoggerService(Storage&& storage) {
  LoggerService logger(storage);
  logger.warn();
  logger.activity();
  logger.warn();
}

namespace utils {
  void useBridge() {
    useLoggerService(OnlineStorage());
  }
}
