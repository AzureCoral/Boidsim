#include "vector2.hpp"
#include <cmath>


Vector2::Vector2() {
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2 Vector2::addVec(const Vector2& other) const {
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::subVec(const Vector2& other) const {
    return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::mulVec(const Vector2& other) const {
    return Vector2(this->x * other.x, this->y * other.y);
}

Vector2 Vector2::divVec(const Vector2& other) const {
    return Vector2(this->x / other.x, this->y / other.y);
}

Vector2 Vector2::addScalar(float scalar) const {
    return Vector2(this->x + scalar, this->y + scalar);
}

Vector2 Vector2::subScalar(float scalar) const {
    return Vector2(this->x - scalar, this->y - scalar);
}

Vector2 Vector2::mulScalar(float scalar) const {
    return Vector2(this->x * scalar, this->y * scalar);
}

Vector2 Vector2::divScalar(float scalar) const {
    return Vector2(this->x / scalar, this->y / scalar);
}

float Vector2::magnitude() const {
    return std::sqrt(this->x * this->x + this->y * this->y);
}

Vector2 Vector2::normalized() const {
    float mag = magnitude();

    if (mag > 0) {
        return divScalar(mag);
    }

    return Vector2();
}
