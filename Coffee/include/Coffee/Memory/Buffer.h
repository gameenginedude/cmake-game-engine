

#pragma once

#include <cstdint>

namespace Coffee {
namespace Memory {
enum class GpuBufferType : uint8_t {
  None = 0,
  Vertex,
  Index,
  Uniform,
  Storage
  // ... so on
};

struct BufferConfig {
  int bufferSize;
  GpuBufferType bufferType;
};

// you could write a general buffer class here idk, obviously you would
// need a custom one for your engine, it's super helpful in my engine. i'm
// planning to make a video about a buffer class soon.
class Buffer {};

// contains views into buffers - like GameObject ref (or any custom data in your
// scene object ref, it's your engine!), vertex buffer start index & end index,
// indexbuffer start & end index.. so on..
class BufferView {};
}
}
