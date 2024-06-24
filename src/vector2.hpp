#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    Vector2 addVec(const Vector2& other) const;
    Vector2 subVec(const Vector2& other) const;
    Vector2 mulVec(const Vector2& other) const;
    Vector2 divVec(const Vector2& other) const;

    Vector2 addScalar(float scalar) const;
    Vector2 subScalar(float scalar) const;
    Vector2 mulScalar(float scalar) const;
    Vector2 divScalar(float scalar) const;

    float magnitude() const;
    Vector2 normalized() const;
};

#endif // VECTOR2_HPP
