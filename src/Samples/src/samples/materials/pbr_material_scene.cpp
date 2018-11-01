#include <babylon/samples/materials/pbr_material_scene.h>

#include <babylon/cameras/arc_rotate_camera.h>
#include <babylon/engine/scene.h>
#include <babylon/materials/image_processing_configuration.h>
#include <babylon/materials/pbr/pbr_material.h>
#include <babylon/materials/textures/cube_texture.h>
#include <babylon/materials/textures/texture.h>
#include <babylon/materials/textures/texture_constants.h>
#include <babylon/mesh/mesh.h>
#include <babylon/mesh/mesh_builder.h>
#include <babylon/mesh/vertex_data_options.h>

namespace BABYLON {
namespace Samples {

PBRMaterialScene::PBRMaterialScene(ICanvas* iCanvas) : IRenderableScene(iCanvas)
{
}

PBRMaterialScene::~PBRMaterialScene()
{
}

const char* PBRMaterialScene::getName()
{
  return "PBR Material Scene";
}

void PBRMaterialScene::initializeScene(ICanvas* canvas, Scene* scene)
{
  auto camera = ArcRotateCamera::New("Camera", -Math::PI_4, Math::PI / 2.5f,
                                     200, Vector3::Zero(), scene);
  camera->attachControl(canvas, true);
  camera->minZ = 0.1f;

  // Environment Texture
  auto hdrTexture
    = CubeTexture::CreateFromPrefilteredData("textures/environment.dds", scene);

  scene->imageProcessingConfiguration()->exposure = 0.6f;
  scene->imageProcessingConfiguration()->contrast = 1.6f;

  // Skybox
  auto hdrSkybox         = Mesh::CreateBox("hdrSkyBox", 1000.f, scene);
  auto hdrSkyboxMaterial = PBRMaterial::New("skyBox", scene);
  hdrSkyboxMaterial->backFaceCulling   = false;
  hdrSkyboxMaterial->reflectionTexture = hdrTexture->clone();
  hdrSkyboxMaterial->reflectionTexture()->coordinatesMode
    = TextureConstants::SKYBOX_MODE;
  hdrSkyboxMaterial->microSurface    = 1.f;
  hdrSkyboxMaterial->disableLighting = true;
  hdrSkybox->material                = hdrSkyboxMaterial;
  hdrSkybox->infiniteDistance        = true;

  // Create meshes
  auto sphereGlass = Mesh::CreateSphere("sphereGlass", 48, 30.f, scene);
  sphereGlass->translate(Vector3(1.f, 0.f, 0.f), -60.f);

  auto sphereMetal = Mesh::CreateSphere("sphereMetal", 48, 30.f, scene);
  sphereMetal->translate(Vector3(1.f, 0.f, 0.f), 60.f);

  auto spherePlastic = Mesh::CreateSphere("spherePlastic", 48, 30.f, scene);
  spherePlastic->translate(Vector3(0.f, 0.f, 1.f), -60.f);

  BoxOptions woodPlankOptions;
  woodPlankOptions.width  = 65.f;
  woodPlankOptions.height = 1.f;
  woodPlankOptions.depth  = 65.f;
  auto woodPlank = MeshBuilder::CreateBox("plane", woodPlankOptions, scene);

#if 0
  // Create materials
  auto glass                            = PBRMaterial::New("glass", scene);
  glass->reflectionTexture              = hdrTexture;
  glass->refractionTexture              = hdrTexture;
  glass->linkRefractionWithTransparency = true;
  glass->indexOfRefraction              = 0.52f;
  glass->alpha                          = 0.f;
  glass->microSurface                   = 1;
  glass->reflectivityColor              = Color3(0.2f, 0.2f, 0.2f);
  glass->albedoColor                    = Color3(0.85f, 0.85f, 0.85f);
  sphereGlass->material                 = glass;

  auto metal               = PBRMaterial::New("metal", scene);
  metal->reflectionTexture = hdrTexture;
  metal->microSurface      = 0.96f;
  metal->reflectivityColor = Color3(0.85f, 0.85f, 0.85f);
  metal->albedoColor       = Color3(0.01f, 0.01f, 0.01f);
  sphereMetal->material    = metal;

  auto plastic               = PBRMaterial::New("plastic", scene);
  plastic->reflectionTexture = hdrTexture;
  plastic->microSurface      = 0.96f;
  plastic->albedoColor       = Color3(0.206f, 0.94f, 1.f);
  plastic->reflectivityColor = Color3(0.003f, 0.003f, 0.003f);
  spherePlastic->material    = plastic;

  auto wood                  = PBRMaterial::New("wood", scene);
  wood->reflectionTexture    = hdrTexture;
  wood->environmentIntensity = 1.f;
  wood->specularIntensity    = 0.3f;

  wood->reflectivityTexture = Texture::New("textures/reflectivity.png", scene);
  wood->useMicroSurfaceFromReflectivityMapAlpha = true;

  wood->albedoColor   = Color3::White();
  wood->albedoTexture = Texture::New("textures/albedo.png", scene);
  woodPlank->material = wood;
#endif
}

} // end of namespace Samples
} // end of namespace BABYLON