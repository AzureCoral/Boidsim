#include <cvector.hpp>
#include <cmath>

CVector::CVector() : x(0), y(0) {}
CVector::CVector(float x, float y) : x(x), y(y) {}

CVector CVector::operator+(const CVector& v) {
    return CVector(x + v.x, y + v.y);
}

CVector CVector::operator-(const CVector& v) {
    return CVector(x - v.x, y - v.y);
}

CVector CVector::operator*(const float& s) {
    return CVector(x * s, y * s);
}

CVector CVector::operator/(const float& s) {
    return CVector(x / s, y / s);
}

CVector CVector::operator+(float s) {
    return CVector(x + s, y + s);
}

CVector CVector::operator-(float s) {
    return CVector(x - s, y - s);
}

CVector& CVector::operator+=(const CVector& v) {
    x += v.x;
    y += v.y;
    return *this;
}

CVector& CVector::operator-=(const CVector& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

CVector& CVector::operator*=(const float& s) {
    x *= s;
    y *= s;
    return *this;
}

CVector& CVector::operator/=(const float& s) {
    x /= s;
    y /= s;
    return *this;
}

CVector CVector::normalized() {
    float mag = magnitude();
    return CVector(x / mag, y / mag);
}

float CVector::magnitude() {
    return sqrt(x*x, y*y);
}

float CVector::dotProduct(const CVector& v) {
    return x*v.x + y*v.y;
}

float CVector::angle(const CVector& v) {
    CVector a = normalized();
    CVector b = v.normalized();
    return acos(a.dotProduct(b));
}
