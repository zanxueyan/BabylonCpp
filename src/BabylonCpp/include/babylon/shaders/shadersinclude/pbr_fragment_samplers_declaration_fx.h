﻿#ifndef BABYLON_SHADERS_SHADERS_INCLUDE_PBR_FRAGMENT_SAMPLERS_DECLARATION_FX_H
#define BABYLON_SHADERS_SHADERS_INCLUDE_PBR_FRAGMENT_SAMPLERS_DECLARATION_FX_H

namespace BABYLON {

extern const char* pbrFragmentSamplersDeclaration;

const char* pbrFragmentSamplersDeclaration
  = "#ifdef ALBEDO\n"
    "  #if ALBEDODIRECTUV == 1\n"
    "  #define vAlbedoUV vMainUV1\n"
    "  #elif ALBEDODIRECTUV == 2\n"
    "  #define vAlbedoUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vAlbedoUV;\n"
    "  #endif\n"
    "  uniform sampler2D albedoSampler;\n"
    "#endif\n"
    "\n"
    "#ifdef AMBIENT\n"
    "  #if AMBIENTDIRECTUV == 1\n"
    "  #define vAmbientUV vMainUV1\n"
    "  #elif AMBIENTDIRECTUV == 2\n"
    "  #define vAmbientUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vAmbientUV;\n"
    "  #endif\n"
    "  uniform sampler2D ambientSampler;\n"
    "#endif\n"
    "\n"
    "#ifdef OPACITY\n"
    "  #if OPACITYDIRECTUV == 1\n"
    "  #define vOpacityUV vMainUV1\n"
    "  #elif OPACITYDIRECTUV == 2\n"
    "  #define vOpacityUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vOpacityUV;\n"
    "  #endif\n"
    "  uniform sampler2D opacitySampler;\n"
    "#endif\n"
    "\n"
    "#ifdef EMISSIVE\n"
    "  #if EMISSIVEDIRECTUV == 1\n"
    "  #define vEmissiveUV vMainUV1\n"
    "  #elif EMISSIVEDIRECTUV == 2\n"
    "  #define vEmissiveUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vEmissiveUV;\n"
    "  #endif\n"
    "  uniform sampler2D emissiveSampler;\n"
    "#endif\n"
    "\n"
    "#ifdef LIGHTMAP\n"
    "  #if LIGHTMAPDIRECTUV == 1\n"
    "  #define vLightmapUV vMainUV1\n"
    "  #elif LIGHTMAPDIRECTUV == 2\n"
    "  #define vLightmapUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vLightmapUV;\n"
    "  #endif\n"
    "  uniform sampler2D lightmapSampler;\n"
    "#endif\n"
    "\n"
    "#ifdef REFLECTIVITY\n"
    "  #if REFLECTIVITYDIRECTUV == 1\n"
    "  #define vReflectivityUV vMainUV1\n"
    "  #elif REFLECTIVITYDIRECTUV == 2\n"
    "  #define vReflectivityUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vReflectivityUV;\n"
    "  #endif\n"
    "  uniform sampler2D reflectivitySampler;\n"
    "#endif\n"
    "\n"
    "#ifdef MICROSURFACEMAP\n"
    "  #if MICROSURFACEMAPDIRECTUV == 1\n"
    "  #define vMicroSurfaceSamplerUV vMainUV1\n"
    "  #elif MICROSURFACEMAPDIRECTUV == 2\n"
    "  #define vMicroSurfaceSamplerUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vMicroSurfaceSamplerUV;\n"
    "  #endif\n"
    "  uniform sampler2D microSurfaceSampler;\n"
    "#endif\n"
    "\n"
    "#ifdef CLEARCOAT\n"
    "  #ifdef CLEARCOAT_TEXTURE\n"
    "  #if CLEARCOAT_TEXTUREDIRECTUV == 1\n"
    "  #define vClearCoatUV vMainUV1\n"
    "  #elif CLEARCOAT_TEXTUREDIRECTUV == 2\n"
    "  #define vClearCoatUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vClearCoatUV;\n"
    "  #endif\n"
    "  uniform sampler2D clearCoatSampler;\n"
    "  #endif\n"
    "\n"
    "  #ifdef CLEARCOAT_BUMP\n"
    "  #if CLEARCOAT_BUMPDIRECTUV == 1\n"
    "  #define vClearCoatBumpUV vMainUV1\n"
    "  #elif CLEARCOAT_BUMPDIRECTUV == 2\n"
    "  #define vClearCoatBumpUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vClearCoatBumpUV;\n"
    "  #endif\n"
    "  uniform sampler2D clearCoatBumpSampler;\n"
    "  #endif\n"
    "\n"
    "  #ifdef CLEARCOAT_TINT_TEXTURE\n"
    "  #if CLEARCOAT_TINT_TEXTUREDIRECTUV == 1\n"
    "  #define vClearCoatTintUV vMainUV1\n"
    "  #elif CLEARCOAT_TINT_TEXTUREDIRECTUV == 2\n"
    "  #define vClearCoatTintUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vClearCoatTintUV;\n"
    "  #endif\n"
    "  uniform sampler2D clearCoatTintSampler;\n"
    "  #endif\n"
    "#endif\n"
    "\n"
    "#ifdef SHEEN\n"
    "  #ifdef SHEEN_TEXTURE\n"
    "  #if SHEEN_TEXTUREDIRECTUV == 1\n"
    "  #define vSheenUV vMainUV1\n"
    "  #elif SHEEN_TEXTUREDIRECTUV == 2\n"
    "  #define vSheenUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vSheenUV;\n"
    "  #endif\n"
    "  uniform sampler2D sheenSampler;\n"
    "  #endif\n"
    "#endif\n"
    "\n"
    "#ifdef ANISOTROPIC\n"
    "  #ifdef ANISOTROPIC_TEXTURE\n"
    "  #if ANISOTROPIC_TEXTUREDIRECTUV == 1\n"
    "  #define vAnisotropyUV vMainUV1\n"
    "  #elif ANISOTROPIC_TEXTUREDIRECTUV == 2\n"
    "  #define vAnisotropyUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vAnisotropyUV;\n"
    "  #endif\n"
    "  uniform sampler2D anisotropySampler;\n"
    "  #endif\n"
    "#endif\n"
    "\n"
    "// Reflection\n"
    "#ifdef REFLECTION\n"
    "  #ifdef REFLECTIONMAP_3D\n"
    "  #define sampleReflection(s, c) textureCube(s, c)\n"
    "\n"
    "  uniform samplerCube reflectionSampler;\n"
    "  \n"
    "  #ifdef LODBASEDMICROSFURACE\n"
    "  #define sampleReflectionLod(s, c, l) textureCubeLodEXT(s, c, l)\n"
    "  #else\n"
    "  uniform samplerCube reflectionSamplerLow;\n"
    "  uniform samplerCube reflectionSamplerHigh;\n"
    "  #endif\n"
    "  #else\n"
    "  #define sampleReflection(s, c) texture2D(s, c)\n"
    "\n"
    "  uniform sampler2D reflectionSampler;\n"
    "\n"
    "  #ifdef LODBASEDMICROSFURACE\n"
    "  #define sampleReflectionLod(s, c, l) texture2DLodEXT(s, c, l)\n"
    "  #else\n"
    "  uniform samplerCube reflectionSamplerLow;\n"
    "  uniform samplerCube reflectionSamplerHigh;\n"
    "  #endif\n"
    "  #endif\n"
    "\n"
    "  #ifdef REFLECTIONMAP_SKYBOX\n"
    "  varying vec3 vPositionUVW;\n"
    "  #else\n"
    "  #if defined(REFLECTIONMAP_EQUIRECTANGULAR_FIXED) || defined(REFLECTIONMAP_MIRROREDEQUIRECTANGULAR_FIXED)\n"
    "  varying vec3 vDirectionW;\n"
    "  #endif\n"
    "  #endif\n"
    "#endif\n"
    "\n"
    "#ifdef ENVIRONMENTBRDF\n"
    "  uniform sampler2D environmentBrdfSampler;\n"
    "#endif\n"
    "\n"
    "// SUBSURFACE\n"
    "#ifdef SUBSURFACE\n"
    "  #ifdef SS_REFRACTION\n"
    "  #ifdef SS_REFRACTIONMAP_3D\n"
    "  #define sampleRefraction(s, c) textureCube(s, c)\n"
    "  \n"
    "  uniform samplerCube refractionSampler;\n"
    "\n"
    "  #ifdef LODBASEDMICROSFURACE\n"
    "  #define sampleRefractionLod(s, c, l) textureCubeLodEXT(s, c, l)\n"
    "  #else\n"
    "  uniform samplerCube refractionSamplerLow;\n"
    "  uniform samplerCube refractionSamplerHigh;\n"
    "  #endif\n"
    "  #else\n"
    "  #define sampleRefraction(s, c) texture2D(s, c)\n"
    "  \n"
    "  uniform sampler2D refractionSampler;\n"
    "\n"
    "  #ifdef LODBASEDMICROSFURACE\n"
    "  #define sampleRefractionLod(s, c, l) texture2DLodEXT(s, c, l)\n"
    "  #else\n"
    "  uniform samplerCube refractionSamplerLow;\n"
    "  uniform samplerCube refractionSamplerHigh;\n"
    "  #endif\n"
    "  #endif\n"
    "  #endif\n"
    "\n"
    "  #ifdef SS_THICKNESSANDMASK_TEXTURE\n"
    "  #if SS_THICKNESSANDMASK_TEXTUREDIRECTUV == 1\n"
    "  #define vThicknessUV vMainUV1\n"
    "  #elif SS_THICKNESSANDMASK_TEXTUREDIRECTUV == 2\n"
    "  #define vThicknessUV vMainUV2\n"
    "  #else\n"
    "  varying vec2 vThicknessUV;\n"
    "  #endif\n"
    "  uniform sampler2D thicknessSampler;\n"
    "  #endif\n"
    "#endif\n";

} // end of namespace BABYLON

#endif // end of BABYLON_SHADERS_SHADERS_INCLUDE_PBR_FRAGMENT_SAMPLERS_DECLARATION_FX_H