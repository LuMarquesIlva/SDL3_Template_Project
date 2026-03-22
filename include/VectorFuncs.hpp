#ifndef VECTORFUNCS_HPP
#define VECTORFUNCS_HPP

#include <vector>

class Vector2 {
public:
    std::vector<float> vector2(float, float);
    Vector2();
    Vector2(std::vector<float> vector2(float, float));
};

class Vector3 {
private:
    std::vector<float> vector3(float, float, float);
public:
    Vector3();
    Vector3(std::vector<float> vector3(float, float, float));
};

#endif