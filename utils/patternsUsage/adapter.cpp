#include "../utils.hpp"

#include <iostream>

#define POUND_TO_KG 0.45

class GoodsContainer {
  public:
    GoodsContainer(const char* type, int count, float itemWeight) :
      type(type), count(count), itemWeightKg(itemWeight) {}

    float getTotalWeight() { return itemWeightKg * count; }
    const char* getType() { return type; }

  private:
    const char* type;
    int count;
    float itemWeightKg;
};

class WeightRecord {
  public:
    virtual float getWeight() = 0;
    virtual const char* getLabel() = 0;
};

class GoodsPoundAdapter : public WeightRecord {
  public:
    GoodsPoundAdapter(GoodsContainer& container) : container(container) {}
    float getWeight() override {
      return container.getTotalWeight() / POUND_TO_KG;
    }
    const char* getLabel() { return container.getType(); }

  private:
    GoodsContainer& container;
};

void showWeightPounds(WeightRecord& record) {
  std::cout
    << record.getLabel() << ": "
    << record.getWeight() << " pounds"
    << std::endl;
}

namespace utils {
  void useAdapter() {
    GoodsContainer wood("wood", 10, 5);
    GoodsPoundAdapter woodRecord(wood);
    showWeightPounds(woodRecord);
  }
}
