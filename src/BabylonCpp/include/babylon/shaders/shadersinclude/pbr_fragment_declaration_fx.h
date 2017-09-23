﻿#ifndef BABYLON_SHADERS_SHADERS_INCLUDE_PBR_FRAGMENT_DECLARATION_FX_H
#define BABYLON_SHADERS_SHADERS_INCLUDE_PBR_FRAGMENT_DECLARATION_FX_H

namespace BABYLON {

extern const char* pbrFragmentDeclaration;

const char* pbrFragmentDeclaration
  = "uniform vec3 vReflectionColor;\n"
    "uniform vec4 vAlbedoColor;\n"
    "\n"
    "// CUSTOM CONTROLS\n"
    "uniform vec4 vLightingIntensity;\n"
    "\n"
    "uniform vec4 vReflectivityColor;\n"
    "uniform vec3 vEmissiveColor;\n"
    "\n"
    "// Samplers\n"
    "#ifdef ALBEDO\n"
    "uniform vec2 vAlbedoInfos;\n"
    "#endif\n"
    "\n"
    "#ifdef AMBIENT\n"
    "uniform vec3 vAmbientInfos;\n"
    "#endif\n"
    "\n"
    "#ifdef BUMP\n"
    "uniform vec3 vBumpInfos;\n"
    "uniform vec2 vTangentSpaceParams;\n"
    "#endif\n"
    "\n"
    "#ifdef OPACITY  \n"
    "uniform vec2 vOpacityInfos;\n"
    "#endif\n"
    "\n"
    "#ifdef EMISSIVE\n"
    "uniform vec2 vEmissiveInfos;\n"
    "#endif\n"
    "\n"
    "#ifdef LIGHTMAP\n"
    "uniform vec2 vLightmapInfos;\n"
    "#endif\n"
    "\n"
    "#ifdef REFLECTIVITY\n"
    "uniform vec3 vReflectivityInfos;\n"
    "#endif\n"
    "\n"
    "#ifdef MICROSURFACEMAP\n"
    "uniform vec2 vMicroSurfaceSamplerInfos;\n"
    "#endif\n"
    "\n"
    "// Refraction Reflection\n"
    "#if defined(REFLECTIONMAP_SPHERICAL) || defined(REFLECTIONMAP_PROJECTION) || defined(REFRACTION)\n"
    "uniform mat4 view;\n"
    "#endif\n"
    "\n"
    "// Refraction\n"
    "#ifdef REFRACTION\n"
    "  uniform vec4 vRefractionInfos;\n"
    "  uniform mat4 refractionMatrix;\n"
    "  uniform vec3 vRefractionMicrosurfaceInfos;\n"
    "#endif\n"
    "\n"
    "// Reflection\n"
    "#ifdef REFLECTION\n"
    "  uniform vec2 vReflectionInfos;\n"
    "  uniform mat4 reflectionMatrix;\n"
    "  uniform vec3 vReflectionMicrosurfaceInfos;\n"
    "#endif\n";

} // end of namespace BABYLON

#endif // end of BABYLON_SHADERS_SHADERS_INCLUDE_PBR_FRAGMENT_DECLARATION_FX_H
