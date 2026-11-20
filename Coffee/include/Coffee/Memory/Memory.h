#pragma once

#include "Coffee/Logs.h"
namespace Coffee {
namespace Memory {

struct GPUSavedData {
  // some custom format we save the GPU data in
};

class Mine {
public:
  Mine &Get() const;
  void Destroy();

  Mine(const Mine &) = delete;
  Mine &operator=(const Mine &) = delete;
  Mine(Mine &&) = delete;
  Mine &operator=(Mine &&) = delete;

private:
  Mine() { COFFEE_PRINT("Mine Created") };
  ~Mine() { COFFEE_PRINT("Mine Destroyed") };

private:
  static Mine *s_instance;
};

} // namespace Memory
} // namespace Coffee
