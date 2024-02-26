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

class StorageFactory {
  public:
    virtual Storage* makeStorage() = 0;
};

class OfflineStorageFactory : public StorageFactory {
  public:
    Storage* makeStorage() override {
      return new OfflineStorage();
    }
};

class OnlineStorageFactory : public StorageFactory {
  public:
    Storage* makeStorage() override {
      return new OnlineStorage();
    }
};

void useStorage(StorageFactory&& factory) {
  Storage* storage = factory.makeStorage();
  storage->save("input to save");
  delete storage;
}

namespace utils {
  void useAbstractFactory() {
    useStorage(OnlineStorageFactory());
  }
}
