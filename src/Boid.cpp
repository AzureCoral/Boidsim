#include "boid.hpp"
#include "vector2.cpp"
#include <cmath>
#include <vector>

Boid::Boid(float x, float y) {
    pos = Vector2(x, y);
    vel = Vector2(0, 0);
    acc = Vector2(0, 0);
}

