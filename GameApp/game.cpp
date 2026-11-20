
#include "Coffee/Coffee.h"
#include "Coffee/Core/Application.h"

#include <string_view>

using namespace Coffee;

struct MovePlayer {
  MovePlayer(Gfx::GameObject *gameObj) : gameObjectPtr(gameObj) {
    // gameObjectPtr is initialized with value "gameObj" as soon as the
    // MovePlayer object is created!!!!
  }
  void operator()(const Core::FrameData &frameData) { gameObjectPtr->Move(); }
  Gfx::GameObject *gameObjectPtr;
};

void OnUpdate(const Core::FrameData &frameData) {
  COFFEE_PRINT("Time elapsed: " << frameData.elapsed_S);
}

int main() {

  Core::Application &engine = Core::Application::Get();
  Loaders::GltfLoader loader{};

  std::string_view filepath = "some/Path/To/Your/3DModel.gltf";
  Loaders::CppFriendlyFormat fileData;

  Gfx::Scene scene{};

  loader.LoadFrom3DFile(filepath, fileData);
  loader.ExtractSceneInfoFrom3DFile(fileData, scene);

  Gfx::GameObject *playerCharacter =
      scene.FindGameObjectByName("player-character");

  MovePlayer movePlayer{playerCharacter};

  engine.Start(movePlayer);

  Core::AppContext ctx;
  engine.GetContext(ctx);

  // engine.Start(OnUpdate);
  engine.Start(movePlayer);

  ctx.graphics->RegisterScene(scene);
  ctx.graphics->PaintFrame();

  Gfx::Graphics::Destroy();

  return 0;
}
