#ifndef BABYLON_ANIMATIONS_ANIMATION_VALUE_H
#define BABYLON_ANIMATIONS_ANIMATION_VALUE_H

#include <babylon/babylon_global.h>
#include <babylon/core/any.h>
#include <babylon/math/color3.h>
#include <babylon/math/color4.h>
#include <babylon/math/matrix.h>
#include <babylon/math/quaternion.h>
#include <babylon/math/size.h>
#include <babylon/math/vector2.h>
#include <babylon/math/vector3.h>

namespace BABYLON {

class BABYLON_SHARED_EXPORT AnimationValue {

public:
  AnimationValue();
  AnimationValue(float value);
  AnimationValue(const Vector3& value);
  AnimationValue(const Quaternion& value);
  AnimationValue(const Matrix& value);
  AnimationValue(const Color3& value);
  AnimationValue(const Vector2& value);
  AnimationValue(const Size& value);
  AnimationValue(bool value);
  AnimationValue(int value);
  AnimationValue(const string_t& value);
  AnimationValue(const Color4& value);
  AnimationValue(const Float32Array& value);
  AnimationValue(const AnimationValue& other);
  AnimationValue(AnimationValue&& other);
  AnimationValue& operator=(const AnimationValue& other);
  AnimationValue& operator=(AnimationValue&& other);
  ~AnimationValue();

  AnimationValue subtract(const AnimationValue& fromValue);
  AnimationValue operator-(const AnimationValue& fromValue);
  AnimationValue operator!();
  AnimationValue operator[](const string_t& property);
  AnimationValue copy() const;

  operator bool() const
  {
    return dataType != -1;
  }

  any getValue() const;

public:
  int dataType;
  float floatData;
  Vector3 vector3Data;
  Quaternion quaternionData;
  Matrix matrixData;
  Color3 color3Data;
  Vector2 vector2Data;
  Size sizeData;
  bool boolData;
  int intData;
  string_t stringData;
  Color4 color4Data;
  Float32Array float32ArrayData;

}; // end of class AnimationValue

} // end of namespace BABYLON

#endif // end of BABYLON_ANIMATIONS_ANIMATION_VALUE_H
