#include <babylon/samples/materials/shader_material_scene.h>

#include <babylon/cameras/arc_rotate_camera.h>
#include <babylon/materials/effect_shaders_store.h>
#include <babylon/materials/shader_material.h>
#include <babylon/mesh/mesh.h>
#include <babylon/mesh/vertex_data_options.h>

namespace BABYLON {
namespace Samples {

ShaderMaterialScene::ShaderMaterialScene(ICanvas* iCanvas)
    : IRenderableScene(iCanvas)
    , _j{0}
    , _camera{nullptr}
    , _shaderMaterial{nullptr}
    , _polyhedron{nullptr}
{
  // Vertex shader
  EffectShadersStore::Shaders["customVertexShader"] = customVertexShader;

  // Fragment shader
  EffectShadersStore::Shaders["customFragmentShader"] = customFragmentShader;
}

ShaderMaterialScene::~ShaderMaterialScene()
{
}

const char* ShaderMaterialScene::getName()
{
  return "Shader Material Scene";
}

void ShaderMaterialScene::initializeScene(ICanvas* canvas, Scene* scene)
{
  // Change scene clear color
  scene->clearColor = Color4(0.f, 0.f, 0.f);

  // Create a Camera
  _camera = ArcRotateCamera::New("ArcRotateCamera", 0.0, 1.5, 150,
                                 Vector3(0.f, 0.f, 0.f), scene);

  // Target the camera to scene origin
  _camera->setTarget(Vector3::Zero());

  // Attach control
  _camera->attachControl(canvas, true);

  // Create shader material
  ShaderMaterialOptions shaderMaterialOptions;
  shaderMaterialOptions.attributes = {"position", "normal"};
  shaderMaterialOptions.uniforms
    = {"worldViewProjection", "world", "vPositionW", "vNormalW", "time"};
  _shaderMaterial = ShaderMaterial::New("ball_shader", scene, "custom",
                                        shaderMaterialOptions);

  // Create polyhedron
  PolyhedronOptions polyhedronOptions(25.f);
  polyhedronOptions.type = 0;
  _polyhedron
    = Mesh::CreatePolyhedron("CreatePolyhedron", polyhedronOptions, scene);
  _polyhedron->setMaterial(_shaderMaterial);

  // Create box
  auto box = Mesh::CreateBox("Box", 500, scene);
  box->flipFaces(true);
  box->setMaterial(_shaderMaterial);

  // Animation
  scene->onAfterCameraRenderObservable.add([this]() {
    _shaderMaterial->setFloat("time", 3.f / static_cast<float>(_j));
    if (_j == 2000) {
      _j = 0;
    }
    ++_j;
    _polyhedron->rotation().x += 0.03f;
    _camera->alpha += 0.01f;
    _camera->position.x += 0.01f;
  });
}

} // end of namespace Samples
} // end of namespace BABYLON
