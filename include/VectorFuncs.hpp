#ifndef VECTORFUNCS_HPP
#define VECTORFUNCS_HPP

#include <vector>

class Vector2
{
public:
    float x = 0.0;
    float y = 0.0;

    // Vector Class Constructor: Uses the two values to create a Vector2 type;
    // the values can be accessed trought Vector2.x and Vector2.y
    Vector2(float value1, float value2) : x(value1), y(value2) { std::vector<float> Vector2(value1, value2); };
};

#endif