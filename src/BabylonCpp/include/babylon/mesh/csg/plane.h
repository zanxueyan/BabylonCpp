#ifndef BABYLON_MESH_CSG_PLANE_H
#define BABYLON_MESH_CSG_PLANE_H

#include <babylon/babylon_api.h>
#include <babylon/math/vector3.h>

namespace BABYLON {

class Vector2;

namespace CSG {

class Polygon;

/**
 * @brief Represents a plane in 3D space.
 */
class BABYLON_SHARED_EXPORT Plane {

public:
  // `BABYLON.CSG.Plane.EPSILON` is the tolerance used by `splitPolygon()` to
  // decide if a point is on the plane.
  static const float EPSILON;
  // Polygon types
  static constexpr unsigned int COPLANAR = 0;
  static constexpr unsigned int FRONT    = 1;
  static constexpr unsigned int BACK     = 2;
  static constexpr unsigned int SPANNING = 3;

public:
  Plane();
  Plane(const Vector3& normal, float w);
  Plane(const Vector3& pos, const Vector3& normal, const Vector2& uv);
  Plane(const Plane& otherPlane);
  Plane(Plane&& otherPlane);
  Plane& operator=(const Plane& otherPlane);
  Plane& operator=(Plane&& otherPlane);
  ~Plane();
  Plane clone() const;
  std::unique_ptr<Plane> cloneToNewObject() const;
  friend std::ostream& operator<<(std::ostream& os, const Plane& plane);
  std::string toString() const;

  void flip();

  /**
   * Split `polygon` by this plane if needed, then put the polygon or polygon
   * fragments in the appropriate lists. Coplanar polygons go into either
   * `coplanarFront` or `coplanarBack` depending on their orientation with
   * `respect to this plane. Polygons in front or in back of this plane go into
   * `either `front` or `back`.
   */
  void splitPolygon(const Polygon& polygon, std::vector<Polygon>& coplanarFront,
                    std::vector<Polygon>& coplanarBack,
                    std::vector<Polygon>& front, std::vector<Polygon>& back);

  static std::pair<bool, Plane> FromPoints(const Vector3& a, const Vector3& b,
                                           const Vector3& c);

public:
  Vector3 normal;
  float w;

}; // end of class Plane

} // end of namespace CSG
} // end of namespace BABYLON

#endif // end of BABYLON_MESH_CSG_PLANE_H
