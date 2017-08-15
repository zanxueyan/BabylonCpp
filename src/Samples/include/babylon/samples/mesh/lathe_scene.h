#ifndef BABYLON_SAMPLES_MESH_LATHE_SCENE_H
#define BABYLON_SAMPLES_MESH_LATHE_SCENE_H

#include <babylon/interfaces/irenderable_scene.h>

namespace BABYLON {
namespace Samples {

struct LatheScene : public IRenderableScene {

  LatheScene(ICanvas* iCanvas);
  ~LatheScene();

  const char* getName() override;
  void initializeScene(ICanvas* canvas, Scene* scene) override;

}; // end of struct LatheScene

} // end of namespace samples
} // end of namespace BABYLON

#endif // end of BABYLON_SAMPLES_MESH_LATHE_SCENE_H
