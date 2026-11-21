#include "Coffee/Memory/Memory.h"

namespace Coffee {
namespace Memory {

Mine *Mine::s_instance = new Mine();

Mine &Mine::Get() const { return *s_instance; }
void Mine::Destroy() {
  if (s_instance)
    delete s_instance;
  else
    COFFEE_PRINT("No instance to destroy!");
}

} // namespace Memory
} // namespace Coffee
