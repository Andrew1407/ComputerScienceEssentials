#include "../utils.hpp"

#include <iostream>

class DbConnectionClient {
  public:
    const char* uri = "None";
    const char* type = "None";
    int tries = 1;

    void connect() {
      std::cout
        << "Connectiong to " << type
        << " db via " << uri
        << " (" << tries << " tries)"
        << std::endl;
    }
};

class DbClientBuilder {
  public:
    virtual void setTries() = 0;
    virtual void setType() = 0;
    virtual void setUri() = 0;
    virtual DbConnectionClient* getInstance() = 0;
};

class SqlClientBuidler : public DbClientBuilder {
  public:
    void setTries() override { client->tries = 1; }
    void setType() override { client->type = "sql"; }
    void setUri() override { client->uri = "localhost:6389"; }

    DbConnectionClient* getInstance() override {
      DbConnectionClient* instance = client;
      client = new DbConnectionClient();
      return instance;  
    }
  
  private:
    DbConnectionClient* client = new DbConnectionClient();
};

class RedisClientBuidler : public DbClientBuilder {
  public:
    void setTries() override { client->tries = 3; }
    void setType() override { client->type = "redis"; }
    void setUri() override { client->uri = "192.168.0.58:7114"; }

    DbConnectionClient* getInstance() override {
      DbConnectionClient* instance = client;
      client = new DbConnectionClient();
      return instance;  
    }
  
  private:
    DbConnectionClient* client = new DbConnectionClient();
};

void useBuidlerInstance(DbClientBuilder&& buidler) {
  buidler.setTries();
  buidler.setType();
  buidler.setUri();
  DbConnectionClient* client = buidler.getInstance();
  client->connect();
  delete client;
}

namespace utils {
  void useBuilder() {
    useBuidlerInstance(RedisClientBuidler());
  }
}
