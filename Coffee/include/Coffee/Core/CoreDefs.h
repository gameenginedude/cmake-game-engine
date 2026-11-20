#pragma once

namespace Coffee {
namespace Core {

class Window;

struct FrameData {
  double elapsed_S = 0.;   // time elapsed in sec
  double delta_S = 0.0166; // delta in sec
};

} // namespace Core
} // namespace Coffee
