#ifndef SIM_MATH
#define SIM_MATH

#include <math.h>
#include <raymath.h>

inline double calcDistanceWithoutSqrt(const Vector3 &o1, const Vector3 &o2){
    return (o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y)+(o1.z-o2.z)*(o1.z-o2.z);
}

inline double calcDistance(const Vector3 &o1, const Vector3 &o2){
    return sqrt(calcDistanceWithoutSqrt(o1, o2));
}

inline bool isPointInsideRectangle(const Vector2 &point, const Rectangle &rec){
    return (point.x>=rec.x && point.x<=rec.x+rec.width && point.y>=rec.y && point.y<=rec.y+rec.height);
}

#endif