#include "../utils.hpp"

#include <stdlib.h>
#include <string>
#include <iostream>

class NumbersGenerator {
  public:
    NumbersGenerator(int length) : length(length) {}
    virtual std::string generate() {
      std::string generated;
      for (int i = 0; i < length; ++i)
        generated += generateSymbol();
      return generated;
    }
  protected:
    int length;
    virtual std::string generateSymbol() {
      int symbol = rand() % length;
      return std::to_string(symbol);
    }
};

class SymbolsGenerator : public NumbersGenerator {
  public:
    SymbolsGenerator(int length) : NumbersGenerator(length) {}
  private:
    virtual std::string generateSymbol() override {
      int symbol = rand() % 97 + 50;
      std::string str;
      str += (char)symbol;
      return str;
    }
};

class SaltGenerator : public NumbersGenerator {
  public:
    SaltGenerator(int length) : NumbersGenerator(length) {}
  private:
    virtual std::string generateSymbol() override {
      int symbol = rand() % (70 + length) + (50 + length);
      std::string str;
      str += (char)symbol;
      return str;
    }
};

class HashGenerator : public SymbolsGenerator, public SaltGenerator {
  public:
    HashGenerator(int symbols, int salt) :
      SymbolsGenerator(symbols), SaltGenerator(salt) {}
      std::string generate() override {
        std::string base = SymbolsGenerator::generate();
        std::string salt = SaltGenerator::generate();
        return salt + "." + base;
      }
};

class HashGeneratorEncapsulated {
  public:
    HashGeneratorEncapsulated(int symbols, int salt) :
      symbolsGenerator(symbols), saltGenerator(salt) {}
    std::string generate() {
      std::string base = symbolsGenerator.generate();
      std::string salt = saltGenerator.generate();
      return salt + "." + base;
    }

  private:
    SymbolsGenerator symbolsGenerator;
    SaltGenerator saltGenerator;
};

class HashGeneratorInjectable {
  public:
    HashGeneratorInjectable(SymbolsGenerator& symbolsGenerator, SaltGenerator& saltGenerator) :
      symbolsGenerator(symbolsGenerator), saltGenerator(saltGenerator) {}
    std::string generate() {
      std::string base = symbolsGenerator.generate();
      std::string salt = saltGenerator.generate();
      return salt + "." + base;
    }

  private:
    SymbolsGenerator& symbolsGenerator;
    SaltGenerator& saltGenerator;
};

namespace utils {

  void multipleInheritance() {
    // auto symbols = SymbolsGenerator(10);
    // auto salt = SaltGenerator(5);
    // auto g = HashGeneratorInjectable(symbols, salt);
    // auto g = HashGeneratorEncapsulated(10, 5);
    auto g = HashGenerator(10, 5);

    std::cout << g.generate() << std::endl;

  }

}
