#ifndef CVECTOR_HPP
#define CVECTOR_HPP

class CVector {
public:
    float x, y;

    CVector();
    CVector(float x, float y);

    CVector operator+(const CVector& v);
    CVector operator-(const CVector& v);
    CVector operator*(const float& s);
    CVector operator/(const float& s);

    CVector operator+(float s);
    CVector operator-(float s);
    
    CVector& operator+=(const CVector& v);
    CVector& operator-=(const CVector& v);
    CVector& operator*=(const float& s);
    CVector& operator/=(const float& s);

    CVector normalized() const;
    float magnitude() const;
    float distance(const CVector& v);
    CVector cap(float m);
    float dotProduct(const CVector& v);
    float angle(const CVector& v);
};

#endif // !CVECTOR_HPP
