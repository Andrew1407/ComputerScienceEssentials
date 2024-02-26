#include "../utils.hpp"

#include <iostream>
#include <math.h>

template<typename T>
class DataContainer {
  public:
    virtual void setData(T input) = 0;
    virtual T getData() = 0;
};

class NumberDataContainer : public DataContainer<float> {
  public:
    void setData(float input) override { data = input; }
    float getData() override { return data; }
  private:
    float data;
};

class StringifiedDataContainer : public DataContainer<std::string> {
  public:
    StringifiedDataContainer(DataContainer<float>& wrapee) : wrapee(wrapee) {}
    void setData(std::string input) override {
      auto data = std::stof(input);
      std::cout << "Float value to set: " << data << std::endl; 
      wrapee.setData(data);
    }
    std::string getData() override {
      auto data = wrapee.getData();
      std::cout << "Float value got: " << data << std::endl;
      return std::to_string(data);
    }

  private:
    DataContainer<float>& wrapee;
};

namespace utils {
  void useDecorator() {
    NumberDataContainer dataContainer;
    StringifiedDataContainer wrapper(dataContainer);

    wrapper.setData("-1");
    auto value = wrapper.getData();
    std::cout << "value: " << value << std::endl;

    wrapper.setData("3.5645");
    value = wrapper.getData();
    std::cout << "value: " << value << std::endl;
  }
}
