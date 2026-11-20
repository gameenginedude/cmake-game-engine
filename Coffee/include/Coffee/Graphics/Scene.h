

#pragma once

#include "Coffee/Logs.h"
#include <iostream>
#include <vector>

namespace Coffee {
namespace Gfx {

class TransformsData {
  // transform data of the object like position vector, rotation angles, quats,
  // model matrix etc. you can also make it custom per gameobj type too! it's
  // your engine, make it as you like :)
};

class GameObject {
  // game object specific information
public:
  void Move() { std::cout << "Moved the game object!" << '\n'; }

private:
  TransformsData
      transformData; // for simplicity, GameObject holds TransformsData here. in
                     // my engine, i have a AoS of all transforms and the Game
                     // obj only holds the index (or ref whatever)
};

class Scene {
public:
  Scene() = default;
  ~Scene() {
    if (m_gameObjects[0])
      delete m_gameObjects[0];
  }

  void AddGameObject(GameObject *node) {
    // add to subtree or tree (in the scene graph)
    COFFEE_PRINT("added game object");
  }
  GameObject *FindGameObjectByName(const std::string &name) {
    COFFEE_PRINT("found game object in the scene from identifier");

    return m_gameObjects[0]; // just as an example (
  }

private:
  std::vector<GameObject *> m_gameObjects{
      new GameObject}; // usually contains root nodes (of a tree made of game
                       // objects, it's called a scene graph). added a fake game
                       // object as an example
};

} // namespace Gfx
} // namespace Coffee
