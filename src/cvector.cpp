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

CVector CVector::normalized() const {
    float mag = magnitude();
    return CVector(x / mag, y / mag);
}

float CVector::magnitude() const {
    return sqrt(x*x + y*y);
}

float CVector::distance(const CVector& v) {
    float dx = x - v.x;
    float dy = y - v.y;
    return sqrt(dx*dx + dy*dy);
}

float CVector::dotProduct(const CVector& v) {
    return x*v.x + y*v.y;
}

CVector CVector::cap(float m) {
    float curr_mag =  magnitude();
    if (curr_mag > m) {
        return normalized() * m;
    }
    return *this;
}

float CVector::angle(const CVector& v) {
    CVector a = normalized();
    CVector b = v.normalized();
    return acos(a.dotProduct(b));
}
